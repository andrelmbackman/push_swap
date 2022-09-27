import pygame as pg
import random
import subprocess

stacksize = int(100)
stackmin = int(-55555)
stackmax = int(55555)
stackrange = int(stackmax - stackmin)
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
#background = (42, 72, 88)
background = (25, 25, 25)
textcolor = (250, 250, 110)
size_inputbox = pg.Rect(100, 10, 140, 32)
color_inactive = pg.Color('lightskyblue3')
color_active = pg.Color('dodgerblue2')
width = 600
height = 700
solvespeed = 100
screensize = (width,height)

# function to draw a bar/node
def	draw_bar(array, i, screen, color, stack):
	n = len(array)
	w, h = screen.get_size()
	w = (w / 2) - 50
	h -= 100
	node_width = w
	node_height = h / n
	x = 20
	if stack == 'b':
		x = 310
	y = (node_width * i) + 50
	bar = pg.Rect(x, y, node_width, node_height)
	pg.draw.rect(screen, color, bar)


# function to draw the whole stack
def	draw_stacks(a_stack, b_stack, screen):
	screen.fill(pg.Color(background))
	n = len(a_stack)
	for i in range(n):
		colour_i = int(a_stack[i] / n_range)
		draw_bar(a_stack, i, screen, colours[colour_i], 'a')
	n = len(b_stack)
	for i in range(n):
		colour_i = int(b_stack[i] / n_range)
		draw_bar(b_stack, i, screen, colours[colour_i], 'b')


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

def	check_event(active):
	for event in pg.event.get():
		if event.type == pg.QUIT:
				return False
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
				return False
			if (sizenumber < 0):
				sizenumber = 0
			elif (sizenumber > 10000):
				sizenumber = 10000
	return True

def	main():
	run = True
	clock = pg.time.Clock()
	sizenumber = 0
	newstacksize = ''
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
	a_stack = random.sample(range(int(stackmin), int(stackmax)), int(stacksize))
	b_stack = []
	print(a_stack)
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
		#screen.blit(bg, (0, 0))
		txt_surface = font.render('', True, color)
		width = max(200, txt_surface.get_width()+10)
		size_inputbox.w = width
		screen.blit(sizetext, sizetextRect)
		screen.blit(txt_surface, (size_inputbox.x+5, size_inputbox.y+5))
		pg.draw.rect(screen, color, size_inputbox, 2)
		pg.display.flip()
	pg.quit()

main()