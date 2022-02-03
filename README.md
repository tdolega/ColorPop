# ColorPop
##Converts a bitmap to grayscale, leaving out one color.

### C++ and Assembly implementation with benchmarks

The program converts a photo (.BMP), to grayscale, leaving out one color, which remains in its original hue. In fact, what is left is not exactly one color, but a range of colors that are in the neighborhood of that one color.

In the window you can change the settings:
- choose the color you want to keep on the image
- the choice of algorithm implementation: assembler or C++
- choose the number of threads
- choice of image to be processed: 3 test images attached or any image from disk
