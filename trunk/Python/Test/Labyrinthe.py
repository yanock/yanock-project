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

	
	if(pgameBoard[position[directionTest["right"]]["x"]][position[directionTest["right"]]["y"]] == "_"):
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "right")
	elif(pgameBoard[position[directionTest["up"]]["x"]][position[directionTest["up"]]["y"]] == "_"):
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "up")
	elif(pgameBoard[position[directionTest["left"]]["x"]][position[directionTest["left"]]["y"]] == "_"):
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "left")
	else:
		pgameBoard, pposition, pdirection = doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, "down")
	
	return pgameBoard, pposition, pdirection

def doMove(pgameBoard, pposition, pdirection, directionTest, newDirection, position, move):
	pdirection = newDirection[move]
	pgameBoard[position[directionTest[move]]["x"]][position[directionTest[move]]["y"]] == "0"
	pgameBoard[pposition["x"]][pposition["y"]] == "_"
	pposition["x"] = position[directionTest[move]]["x"]
	pposition["y"] = position[directionTest[move]]["y"]
	return pgameBoard, pposition, pdirection



character = "0"
goal = "1"
position = {"x": 0, "y": 0}
gameBoard = {}
direction = "right"
i = 0
with open("exemple.txt", "r") as file:
	for line in file:
		gameBoard[i] = line
		find = gameBoard[i].find(character)
		if  find != -1:
			position["x"] = find
			position["y"] = i
		i+=1
		
gameBoard, position, direction = move(gameBoard, position, direction)

for i in range(len(gameBoard)):
	print gameBoard[i]		




