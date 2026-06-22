#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "canvas.h"
#include "geometry.h" 
#include "myBuffer.h" 

//-----------------------Clock
void clkSpeed(float sec) {
	float ms = 1000 * sec;
	clock_t start = clock();
	while (clock() < start + ms) {
		// wait
	}
}

//-----------------------Main
int main(int argc, char *argv[]) {
		// Exception Check 
		if (argc < 3) {
			printf("No arguments were provided.\n");
			return 1;
		} else if (argc >= 5) {
			printf("Too many arguments were provided.\n");
			return 1; 
		} 

		// Size and Time
		int width = atoi(argv[1]);
		int height = atoi(argv[2]);
		int len = atoi(argv[3]) * 100;
		char canvas[width][height];

		// Object Configs
		int coord_x = 0;
		int coord_y = 50;
		int x = 0;
		int y = 0; 
		double raw_x = 0.0;
		double raw_y = 0.0;
	
		double x_scale = 1 / 4.0;
		double y_scale = 25.0;

		// Buffer 
		int buffer[len];
		for (int i = 0; i < len; i++) {
			buffer[i] = 0; 
		}

		// Animation Loop
		while (1) {
			// Current Phase : Dynamic Trajectory of Trigonometric functions
			
			// #Current Issue# The trajectory is not printed.
			// - 1. Make another simple trajectory generator.
			// - 2. Test it. 

			// 1. Prepares ingredients 
			raw_x = (double)x;
			raw_y = y_scale * sin(raw_x * x_scale);
			y = (int)raw_y;
		
			// 2. Put it in the buffer
			intPush(len, &y, buffer);

			// 3. Draw the trajectory
			drawTrajectory(width, height, canvas, coord_x, coord_y, len, buffer, y_scale);

			// 4. Print the canvas
			printCanvas(width, height, canvas);

			// 5. Reset the canvas
			makeCanvas(width, height, canvas); 

			// Increment
			x++; 	

			// Functionals 
			clkSpeed(15.0); 
		}


		return 0;
}


