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

void displayList(QStringList list, string ds);


void displayList(QStringList list, string ds)
{
	QString str = "";
	for(int l=0;l<list.size(); l++)
		str.append(list[l]+ " ");
	cout << ds << " : " << endl;
	cout << str.toStdString() <<endl;
	
}



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
	//for(int i=0; i < 2; i++)
	{
		QStringList list = in.readLine().split(" ");
		QStringList tableau;
		QStringList ok;
		for(int j = list[0].toInt(); j<=list[1].toInt(); j++)
			tableau.append(QString::number(j));

		int recycledPair = 0;
		for(int j = 0; j<tableau.size(); j++)
		{
			QString avant;
			avant = tableau[j];
			//cout << avant.toStdString() << endl;
			for(int k = 1; k<=avant.size()-1; k++)
			{
				QString  apres;
				apres.append(avant.mid(avant.size()-k));
				apres.append(avant.mid(0, avant.size()-k));
				
				if(avant != apres)
				{
					if(tableau.indexOf(apres)!=-1 ) //&& ok.indexOf(apres) == -1
					{
						recycledPair++;
						tableau[j] = "-1";
						ok.append(apres);
						
					}
				}
			}
			
		}
		
		
		
		cout << "Case #"<< i+1 << ": " << recycledPair << endl;
		out << "Case #"<< i+1 << ": " << recycledPair << endl;
	

	}

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
