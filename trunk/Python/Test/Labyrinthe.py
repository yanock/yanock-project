from pprint import pprint as pp

continuer = True;

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
		directionTest = {"up":2, "right":3, "down":4, "left":1}
		newDirection = {"up":"right", "right":"down", "down":"left", "left":"up"}
	elif pdirection == "down":
		directionTest = {"up":3, "right":4, "down":1, "left":2}
		newDirection = {"up":"down", "right":"left", "down":"up", "left":"right"}	
	elif pdirection == "left":	
		directionTest = {"up":4, "right":1, "down":2, "left":3}
		newDirection = {"up":"left", "right":"up", "down":"right", "left":"down"}
		
	
	if(checkValue(position[directionTest["right"]]["y"], len(gameBoard), position[directionTest["right"]]["x"], len(gameBoard[0])) and (checkPath(pgameBoard, position, directionTest, "right", "_") or checkPath(pgameBoard, position, directionTest, "right", "1"))):
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "right")
	elif(checkValue(position[directionTest["up"]]["y"], len(gameBoard), position[directionTest["up"]]["x"], len(gameBoard[0])) and (checkPath(pgameBoard, position, directionTest, "up", "_") or checkPath(pgameBoard, position, directionTest, "up", "1"))):
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "up")
	elif(checkValue(position[directionTest["left"]]["y"], len(gameBoard), position[directionTest["left"]]["x"], len(gameBoard[0])) and (checkPath(pgameBoard, position, directionTest, "left", "_") or checkPath(pgameBoard, position, directionTest, "left", "1"))):
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "left")
	else:
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "down")
		
	return pgameBoard, pposition, pdirection

def doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, move):
	global continuer
	
	if (pgameBoard[position[directionTest[move]]["y"]][position[directionTest[move]]["x"]]) == "1":
		continuer = False
	
	pdirection = newDirection[move]
	pgameBoard[position[directionTest[move]]["y"]][position[directionTest[move]]["x"]] = "0"
	pgameBoard[pposition["y"]][pposition["x"]] = "_"
	pposition["x"] = position[directionTest[move]]["x"]
	pposition["y"] = position[directionTest[move]]["y"]
	return pgameBoard, pposition, pdirection

def checkValue(position_y, taille_tableau, position_x, taille_ligne):
	return (position_y >= 0 and position_y < taille_tableau and position_x >= 0 and position_x < taille_ligne)


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

while continuer != False:
	gameBoard, position, direction = move(gameBoard, position, direction)
	pp(gameBoard)
	raw_input("suite?")



