"""
import urllib2
import cookielib
import os
 
COOKIE_FILE = "cookies.lwp"
top_url = "http://www.newbiecontest.org/epreuves/prog/prog14.php"
nc_url = "http://www.newbiecontest.org/epreuves/prog/prog14.php"
username = "yanock"
password = "satriani"
user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
headers = { "User-Agent" : user_agent }
opener = None
 
# Basic authentification (Base64(user:pwd))
password_mgr = urllib2.HTTPPasswordMgrWithDefaultRealm()
# Add username and password. If we new the domain, could use it instead of None.
password_mgr.add_password(None, top_url, username, password)
auth_handler = urllib2.HTTPBasicAuthHandler(password_mgr)
 
# cookie section
cj = cookielib.LWPCookieJar()
if cj is not None:
# we successfully imported
# one of the two cookie handling modules
 
  if os.path.isfile(COOKIE_FILE):
    # if we have a cookie file already saved
    # then load the cookies into the Cookie Jar
    cj.load(COOKIE_FILE)
 
  # Now we need to get our Cookie Jar
  # installed in the opener;
  # for fetching URLs
  if cookielib is not None:
    # if we use cookielib
    # then we get the HTTPCookieProcessor
    # and install the opener in urllib2
    opener = urllib2.build_opener(auth_handler, urllib2.HTTPCookieProcessor(cj))
  else:
    opener = urllib2.build_opener(auth_handler)
 
urllib2.install_opener(opener)
f = urllib2.urlopen(nc_url)
print f.headers
print f.read()
"""

import urllib2
from time import time 

start = time()

opener = urllib2.build_opener()
nc_url = "http://www.newbiecontest.org/epreuves/prog/prog14.php"
phpsessid = '2f70ed49070270713647390d9adf5b79'
smfcookie89 = 'a%3A4%3A%7Bi%3A0%3Bs%3A4%3A%227230%22%3Bi%3A1%3Bs%3A40%3A%224901e78221d00532261ece3f85d415f55ae454e9%22%3Bi%3A2%3Bi%3A1530170190%3Bi%3A3%3Bi%3A0%3B%7D'
cookie = 'admin=0; PHPSESSID=%s; SMFCookie89=%s' % (phpsessid, smfcookie89)
opener.addheaders.append(('Cookie', cookie))
f = opener.open(nc_url)
print ("compteur : %d" % (start - time()))
print f.read()



