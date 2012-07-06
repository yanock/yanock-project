"""
import urllib2, re
from time import clock, time

proxy_handler = urllib2.ProxyHandler({'http': 'http://proxy.manitougroup.com:8080'})

user_agent = 'Mozilla/5.0 (Windows NT 5.1; rv:15.0) Gecko/20120703 Firefox/15.0a2'


start = time()
opener = urllib2.build_opener(proxy_handler)

print ("build opener : %d" % (time() - start))

nc_url = "http://www.newbiecontest.org/index.php?page=epreuve&no=147"
nc_url2 = "http://www.newbiecontest.org/index.php?page=epreuve&no=144"
phpsessid = '2f70ed49070270713647390d9adf5b79'
smfcookie89 = 'a%3A4%3A%7Bi%3A0%3Bs%3A4%3A%227230%22%3Bi%3A1%3Bs%3A40%3A%224901e78221d00532261ece3f85d415f55ae454e9%22%3Bi%3A2%3Bi%3A1530170190%3Bi%3A3%3Bi%3A0%3B%7D'
cookie = 'admin=0; PHPSESSID=%s; SMFCookie89=%s' % (phpsessid, smfcookie89)

start = time()

#opener.addheaders.append(('Cookie', cookie))

opener.addheaders = [('User-agent', user_agent)]
print ("add header : %d" % (time() - start))

start = time()
f = opener.open(nc_url)
print ("open 1 : %d" % (time() - start))

start = time()
f2 = opener.open(nc_url2)
print ("open 2 : %d" % (time() - start))

"""

import urllib2
opener = urllib2.build_opener()
opener.addheaders = [('User-agent', 'Mozilla/5.0')]
opener.open('http://www.plop.org/')