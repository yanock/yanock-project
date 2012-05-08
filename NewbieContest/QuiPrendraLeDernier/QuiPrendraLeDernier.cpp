#include <stdio.h>
#include <../../curl/include/curl/curl.h>
#include <iostream>
#include <string>
using namespace std;

string contents;

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

CURLcode curlParsing(string url, string proxy, string sessid, string cookie)
{
	string cooky="SMFCookie89=",sess="PHPSESSID=";
	sess+=sessid.c_str();
	sess+="; path=/";
	cooky+=cookie.c_str();
	cooky+="; path=/";
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_PROXY, proxy.c_str()); 
		curl_easy_setopt(curl, CURLOPT_HEADER, 0);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 5.01; Windows NT 5.0)");
		curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1);
		  /* no progress meter please */
		curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
		// Tell libcurl what function to call when it has data
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,handle_data);
		curl_easy_setopt(curl, CURLOPT_COOKIE, sess.c_str());
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
	return res;
}

int main(void)
{
	CURLcode res = curlParsing("http://www.newbiecontest.org/epreuves/prog/prog14.php", "proxy.manitougroup.com:8080", "df3c56f0c809ab44cf77e84d5ce76df2", "a%3A4%3A%7Bi%3A0%3Bs%3A4%3A%227230%22%3Bi%3A1%3Bs%3A40%3A%224901e78221d00532261ece3f85d415f55ae454e9%22%3Bi%3A2%3Bi%3A1525681197%3Bi%3A3%3Bi%3A0%3B%7D");
	//<TAG\b[^>]*>(.*?)</TAG>
	
	
	return 0;
}