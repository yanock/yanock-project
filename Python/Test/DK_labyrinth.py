import pygame
from pygame.locals import *

sprite_width = 30
sprite_height = 30
tab_width = len(gameBoard[0])
tab_height = len(gameBoard)

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

