//
//  main.cpp
//  Canny Edge Detector
//
//  Created by Hasan Akgün on 21/03/14.
//  Copyright (c) 2014 Hasan Akgün. All rights reserved.
//

#include <iostream>

#include "canny.h"

using namespace std;

char* name[] = {"lena", "bigben", "stpietro", "twow"};

int g_size[4] = {3, 5, 7, 9};
float g_sig[3] = {0.8, 1.0, 1.2};
int threslo[4] = {5, 20, 40, 55};
int threshi[4] = {60, 65, 80, 100};

int main()
{

	char* n = "lena";

	for (int i = 0; i < 4; i++) {
		canny cny(n);
		cny.process(g_size[i], 1.0, 40, 60);
		cny.display(false);
	}

	cout << "Press any key to start test on gaussian sigma" << endl;
	cin.get();

	for (int i = 0; i < 3; i++) {
		// cout << "gsig" << i << endl;
		canny cny(n);
		cny.process(3, g_sig[i], 40, 60);
		cny.display(false);
	}

	cout << "Press any key to start test on threshold lower bound" << endl;
	cin.get();

	for (int i = 0; i < 4; i++) {
		canny cny(n);
		cny.process(3, 1.0, threslo[i], 60);
		cny.display(false);
	}

	cout << "Press any key to start test on threshold upper bound" << endl;
	cin.get();

	for (int i = 0; i < 4; i++) {
		canny cny(n);
		cny.process(3, 1.0, 40, threshi[i]);
		cny.display(false);
	}

    return 0;
}

