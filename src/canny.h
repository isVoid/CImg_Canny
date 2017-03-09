//
//  canny.h
//  Canny Edge Detector
//
//  Created by Hasan Akgün on 21/03/14.
//  Copyright (c) 2014 Hasan Akgün. All rights reserved.
//

#ifndef _CANNY_
#define _CANNY_
#include <string>
#include <vector>
#include "CImg.h"

using namespace cimg_library;
using namespace std;

class canny {
private:

    CImg<unsigned char> img; //Original Image
    CImg<unsigned char> grayscaled; // Grayscale
    CImg<unsigned char> gFiltered; // Gradient
    CImg<unsigned char> sFiltered; //Sobel Filtered
    CImg<float> angles; //Angle Map
    CImg<unsigned char> nonMaxSupped; // Non-maxima supp.
    CImg<unsigned char> thres; //Double threshold and final

    CImgDisplay img_disp;
    CImgDisplay gray_disp;
    CImgDisplay fil_img_disp;

    char _name[256];
    int _gfs, _thres_lo, _thres_hi;
    double _g_sig;

public:

    canny(const char* name); //Constructor

    CImg<unsigned char> process(int gfs, double g_sig, int thres_lo, int thres_hi);

	void toGrayScale();
	vector< vector<double> > createFilter(int row, int col, double sigma_in); //Creates a gaussian filter
	void useFilter(CImg<unsigned char>, vector< vector<double> >); //Use some filter
    void sobel(); //Sobel filtering
    void nonMaxSupp(); //Non-maxima supp.
    void threshold(CImg<unsigned char>, int, int); //Double threshold and finalize picture

    void display(bool on);

};

#endif
