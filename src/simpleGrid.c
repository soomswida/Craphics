#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "canvas.h"
#include "simpleGrid.h"
// Note. The sequence of the import statement definetely matters!

// The Basic usage of it and the pipeline which it will be applied to
// 1. Get intersections of a given geometry. 
// 2. Translate the result into the form of `canvas`.

// Consequently, the pipleline will be:
// [Geometry] -> 
// [Grid with its intersections] -> 
// [Canvas with determined points of the geometry]

// The main function: Empty Canvas & Gemetry -> Painted(Interploated) Canvas

// But for now, we need to show it can properly deal with a really simple geometry,
// for example, a straight line.

// This line stuff, acutally, has more importance than as a mere simple test,
// because it will play a primary role when it comes to 'polygon'.



// Helper of `unitLinePainter` — builds a pixter matrix(Grid) w.r.t. 
// the given canvas.
void buildGrid(matt* canvas, pgrid* grid) {
	int rows = canvas->rows;
	int cols = canvas->cols;

	grid->rows = rows;
	grid->cols = cols;

	pixter **mat = (pixter **)malloc(rows * sizeof(pixter*));
	for (int i = 0; i < rows; i++) mat[i] = (pixter *)malloc(cols * sizeof(pixter));

	// Initialize with 0
	pixter init_cell;
	init_cell.inters[0] = 0;
	init_cell.inters[1] = 0;
	init_cell.degree = 0;

	for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				mat[i][j] = init_cell;
			}
	}

	grid->mat = mat; 

}


// Let's implement a function for an unit line: 
// ([0,0], [0,1]) && ([0,0], [1,0]) && ([0,0], [1,1]) && [(0,1), (1,0)]


/*
But, why do we need those four type of unit lines at the first place? 
They can be yielded by the simplest linear transformation.
What we really need is a single line and the logic for its 
linear transformation. 
*/

void unitLinePainter(matt* canvas, udot origin, int len, double rad) {
	// Get the size of canvas dynamically
	// But the `sizeof` approach is too heavy and bolilerplate
	// Defining a dedicated type for this is way more concise! --> `matt` (done)
	int rows = canvas->rows;
	int cols = canvas->cols; 
	char** mat = canvas->mat; 

	// Make a pixter matrix w.r.t. the size above
	// only for local usage
	pgrid grid;
	buildGrid(canvas, &grid);

	// Iterate the pixter matrix w.r.t. the given geometry
	
	// Put two dots along with the given origin and len.
	// The initial State is flat.
	

	// Get the two dots
	double left_x = 0.0;
	double right_x = 0.0;
	double x_o = (double)origin.coords[0];
	double y_o = (double)origin.coords[1]; 

	if (len % 2 != 0) {
		left_x = (double)(len / 2 + 1);
		right_x = (double)(len / 2); 
	} else {
		left_x = (double)(len / 2); 
		right_x = (double)(len / 2); 
	}

	// Coordination
	double lower_x = x_o - left_x; 
	double upper_x = x_o + right_x;
	double lower_y = y_o - left_x;
	double upper_y = y_o + right_x;

	left_x = lower_x;
	double left_y = y_o;
	right_x = upper_x;
	double right_y = y_o; 

	// Rotation Transformation
	double theta = rad * (180 / M_PI);

	double buffer_x = left_x;
	double buffer_y = left_y;

	left_x = buffer_x * cos(theta) - buffer_y * sin(theta);
	left_y = buffer_x * sin(theta) + buffer_y * cos(theta);

	buffer_x = right_x;
	buffer_y = right_y;

	right_x = buffer_x * cos(theta) - buffer_y * sin(theta);
	right_y = buffer_x * sin(theta) + buffer_y * sin(theta); 

	


	// Get the expression for the line w.r.t. the given radian
	double gradient = (right_y - left_y) / (right_x - left_y);  

	// Exceptions 
	int isFlat = 0;
	int isStand = 0; 

	if (right_y - left_y == 0) { // flat
		isFlat = 1;
	} else if (right_x - left_y == 0) { // stand
		isStand = 1;
	} else {
		// Normal, do nothing
	}
	

	// Get the intersection of the line of two dots on the grid
	// Minimize the number of operatons with lower/upper bounds
	for (int i = lower_x; i <= upper_x; i++) {
			for (int j = lower_y; i <= upper_y; j++) {

			}
	}

	
}
