import urllib, urllib2, cookielib

proxy = "http://"":""@proxy.manitougroup.com:8080"
urlprx = UrllibProxy(proxy)

urlprx.urlretrieve("http://www.developer.nokia.com/Community/Wiki/","wikinokiadeveloper.html")
opener = urllib.FancyURLopener(proxies=proxies)
r = opener.open("http://www.python.org/")
print r.read()

"""
kuhkuhkuhukh

cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
login_data = urllib.urlencode({'username' : username, 'j_password' : password})
opener.open('http://www.example.com/login.php', login_data)
resp = opener.open('http://www.example.com/hiddenpage.php')
print resp.read()
"""