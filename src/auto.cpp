//
//  auto.cpp
//  Automated Canny algorithm parameter lab
//
//	Created by Michael Wang, 10/03/17
//  Software is released under GNU GPL-2.0
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

	for (int j = 0; j < 4; j++) {

		char* n = name[j];
		cout << "On image " << n << endl;

		for (int i = 0; i < 4; i++) {
			canny cny(n);
			cny.process(g_size[i], 1.0, 40, 60);
			cny.displayandsave(false);
		}

		cout << "Press any key to start test on gaussian sigma" << endl;
		cin.get();

		for (int i = 0; i < 3; i++) {
			// cout << "gsig" << i << endl;
			canny cny(n);
			cny.process(3, g_sig[i], 40, 60);
			cny.displayandsave(false);
		}

		cout << "Press any key to start test on threshold lower bound" << endl;
		cin.get();

		for (int i = 0; i < 4; i++) {
			canny cny(n);
			cny.process(3, 1.0, threslo[i], 60);
			cny.displayandsave(false);
		}

		cout << "Press any key to start test on threshold upper bound" << endl;
		cin.get();

		for (int i = 0; i < 4; i++) {
			canny cny(n);
			cny.process(3, 1.0, 40, threshi[i]);
			cny.displayandsave(false);
		}

	}


    return 0;
}

