debug = True;

def move(pgameBoard, pposition, pdirection):
	position = {}
	position[1] = {"x": pposition["x"], "y": pposition["y"]-1}
	position[2] = {"x": pposition["x"]+1, "y": pposition["y"]}
	position[3] = {"x": pposition["x"], "y": pposition["y"]+1}
	position[4] = {"x": pposition["x"]-1, "y": pposition["y"]}
	
	if pdirection == "up":
		directionTest = {"up":1, "right":2, "down":3, "left":4}
		newDirection = {"up":"up", "right":"right", "down":"down", "left":"left"}
	elif pdirection == "right":
		if debug: print "coucou"
		directionTest = {"up":2, "right":3, "down":4, "left":1}
		newDirection = {"up":"right", "right":"down", "down":"left", "left":"up"}
	elif pdirection == "down":
		directionTest = {"up":3, "right":4, "down":1, "left":2}
		newDirection = {"up":"down", "right":"left", "down":"up", "left":"right"}	
	elif pdirection == "left":	
		directionTest = {"up":4, "right":1, "down":2, "left":3}
		newDirection = {"up":"left", "right":"up", "down":"right", "left":"down"}
		
	
	if(checkValue(position[directionTest["right"]]["y"], len(gameBoard), position[directionTest["right"]]["x"], len(gameBoard[0])) and checkPath(pgameBoard, position, directionTest, "right", "_")):
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "right")
		if debug: print "1"
	elif(checkValue(position[directionTest["up"]]["y"], len(gameBoard), position[directionTest["up"]]["x"], len(gameBoard[0])) and checkPath(pgameBoard, position, directionTest, "up", "_")):
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "up")
		if debug: print "2"
	elif(checkValue(position[directionTest["left"]]["y"], len(gameBoard), position[directionTest["left"]]["x"], len(gameBoard[0])) and checkPath(pgameBoard, position, directionTest, "left", "_")):
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "left")
		if debug: print "3"
	else:
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "down")
		if debug: print "4"
		
	return pgameBoard, pposition, pdirection

def doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, move):
	
	pdirection = newDirection[move]
	pgameBoard[position[directionTest[move]]["y"]][position[directionTest[move]]["x"]] = "0"
	pgameBoard[pposition["y"]][pposition["x"]] = "_"
	pposition["x"] = position[directionTest[move]]["x"]
	pposition["y"] = position[directionTest[move]]["y"]
	
	return pgameBoard, pposition, pdirection

def checkValue(value1, value2, compar1, compar2):
	return (value1 >= 0 and value1 < compar1 and value2 >= 0 and value2 < compar2)


def checkPath(pgameBoard, position, directionTest, case, compar):
	return (pgameBoard[position[directionTest[case]]["y"]][position[directionTest[case]]["x"]] == compar)

character = "0"
goal = "1"
position = {"x": 0, "y": 0}
gameBoard = []
direction = "right"
i = 0
with open("exemple.txt", "r") as file:
	for line in file:
		j = 0
		gameBoard.append([])
		for char in line:
			if char != "\n":
				gameBoard[i].append(char)
			if  char == "0":
				position["x"] = j
				position["y"] = i
			j+=1
		i+=1
		
if debug: print position


for line in gameBoard:
	print line

gameBoard, position, direction = move(gameBoard, position, direction)





