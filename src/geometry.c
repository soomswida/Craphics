#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myBuffer.h"

// Define a geometry

// 1. Algebraic way (basic equations)
// -- a. Calculates with given formulars
// -- b. Returns approximated coordinates in integer form. 


// 1.1. Circle
// x^2 + y^2 = r^2
// { (x,y) | y = - sqrt(r^2 - x^2) || y = sqrt(r^2 - x^2) }

// 1.1.1. Issue - The problem of discrete pixels(integer values)
// error = sqrt((r^2 -(x^2+y^2))^2)
// if (error < 1) : draw it


// 1.2. Trigonometric functions
// sin(x), cos(x)
// - approximation is not necessary here.
// just x++; y = sin(x); initPush(len, y, buffer); would be enough.


// 2. Discrete way (dots and lines)


// Draw a geometry
// 1. Get the object block or data
// 2. Put it onto the canvas

// Draw a trajectory
// 1. Get the series of object or data (namely buffer here)
// 2. Put it onto the canvas
void drawTrajectory(int rows, 
	int cols, 
	char canvas[rows][cols],
	int x,
	int y,
	int len, 
	int buffer[len],
	int norm) { // 2-dim(bounded to x-axis(): get 1-dim vec

	// Minimal Exception Handling
	int x_outOfBound = x < 0 || x > rows;
	int y_outOfBound = y < 0 || y > cols; 

	int in_x = x;
	int in_y = y; 
	int idx = 0;
	int result_x = 0;
	int result_y = 0; 

	if (x_outOfBound || y_outOfBound) {
		printf("Invalid coordinates.\n");
	} else {
			for (int i = 0; i < rows; i++) {
					if (buffer[i] + in_y  < 0 || buffer[i] + in_y  > cols) {
						// do nothing
					} else {

						result_y = in_y + buffer[i]; 
						canvas[i][result_y] = '#';
					} 
			}	
	}

}

void simpleTrajectory(int rows,
	int cols,
	char canvas[rows][cols],
	int x,
	int y) {


}

void drawUnboundedTrajectory() { // 2-dim(unbounded): get 2-dim mat

}

