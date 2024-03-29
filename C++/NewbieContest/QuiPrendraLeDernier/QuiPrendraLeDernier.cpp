#include <stdio.h>
#include <../../curl/include/curl/curl.h>
#include <iostream>
#include <string>
#include <QRegExp>
#include <QStringList>
#include <stdlib.h>
#include <sstream>




using namespace std;

string contents;

void displayList(QStringList list, string ds)
{
	QString str = "";
	for(int l=0;l<list.size(); l++)
	{
		str.append(list[l]);
		str.append("\r\n");
	}
	cout << ds << " : " << endl;
	cout << str.toStdString() <<endl;
	
}

size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	int numbytes = size*nmemb;
	// The data is not null-terminated, so get the last character, and replace
	// it with '\0'.
	char lastchar = *((char *) ptr + numbytes - 1);
	*((char *) ptr + numbytes - 1) = '\0';
	contents.append((char *)ptr);
	contents.append(1,lastchar);
	*((char *) ptr + numbytes - 1) = lastchar;  // Might not be necessary.
	return size*nmemb;
}

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  int written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

void curlParsing(string url, string proxy, string sessid, string cookie)
{
	contents="";
	string data ="";
	string cooky="PHPSESSID=";
	cooky+=sessid.c_str();
	cooky+="; SMFCookie89=";
	cooky+=cookie.c_str();
	cooky+="; path=/";
	
	CURLcode res;
	CURL *curl;
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		//curl_easy_setopt(curl, CURLOPT_PROXY, proxy.c_str()); 
		curl_easy_setopt(curl, CURLOPT_HEADER, 0);

		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:12.0) Gecko/20100101 Firefox/12.0");
		curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1);
		  /* no progress meter please */
		curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
		// Tell libcurl what function to call when it has data
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,handle_data);
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);//to view verbose output 
		//curl_easy_setopt(curl, CURLOPT_POST, 1);//Tell libcurl to use POST
		//curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
		curl_easy_setopt(curl, CURLOPT_AUTOREFERER, true);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
		curl_easy_setopt(curl, CURLOPT_COOKIE, cooky.c_str());
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		
	}
	/*
	if (res == 0)
		cout << "test "<< contents << endl;
	else
		cerr << "Error: " << res << endl;
	*/
}

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



int main(void)
{
	
	
	QRegExp rx("<br><br>(.*)<br><br>", Qt::CaseInsensitive );

	
	int pos = 0, numTas = 1, nbPions = 1, i=0;
	QStringList list, list2;
	stringstream pions, tas;
	string url = "www.newbiecontest.org/epreuves/prog/prog14.php";
	
	curlParsing(url, "proxy.manitougroup.com:8080", "df3c56f0c809ab44cf77e84d5ce76df2", "a%3A4%3A%7Bi%3A0%3Bs%3A4%3A%227230%22%3Bi%3A1%3Bs%3A40%3A%224901e78221d00532261ece3f85d415f55ae454e9%22%3Bi%3A2%3Bi%3A1525681197%3Bi%3A3%3Bi%3A0%3B%7D");
	//cout << contents << endl;
	pos = rx.indexIn(contents.c_str());
	list = rx.capturedTexts();
	//cout << list[1].toStdString() << endl;
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

	return 0;
}
