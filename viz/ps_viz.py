import pygame as pg
import random
import subprocess

ps_program = '/Users/abackman/workspace/hive_projects/push_swap/push_swap'
background = (42, 72, 88)
textcolor = (142, 72, 88)
size_inputbox = pg.Rect(100, 10, 140, 32)
color_inactive = pg.Color('lightskyblue3')
color_active = pg.Color('dodgerblue2')
width = 600
height = 700
solvespeed = 100
screensize = (width,height)

def	init():
	pg.init()
	screen = pg.display.set_mode((width, height))
	screen.fill(background)
	pg.display.set_caption("Push_swap visualizer")
	return screen

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
	clock = pg.time.Clock()
	stacksize = ''
	sizenumber = 0
	active = False
	color = color_inactive
	screen = init()

	font = pg.font.Font(None, 32)
	sizetext = font.render('size:', True, textcolor, background)
	sizetextRect = sizetext.get_rect()
	sizetextRect.center = (50, 26)

	bg = pg.Surface(screensize)
	screen.blit(bg, (0, 0))
	pg.draw.rect(bg, background, (0, 0, 600, 700))

	stack = generate(-2147483648, 2147483647, 10)
	print(stack)
	while run:
		for event in pg.event.get():
			if event.type == pg.QUIT:
				run = False
			elif event.type == pg.MOUSEBUTTONDOWN:
				if size_inputbox.collidepoint(event.pos):
					active = not active
				else:
					active = False
				color = color_active if active else color_inactive
			if event.type == pg.KEYDOWN:
				if active:
					if event.key == pg.K_RETURN:
						print(stacksize)
						stacksize = ''
					elif event.key == pg.K_BACKSPACE:
						stacksize = stacksize[:-1]
					elif event.key == pg.K_UP:
						solvespeed *= 1.5
					elif event.key == pg.K_DOWN:
						solvespeed /= 1.5
					else:
						stacksize += event.unicode
				if event.key == pg.K_ESCAPE:
					run = False
				if (sizenumber < 0):
					sizenumber = 0
				elif (sizenumber > 10000):
					sizenumber = 10000
		screen.blit(bg, (0, 0))
		txt_surface = font.render(stacksize, True, color)
		width = max(200, txt_surface.get_width()+10)
		size_inputbox.w = width
		screen.blit(sizetext, sizetextRect)
		screen.blit(txt_surface, (size_inputbox.x+5, size_inputbox.y+5))
		pg.draw.rect(screen, color, size_inputbox, 2)
		pg.display.flip()
	pg.quit()

main()