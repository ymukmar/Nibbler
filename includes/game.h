

#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <openGl/gl.h>
#include <dlfcn.h>

#define UP 4
#define DOWN -4
#define RIGHT 5
#define LEFT -5

#define COLUMNS 40
#define ROWS 40
#define FPS 16

void    initGrid(int x, int y);
void    drawGrid();
void    drawSnake();

#endif
