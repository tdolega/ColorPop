.code

;; stale wyznaczania szarosci => (short)(<znana stala> * <SHORT_MAX> + <zaokraglenie>)
;; wartosc w little endian zaladowana 16 razy
; 0.2989 * 32768.0 + 0.5
coefR DW 19235, 19235, 19235, 19235, 19235, 19235, 19235, 19235, 19235, 19235, 19235, 19235, 19235, 19235, 19235, 19235
; 0.5870 * 32768.0 + 0.5
coefG DW  9794,  9794,  9794,  9794,  9794,  9794,  9794,  9794,  9794,  9794,  9794,  9794,  9794,  9794,  9794,  9794
; 0.1140 * 32768.0 + 0.5
coefB DW  3736,  3736,  3736,  3736,  3736,  3736,  3736,  3736,  3736,  3736,  3736,  3736,  3736,  3736,  3736,  3736

inR = 0
outR = 0
inG = 32
outG = 32
inB = 64
outB = 64

; zmienne wejsciowe (struct tagRGB)
cutoffLow = 240
cutoffHigh = 248
asmImp proc

; zapis stosu do przywrocenia na koncu procedury
mov rax, rsp
mov QWORD PTR [rax+8], rbx
push rbp
sub rsp, 192
lea rbp, QWORD PTR [rsp+32]
and rbp, -32

; oblicz adres pierwszego pixela
lea eax, DWORD PTR [r9+r9*2]
mov rbx, rdx
sub r8d, eax
movsxd  r11, r8d

; ustaw dlugosc petli na 16..
mov edx, 16
; ..lub ("dlugosc do konca linii" + 1) jezeli jest mniejsza niz 15
cmp r9d, 15
lea eax, DWORD PTR [r9+1]
cmovg eax, edx
xor r9d, r9d
movsxd r10, eax
mov edx, r9d

;; petla odczytujaca
add rcx, r11
petlaOdczytu:
; odczytaj B
movzx eax, BYTE PTR [rcx]
lea rcx, QWORD PTR [rcx+3]
mov WORD PTR inB[rbp+rdx*2], ax
; odczytaj G
movzx eax, BYTE PTR [rcx-2]
mov WORD PTR inG[rbp+rdx*2], ax
; odczytaj R
movzx eax, BYTE PTR [rcx-1]
mov WORD PTR inR[rbp+rdx*2], ax

inc rdx
; porownanie z koncem petli
cmp rdx, r10
jl SHORT petlaOdczytu

;;; obliczanie maski szarosci
; zaladowanie wartosci
mov r8,  QWORD PTR cutoffLow[rsp]
mov rdx, QWORD PTR cutoffHigh[rsp]
vmovdqu ymm9, YMMWORD PTR inR[rbp]
vmovdqu ymm7, YMMWORD PTR inG[rbp]
vmovdqu ymm8, YMMWORD PTR inB[rbp]

;; oblicz maske 'R
; zaladuj dolny limit
movzx eax, BYTE PTR [r8+2]
vmovd xmm0, eax
; ustaw dolny limit na wszytskich pozycjach
vpbroadcastw ymm0, xmm0
; stworz maske ponizej limitu
vpcmpgtw ymm1, ymm0, ymm9
; zaladuj gorny limit
movzx eax, BYTE PTR [rdx+2]
vmovd xmm0, eax
; ustaw gorny limit na wszytskich pozycjach
vpbroadcastw ymm0, xmm0
; stworz maske powyzej limitu
vpcmpgtw ymm0, ymm9, ymm0
; zsumuj maski
vpor ymm3, ymm0, ymm1

;; oblicz maske 'G, wszystko analogicznie jak wyzej
movzx eax, BYTE PTR [r8+1]
vmovd xmm0, eax
vpbroadcastw ymm0, xmm0
vpcmpgtw ymm1, ymm0, ymm7
movzx eax, BYTE PTR [rdx+1]
vmovd xmm0, eax
vpbroadcastw ymm0, xmm0
vpcmpgtw ymm0, ymm7, ymm0
vpor ymm2, ymm0, ymm1

;; oblicz maske 'B, wszystko analogicznie jak wyzej
movzx eax, BYTE PTR [r8]
vmovd xmm0, eax
vpbroadcastw ymm0, xmm0
vpcmpgtw ymm1, ymm0, ymm8
movzx eax, BYTE PTR [rdx]
vmovd xmm0, eax
vpbroadcastw ymm0, xmm0
vpcmpgtw ymm0, ymm8, ymm0
vpor ymm1, ymm0, ymm1

; polacz maski trzech kolorow
vpor ymm2, ymm1, ymm2
vpor ymm6, ymm2, ymm3

;; oblicz kolory w skali szarosci
; pomnozenie przez 64
vpsllw ymm0, ymm8, 6
; operacja round(B * coefB / 2^15)
vpmulhrsw ymm5, ymm0, YMMWORD PTR coefB
; G jak wyzej
vpsllw ymm1, ymm9, 6
vpmulhrsw ymm4, ymm1, YMMWORD PTR coefG
; R jak wyzej
vpsllw ymm0, ymm7, 6
vpmulhrsw ymm1, ymm0, YMMWORD PTR coefR
; dodaj wszystkie wyniki
vpaddw ymm2, ymm1, ymm4
vpaddw ymm3, ymm2, ymm5
; podziel przez 64
vpsrlw ymm0, ymm3, 6

; zostaw skale szarosci tylko gdzie wskazuje maska szarosci
vpand ymm4, ymm0, ymm6

;; wykonywane jest 'not and' na masce szarosci i kolorach
;; aby zostawic poszczegolny kolor tylko tam gdzie ma byc
;; po czym wyniki kolorow i szarosci sa laczone poprzez 'or'
; dodaj kolor R
; kolor R odwrotnie niz wyzej, jest zostawiany tylko w granicach
vpandn ymm1, ymm6, ymm9
; obie wartosci sa laczone
vpor ymm0, ymm1, ymm4
; i zapisywane do pamieci
vmovdqu YMMWORD PTR outR[rbp], ymm0

; dodaj kolor G
vpandn ymm2, ymm6, ymm7
vpor ymm1, ymm2, ymm4
vmovdqu YMMWORD PTR outG[rbp], ymm1

; dodaj kolor B
vpandn ymm0, ymm6, ymm8
vpor ymm2, ymm0, ymm4
vmovdqu YMMWORD PTR outB[rbp], ymm2

;; petla zapisujaca
; adres pierwszego pixela
lea rax, QWORD PTR [r11+rbx]
petlaZapisu:
; zapisz B
movzx ecx, BYTE PTR outB[rbp+r9*2]
mov BYTE PTR [rax], cl
; zapisz G
lea rax, QWORD PTR [rax+3]
movzx ecx, BYTE PTR outG[rbp+r9*2]
mov BYTE PTR [rax-2], cl
; zapisz R
movzx ecx, BYTE PTR outR[rbp+r9*2]
mov BYTE PTR [rax-1], cl

inc r9
; porownanie z koncem petli
cmp r9, r10
jl SHORT petlaZapisu

; przygotowanie powrotu z procedury
lea r11, QWORD PTR [rsp+192]
mov rbx, QWORD PTR [r11+16]
mov rsp, r11
pop rbp
ret 0

asmImp endp
end