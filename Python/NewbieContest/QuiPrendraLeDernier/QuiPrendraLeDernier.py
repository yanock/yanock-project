import urllib2, re

from time import time 

start = time()

opener = urllib2.build_opener()
nc_url = "http://www.newbiecontest.org/epreuves/prog/prog14.php"
phpsessid = '2f70ed49070270713647390d9adf5b79'
smfcookie89 = 'a%3A4%3A%7Bi%3A0%3Bs%3A4%3A%227230%22%3Bi%3A1%3Bs%3A40%3A%224901e78221d00532261ece3f85d415f55ae454e9%22%3Bi%3A2%3Bi%3A1530170190%3Bi%3A3%3Bi%3A0%3B%7D'
cookie = 'admin=0; PHPSESSID=%s; SMFCookie89=%s' % (phpsessid, smfcookie89)
opener.addheaders.append(('Cookie', cookie))
f = opener.open(nc_url)
page = f.read()


p = re.compile('<br><br>(.*)<br><br>')
jetons =  p.findall(page)
print jetons[0].split('/')




"""

traitement(&nbPions, &numTas,  list[1]);
	while(i<1)
	{
		url = "www.newbiecontest.org/epreuves/prog/prog14.php?numtas=1&nbpions=1";
		curlParsing(url, "proxy.manitougroup.com:8080", "df3c56f0c809ab44cf77e84d5ce76df2", "a%3A4%3A%7Bi%3A0%3Bs%3A4%3A%227230%22%3Bi%3A1%3Bs%3A40%3A%224901e78221d00532261ece3f85d415f55ae454e9%22%3Bi%3A2%3Bi%3A1525681197%3Bi%3A3%3Bi%3A0%3B%7D");
		pos = rx.indexIn(contents.c_str());
		list = rx.capturedTexts();
		list2 = list[1].split(" ");
		//cout << list2[list2.length()-1].toStdString() << endl;
		i++;
	}

	pions << nbPions;
	tas << numTas;
	url = "http://www.newbiecontest.org/epreuves/prog/prog14.php?numtas=";
	url+= tas.str();
	url+="&nbpions=";
	url+=pions.str();
	
	
	
	
	void traitement(int* pion, int* tas,  QString chaine)
{
	QStringList l = chaine.split("/");
	for(int i=0;i<l.size(); i++)
	{
		//Si n%3==1, vous avez perdu ==> jouer au hasard
		//Sinon, enlever (n%3)*(-1/2) + 2 allumettes
		//http://www.assomasi.org/Sciences_Informatiques/Algorithmes/Introduction_Algorithme.html
		//http://maths.amatheurs.fr/index.php?page=nim
		//http://maths.amatheurs.fr/index.php?page=allumettes
		if(l[i].toInt()%3==
		
	}

}
"""
