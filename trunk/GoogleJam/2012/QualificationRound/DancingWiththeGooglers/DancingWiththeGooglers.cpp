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

	QString filename = "B-large";
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
		int googlers=0, suprising=0, max=0, ok = 0;
		QStringList list = in.readLine().split(" ");
		googlers = list[0].toInt();
		suprising = list[1].toInt();
		max = list[2].toInt();
		
		for(int j=3; j<list.size(); j++)
		{
				int score = list[j].toInt();
				
				cout << "valeur " << (max+(max-1)*2)<< " " <<(max+(max+1)*2) << endl;
				cout << "valeur " << (max+(max-2)*2)<< " " << (max+(max+2)*2) << endl;
				cout << "score " << score << endl;
				
				if (score > 0 || (score == 0 && max == 0))
				{
					if(score>=(max+(max-1)*2))
					{
						ok++;
					}
					
					//else if(score>=(max+(max-2)*2) && suprising>0 )
					else if(score>=(max+(max-2)*2) && suprising>0 )
					{
						cout << "surprising" << endl;
						ok++;
						suprising--;
					}
				}
		}
		
		
		cout << "Case #"<< i+1 << ": " << ok << endl;
		cout << endl;
		out << "Case #"<< i+1 << ": " <<  ok << endl;
	}

	

	printf("time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
