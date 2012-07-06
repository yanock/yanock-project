import cookielib
import os
import urllib
import urllib2

class NewbieContest(object):
	def __init__(self, login, password, cookie_jar = 'newbiecontest.cookies', url = 'http://www.newbiecontest.org/forums/index.php?action=login2'):
		self.login = login
		self.password = password
		self.cookie_jar = cookie_jar
		self.url = url
		
		self.cj = cookielib.MozillaCookieJar(cookie_jar)
	
	def _get_cookie_jar(self):
		self.cj.load()
		return urllib2.build_opener(urllib2.HTTPCookieProcessor(self.cj))
	
	def authenticate(self):
		opener = self._get_cookie_jar()

		opener.open(url, urllib.urlencode({'user' : login, 'passwrd' : password}))
		#opener.open(url, urllib.urlencode({'user' : login, 'passwrd' : password})) #2eme appel utile ?

		self.cj.save()
	
	def get(self, url):
		opener = self._get_cookie_jar()
		response = opener.open(url)
		return response.read()

nb = NewbieContest('user', 'passwrd')
#nb.authenticate() #pour creer le cookie

from pprint import pprint as pp
import math
import re

src = nb.get('http://www.newbiecontest.org/epreuves/prog/prog5.php')
pp(src)

l = src.split('<br />')
txt = l[0].strip().split(' ')[-1].strip('\'')
key = int(l[1].strip().split(' ')[-1].strip('\''))
pp((txt, key))

res = ''
for c in txt:
	res += chr(ord('a') + (ord(c) - ord('a') - key) % 26)
pp(res)

pp(nb.get('http://www.newbiecontest.org/epreuves/prog/verifpr5.php?solution=%s' % res))
