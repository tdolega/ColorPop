# ColorPop
## Converts a bitmap to grayscale, leaving out one color.
Visual Studio solution consists of 3 projects: GUI and 2 DLL implementations: C++ and Assembly **with AVX2**

In the window you can change the settings:
- choose image to be processed: 3 test images attached or any image from disk
- choose the color you want to keep on the image
- choose algorithm implementation: C++ or assembler
- choose the number of threads

![image](https://user-images.githubusercontent.com/20531317/152339309-ca1d7e11-4341-449a-9492-df76ee1e94eb.png)

Benchmark on Ryzen 9 3900X and Windows 11 for 3000x3000 file
![image](https://user-images.githubusercontent.com/20531317/152339410-ff53da9b-e104-459d-9426-78ccce428e10.png)
