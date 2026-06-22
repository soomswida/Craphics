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

		int width = atoi(argv[1]);
		int height = atoi(argv[2]);
		int how_long = atoi(argv[3]) * 1000;

		

		char canvas[width][height];
		makeCanvas(width, height, canvas);
		printCanvas(width, height, canvas); 


		int coord_x = 0;
		int coord_y = 50;

		int x = 0;
		int y = 0; 
		double raw_x = 0.0;
		double raw_y = 0.0;
		int len = 100;
		int buffer[len];
		for (int i = 0; i < len; i++) {
			buffer[i] = 0; 
		}

		printf("Debug: Before Animation Loop\n");

		// Animation Loop
		while (how_long != 0) {
			// Current Phase : Dynamic Trajectory of Trigonometric functions
			
			// #Current Issue# The trajectory is not printed.
			// - 1. Make another simple trajectory generator.
			// - 2. Test it. 


			printf("Debug: Animation Loop 1\n");
			// 1. Prepares ingredients 
			double x_scale = 1 / 15.0;
			double y_scale = 20.0;
			raw_x = (double)x;
			raw_y = y_scale * sin(raw_x * x_scale);
			y = (int)raw_y;
		
			printf("Debug: Animation Loop 2\n");
			// 2. Put it in the buffer
			intPush(len, &y, buffer);

			printf("[out of buffer - %d]", y); 

			// Debug - check the buffer
			for (int i = 0; i < len; i++) {
				printf("%d", buffer[i]);
			}
			printf("\n");

			printf("Debug: Animation Loop 3\n");
			// 3. Draw the trajectory
			drawTrajectory(width, height, canvas, coord_x, coord_y, len, buffer, y_scale);

			printf("Debug: Animation Loop 4\n");
			// 4. Print the canvas
			printCanvas(width, height, canvas);

			printf("Debug: Animation Loop 5\n");
			// 5. Reset the canvas
			makeCanvas(width, height, canvas); 

			// Increment
			x++; 	

			// Functionals
			how_long--; 
			clkSpeed(15.0); 
		}


		return 0;
}


