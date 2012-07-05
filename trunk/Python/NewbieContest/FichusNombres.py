import urllib2
from time import time 


def callUrlLib(purl):
	start = time()
	opener = urllib2.build_opener()
	phpsessid = '2f70ed49070270713647390d9adf5b79'
	smfcookie89 = 'a%3A4%3A%7Bi%3A0%3Bs%3A4%3A%227230%22%3Bi%3A1%3Bs%3A40%3A%224901e78221d00532261ece3f85d415f55ae454e9%22%3Bi%3A2%3Bi%3A1530170190%3Bi%3A3%3Bi%3A0%3B%7D'
	cookie = 'admin=0; PHPSESSID=%s; SMFCookie89=%s' % (phpsessid, smfcookie89)
	opener.addheaders.append(('Cookie', cookie))
	f = opener.open(purl)
	print ("compteur : %d" % (start - time()))
	return f.read()



url = 'http://www.newbiecontest.org/epreuves/prog/frok-fichus_nb/anag.txt'

page = callUrlLib(url)
dictionnaire = page.split('\n')[0:-1]


