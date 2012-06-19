import pygame
from pygame.locals import *

ecran_width = 640
ecran_height = 480
position_perso = [ecran_width/2, ecran_height/2]



pygame.init()
fenetre = pygame.display.set_mode((ecran_width, ecran_height), RESIZABLE)
fond = pygame.image.load("background.jpg").convert()
perso = pygame.image.load("perso.png").convert_alpha()
fenetre.blit(fond, (0,0))
fenetre.blit(perso, (position_perso[0], position_perso[1]))

pygame.display.flip()
pygame.key.set_repeat(400, 30)



continuer = True
while(continuer):
	for event in pygame.event.get():
		if event.type == QUIT:
			continuer = False
		if event.type == KEYDOWN:
			print event.key
			if event.key == K_RIGHT:
				position_perso[0]+=10
			if event.key == K_LEFT:
				position_perso[0]-=10
			if event.key == K_UP:
				position_perso[1]-=10
			if event.key == K_DOWN:
				position_perso[1]+=10
			if event.key == K_a:
				continuer = 0
		if event.type == MOUSEBUTTONDOWN:
			if event.button == 1:
				position_perso[0] = event.pos[0]
				position_perso[1] = event.pos[1]
		if event.type == MOUSEMOTION:
			position_perso[0] = event.pos[0]
			position_perso[1] = event.pos[1]
			
			
	fenetre.blit(fond, (0,0))	
	fenetre.blit(perso, (position_perso[0], position_perso[1]))
	pygame.display.flip()