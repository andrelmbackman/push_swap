import pygame as pg
import random
import subprocess
from moves import *
import sys
sys.path.insert(0, '..')

stacksize = int(300)
stackmin = int(-55555)
stackmax = int(55555)
stackrange = int((stackmax - stackmin))
n_colours = int(13)
n_range = int(stackrange / n_colours)
colours = [
	pg.Color(250, 250, 110),
	pg.Color(209, 242, 114),
	pg.Color(170, 232, 122),
	pg.Color(132, 220, 132),
	pg.Color(95, 207, 141),
	pg.Color(55, 194, 149),
	pg.Color(0, 179, 154),
	pg.Color(0, 164, 157),
	pg.Color(0, 149, 156),
	pg.Color(0, 133, 151),
	pg.Color(0, 118, 142),
	pg.Color(14, 102, 130),
	pg.Color(36, 87, 115),
]

ps_program = '/Users/abackman/workspace/hive_projects/push_swap/push_swap'
background = (25, 25, 25)
textcolor = (36, 87, 115)
size_inputbox = pg.Rect(100, 10, 140, 32)
color_inactive = pg.Color('lightskyblue3')
color_active = pg.Color('dodgerblue2')
width = 600
height = 700
solvespeed = 100
screensize = (width,height)

def	get_moves(ints):
	data = subprocess.Popen([ps_program, ints], stdout=subprocess.PIPE)
	output = data.stdout.read()
	data.stdout.close()
	output = list(output.decode("utf-8").split("\n"))
	output.pop()
	return output


# function to draw a bar/node
def	draw_bar(array, i, screen, color, stack):
	n = len(array)
	w, h = screen.get_size()
	w = (w / 2) - 50
	h -= 100
	node_width = (w * ((array[i] + stackmax) / stackrange)) + 5
	node_height = h / stacksize
	x = 30
	if stack == 'b':
		x = 330
	y = (node_height * i) + 70
	bar = pg.Rect(x, y, node_width, node_height)
	pg.draw.rect(screen, color, bar)


# function to draw the whole stack
def	draw_stacks(a_stack, b_stack, screen):
	screen.fill(pg.Color(background))
	n = len(a_stack)
	for i in range(n):
		colour_i = (a_stack[i] + stackmax) / n_range
		colour_i = int(colour_i)
		draw_bar(a_stack, i, screen, colours[colour_i], 'a')
	n = len(b_stack)
	i = 0
	for i in range(n):
		colour_i = (b_stack[i] + stackmax) / n_range
		colour_i = int(colour_i)
		draw_bar(b_stack, i, screen, colours[colour_i], 'b')


def	init():
	pg.init()
	screen = pg.display.set_mode((width, height))
	screen.fill(background)
	pg.display.set_caption("Push_swap visualizer")
	return screen

def	main():
	run = True
	clock = pg.time.Clock()
	sizenumber = 0
	newstacksize = ''
	active = False
	color = color_inactive
	screen = init()
	solvespeed = 10

	font = pg.font.Font(None, 32)
	sizetext = font.render('size:', True, textcolor, background)
	sizetextRect = sizetext.get_rect()
	sizetextRect.center = (50, 26)

	bg = pg.Surface(screensize)
	screen.blit(bg, (0, 0))
	pg.draw.rect(bg, background, (0, 0, 600, 700))

	a_stack = random.sample(range(int(stackmin), int(stackmax)), int(stacksize))
	b_stack = []
	print(len(b_stack))
	#istr = ['{:.2f}'.format(x) for x in a_stack]
	jstr = [str(x) for x in a_stack]
	x = 0
	istr = " ".join(str(x) for x in jstr)
	x = 0
	ps_moves = get_moves(istr)
	moves_len = len(ps_moves)
	#print("istr: ", istr)
	#ps_moves = get_moves(istr)
	#print("a_stack: ", a_stack)
	#print("ps moves: ", ps_moves)
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
						print(newstacksize)
						newstacksize = ''
					elif event.key == pg.K_BACKSPACE:
						newstacksize = newstacksize[:-1]
					elif event.key == pg.K_UP:
						solvespeed *= 1.5
					elif event.key == pg.K_DOWN:
						solvespeed /= 1.5
					else:
						newstacksize += event.unicode
				if event.key == pg.K_ESCAPE:
					run = False
				if (sizenumber < 0):
					sizenumber = 0
				elif (sizenumber > 10000):
					sizenumber = 10000
		draw_stacks(a_stack, b_stack, screen)
		if x < moves_len:
			exec_move(ps_moves[x], a_stack, b_stack)
			x += 1
		#screen.blit(bg, (0, 0))
		txt_surface = font.render('', True, color)
		width = max(200, txt_surface.get_width()+10)
		size_inputbox.w = width
		screen.blit(sizetext, sizetextRect)
		screen.blit(txt_surface, (size_inputbox.x+5, size_inputbox.y+5))
		pg.draw.rect(screen, color, size_inputbox, 2)
		pg.display.flip()
		pg.time.delay(solvespeed)
	pg.quit()

main()