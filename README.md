# ColorPop
## Converts a bitmap to grayscale, leaving out one color.

The program converts a photo (.BMP), to grayscale, leaving out one color, which remains in its original hue. In fact, what is left is not exactly one color, but a range of colors that are in the neighborhood of that one color.

#### C++ and Assembly implementation with benchmarks

In the window you can change the settings:
- choose the color you want to keep on the image
- the choice of algorithm implementation: assembler or C++
- choose the number of threads
- choice of image to be processed: 3 test images attached or any image from disk

![image](https://user-images.githubusercontent.com/20531317/152339309-ca1d7e11-4341-449a-9492-df76ee1e94eb.png)

Benchmark on Ryzen 9 3900X and Windows 11 for 3000x3000 file
![image](https://user-images.githubusercontent.com/20531317/152339410-ff53da9b-e104-459d-9426-78ccce428e10.png)
