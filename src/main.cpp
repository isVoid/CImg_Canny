//
//  main.cpp
//  Canny Edge Detector Lab
//
//	Created by Michael Wang, 10/03/17
//  Software is released under GNU GPL-2.0
//	

#include <iostream>
#define _USE_MATH_DEFINES
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include "canny.h"

using namespace std;

template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<std::string> split(const string &s, char delim) {
    vector<std::string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

bool run = true;

int gs = 3, g_sig = 1, threslo = 20,  threshi = 40;

void processInput(string c) {

	if (c.compare("q") == 0) {
		cout << "Quitting..." << endl;
		run = false;
	}
	else if (c.compare("lena") != 0 && c.compare("bigben") != 0 && c.compare("stpietro") != 0 && c.compare("twows") != 0) {
		cout << "Invalid path!" << endl;
	}
	else {

		cout << "Loading: " << c << endl;
	    canny cny(c.c_str());

    	cout << "#\tType in \"gsize\" to set size of Gaussian Filter" << endl;
    	cout << "#\tType in \"gsig\" to set Gaussian sigma value" << endl;
    	cout << "#\tType in \"tlo\" to set lower bound of thresholding" << endl;
    	cout << "#\tType in \"thi\" to set upper bound of thresholding" << endl;
    	cout << "#\tTo set multiple values, separate these commands with space" << endl;
    	cout << "#\tType \"go\" to process with default value"<< endl;

    	string cc;
    	cin >> cc;

		vector<string> cmds = split(cc, ' '); 
		for (int i = 0; i < cmds.size(); i++) {

			string cmd = cmds[i];

			cin.clear();

			if (cmd.compare("gsize") == 0) {
				cout << "Please type in gaussian filter size (odd number), default is 3: ";
				cin >> gs;
			}
			else if (cmd.compare("gsig") == 0) {
				cout << "Please type in gaussian sigma value, default is 1: ";
				cin >> g_sig;
			}
			else if (cmd.compare("tlo") == 0) {
				cout << "Please type in lower bound of thresholding, default is 20: ";
				cin >> threslo;
			}
			else if (cmd.compare("thi") == 0) {
				cout << "Please type in upper bound of thresholding, default is 40: ";
				cin >> threshi;
			}
		}

		cout << "Processing image and output: " << endl;
		cny.process(gs, g_sig, threslo, threshi);
		cout << "Done processing" << endl;
		cny.displayandsave(true);
	}

}

int main()
{
    string command;

    while(run) {
    	cin.clear();

    	cout << endl;
    	cout << "#\tCanny Algorithm Lab" << endl;
    	cout << "#\tChoose an image to process: lena, bigben, stpietro, twows" << endl;
    	cout << "#\ttype \"q\" to quit program." << endl;

    	cin >> command;

    	processInput(command);
    }

    return 0;
}

