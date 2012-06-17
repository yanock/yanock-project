#!/usr/bin/python
# -*- coding: utf-8 -*-

import MySQLdb as mdb
import sys



for i in range(10000):
	con = None
	try:
		print i
		con = mdb.connect('localhost', 'root', 'test', 'test');
		
		cur = con.cursor()
		break
		cur.execute("SELECT VERSION()")
		
		data = cur.fetchone()
		
		print "Database version : %s " % data
		
	except mdb.Error, e:
	  
		print "Error %d: %s" % (e.args[0],e.args[1])
		#sys.exit(1)
		
	finally:    
			
		if con:    
			con.close()
