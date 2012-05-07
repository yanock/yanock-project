//============================================================================
// Name        : base.cpp
// Author      : yanock
// Version     :
// Copyright   : Your copyright notice
// Description : Fichier de base pour le c++
//============================================================================

#include <iostream>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <QList>
#include <QHash>
#include <time.h>
#include <string>
#undef main

using namespace std;

clock_t start=clock();

void displayList(QStringList list, string ds)
{
	QString str = "";
	for(int l=0;l<list.size(); l++)
		str.append(list[l]);
	cout << ds << " : " << endl;
	cout << str.toStdString() <<endl;
	
}

int main() {

	QString filename = "A-small-attempt0";
	QFile file(filename+".in");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	 return 0;
		QFile file2(filename+".out");
	if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
	 return 0;
       
	QTextStream out(&file2);
	QTextStream in(&file);


	QHash<QString, QString> hash;
	
	hash["a"] = "y";	
	
	hash["b"] = "h";
	hash["c"] = "e";
	hash["d"] = "s";
	hash["e"] = "o";
	hash["f"] = "c";
	hash["g"] = "v";
	hash["h"] = "x";
	hash["i"] = "d";
	hash["j"] = "u";
	hash["k"] = "i";
	hash["l"] = "g";
	hash["m"] = "l";
	hash["n"] = "b";
	hash["o"] = "k";
	hash["p"] = "r";
	hash["q"] = "z";
	hash["r"] = "t";
	hash["s"] = "n";
	hash["t"] = "w";
	hash["u"] = "j";
	hash["v"] = "p";
	hash["w"] = "f";
	hash["x"] = "m";
	hash["y"] = "a";
	hash["z"] = "q";
	hash[" "] = " ";

	
	int test_case = in.readLine().toInt();

	for(int i=0; i < test_case; i++)
	{
		
		QString phrase = in.readLine();
		QString phraseReturn;
		for(int j=0;j<phrase.size();j++)
		{
			QString toto(phrase[j]);
			phraseReturn.append(hash.value(toto));
		}

		cout << "Case #"<< i+1 << ": " << phraseReturn.toStdString() <<endl;
		out << "Case #"<< i+1 << ": " << phraseReturn << endl;
	}

	

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
