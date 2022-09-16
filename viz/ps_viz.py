import pygame
import random
import subprocess

ps_program = '/Users/abackman/workspace/hive_projects/push_swap/push_swap'
background = (234, 212, 252)
width = 400
height = 450

def	init():
	pygame.init()
	screen = pygame.display.set_mode((width, height))
	screen.fill(background)
	pygame.display.set_caption("Push_swap visualizer")

def	set_list(self, lst):
	self.lst = lst
	self.mini = min(lst)
	self.maxi = max(lst)

def	generate(min: int, max: int, size: int):
	if size < 1:
		return 0
	lst = list(range(min, max))
	shuffle(lst)
	return lst

def	main():
	run = True
	clock = pygame.time.Clock()

	init()
	while run:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				run = False
	pygame.quit()

main()