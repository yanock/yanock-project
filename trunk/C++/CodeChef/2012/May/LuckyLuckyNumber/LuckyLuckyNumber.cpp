//============================================================================
// Name        : base.cpp
// Author      : yanock
// Version     :
// Copyright   : Your copyright notice
// Description : Fichier de base pour le c++
//============================================================================

#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#undef main

using namespace std;
clock_t start=clock();
//CONFIG += console
int main() {

	//string const nomFichier("test.out");
    //ofstream out(nomFichier.c_str());
	ifstream cin("test.in");
	
    if(!cin)    
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
		return 0;
	}
    
	string line;
	getline(cin, line);
	int test_case = atoi(line.c_str());

	for(int i=0; i < test_case; i++)
	{
		getline(cin, line);
		int number = atoi(line.c_str());
		
		
		cout << endl;
	}

	//printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
	
}
