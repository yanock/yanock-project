//============================================================================
// Name : base.cpp
// Author : yanock
// Version :
// Copyright : Your copyright notice
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
//ifstream cin("test.in");
/*
if(!cin)
{
cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
return 0;
}
*/
string line;
getline(cin, line);
int test_case = atoi(line.c_str());
 
for(int i=0; i < test_case; i++)
{
string jewels, stone;
getline(cin, jewels);
getline(cin, stone);
int total = 0;
size_t found;
//4294967295 4294967295
for(int j=0; j < stone.length(); j++)
{
found = jewels.find_first_of(stone[j]);
if(found!=string::npos)
{
total++;
}
}
cout << total << endl;
}
 
//printf("time=%.3lfsec\n",0.001*(clock()-start));
return 0;
}
