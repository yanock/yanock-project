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
		str.append(list[l]+ " ");
	cout << ds << " : " << endl;
	cout << str.toStdString() <<endl;
	
}

int main() {

	QString filename = "A-large-practice";
	QFile file(filename+".in");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	 return 0;
		QFile file2(filename+".out");
	if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
	 return 0;
       
	QTextStream out(&file2);
	QTextStream in(&file);


	//QHash<QString, int> hash;
	
	int test_case = in.readLine().toInt();

	for(int i=0; i < test_case; i++)
	{
		QList<QStringList> list;
		int nbRope = in.readLine().toInt();
		int f = 1, intersection = 0;
		
		for(int j=0; j < nbRope; j++)
			list.append(in.readLine().split(" "));
		
		foreach( QStringList rope, list)
		{
			for(int l=f; l<list.size(); l++)
			{
				QStringList rope2 = list[l];
				/*
				displayList(rope, "rope");
				displayList(rope2, "rope2");
				cout << endl;
				*/
				//cout << rope[0].toStdString() << " " << rope2[0].toStdString()<< endl;
				if(rope[0].toInt()>rope2[0].toInt())
				{
					//cout << "in "<< rope[1].toStdString() << " " << rope2[1].toStdString()<< endl;
					if(rope[1].toInt()<rope2[1].toInt())
						intersection++;
				}
				else
				{
					//cout << "out "<< rope[1].toStdString() << " " << rope2[1].toStdString()<< endl;
					if(rope[1].toInt()>rope2[1].toInt())
						intersection++;
				}
				
			}
			f++;
		}	
			
		
		cout << "Case #"<< i+1 << ": " << intersection <<  endl;
		out << "Case #"<< i+1 << ": " <<intersection <<  endl;
	}

	

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
