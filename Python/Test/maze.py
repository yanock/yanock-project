#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pprint import pprint as pp

class Maze:
	def __init__(self, map):
		self.map = map
		
		for j in xrange(len(map)):
			row = map[j]
			
			if 2 in row:
				self.start = {'x': row.index(2), 'y': j}
			
			if 3 in row:
				self.stop = {'x': row.index(3), 'y': j}
	
	def __repr__(self):
		return "start: %r; stop: %r" % (self.start, self.stop)
	
	def wall(self, i, j, where):
		if where not in ('↑', '←', '↓', '→'):
			raise Exception('I don\'t understand "wall %r"!' % where)
		
		return not ((where == '↑' and j > 0 and self.map[j - 1][i] != 1) or
			(where == '←' and i > 0 and self.map[j][i - 1] != 1) or
			(where == '↓' and j < len(map) - 1 and self.map[j + 1][i] != 1) or
			(where == '→' and i < len(map[0]) - 1 and self.map[j][i + 1] != 1))

class LostGuy:
	map = {
		'↑': {'↑': '↑', '←': '←', '↓': '↓', '→': '→'},
		'←': {'↑': '←', '←': '↓', '↓': '→', '→': '↑'},
		'↓': {'↑': '↓', '←': '→', '↓': '↑', '→': '←'},
		'→': {'↑': '→', '←': '↑', '↓': '←', '→': '↓'},
	}
	
	def __init__(self, maze):
		self.maze = maze
		self.x = maze.start['x']
		self.y = maze.start['y']
		self.direction = '↑'
	
	def __repr__(self):
		return "x: %r; y: %r; finish: %r; direction: %s; wall: %r" % (
			self.x,
			self.y,
			self.finish(),
			self.direction,
			[self.wall(where)
				for where
				in ('↑', '←', '↓', '→')
			]
		)
	
	def translate_direction(self, where):
		return self.map[self.direction][where]
	
	def wall(self, where):
		return self.maze.wall(self.x, self.y, self.translate_direction(where))
	
	def turn(self, where):
		if where not in ('←', '→'):
			raise Exception('I don\'t understand "turn %r"!' % where)
		
		self.direction = self.translate_direction(where)
		
		return True
	
	def move(self, where):
		if where not in ('↑', '↓'):
			raise Exception('I don\'t understand "move %r"!' % where)
		
		if self.wall(where):
			return False
		
		dir = self.translate_direction(where)
		
		if dir == '↑':
			self.y -= 1
		elif dir == '←':
			self.x -= 1
		elif dir == '↓':
			self.y += 1
		elif dir == '→':
			self.x += 1
		
		return True
	
	def finish(self):
		return self.x == self.maze.stop['x'] and self.y == self.maze.stop['y']

if __name__ == '__main__':
	map = [
		[1, 1, 1, 1, 1, 1, 1, 1],
		[1, 0, 0, 1, 0, 1, 3, 1],
		[1, 0, 0, 1, 0, 0, 0, 1],
		[1, 0, 1, 1, 0, 1, 1, 1],
		[1, 0, 0, 0, 0, 0, 0, 1],
		[1, 1, 0, 1, 1, 1, 0, 1],
		[1, 2, 0, 0, 0, 1, 0, 1],
		[1, 1, 1, 1, 1, 1, 1, 1]
	]
	
	maze = Maze(map)
	guy = LostGuy(maze)
	
	pp(maze)
	pp(guy)
	print('')
	
	while not guy.finish():
		while not guy.wall('↑'):
			print('move ↑')
			guy.move('↑')
			pp(guy)
			
			if not guy.wall('←'):
				print('turn ←')
				guy.turn('←')
				pp(guy)
		
		print('turn →')
		guy.turn('→')
		pp(guy)
