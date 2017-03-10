#CImg_Canny

This is a CImg wrapped canny algorithm for edge detection. 

Code is modified from Hasan's orginal code using OpenCV library.
https://github.com/hasanakg/Canny-Edge-Detector

There are 2 versions of this software, one with interactive command line interface that you can play around with Canny's parameter. The other generates images from a set of parameters.

I'm rather new to Makefile. Please feel free to update the makefile to make compiling more elegent and quiet.

To build both: `make all`

To build interactive version: `make Canny`

To build auto version: `make auto_canny`