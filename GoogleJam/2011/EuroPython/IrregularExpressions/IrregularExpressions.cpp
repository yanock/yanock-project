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
//CONFIG += console
int main() {

	QString filename = "test";
	QFile file(filename+".in");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	 return 0;
		QFile file2(filename+".out");
	if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
	 return 0;
       
	QTextStream out(&file2);
	QTextStream in(&file);

	QHash<QString, int> hash;

	int test_case = in.readLine().toInt();


	for(int i=0; i < test_case; i++)
	{
		
		QString spell = in.readLine();
		QString output = "Nothing.";
		//cout<< "spell : " << spell.toStdString() << endl;
		
		QRegExp rx("[^aeiou]*[aeiou][^aeiou]*");

		 int pos = 0;

		 while ((pos = rx.indexIn(spell, pos)) != -1) {
			 pos += rx.matchedLength();
			 QRegExp reg(rx.cap(0));
			 QRegExp no("[aeiou][^aeiou]*[aeiou][^aeiou]*"+rx.cap(0));
			 if (reg.indexIn(spell, pos) != -1 && no.indexIn(spell, pos) == -1)
			{
				 output = "Spell!";
				 break;
			}
		 }




		cout << "Case #"<< i+1 << ": " << output.toStdString()<<  endl;
		out << "Case #"<< i+1 << ": " << output <<endl;

		
		
	}

	

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
