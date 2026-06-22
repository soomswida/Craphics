#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Alter the given matrix as a form of canvas
void makeCanvas(int rows, int cols, char canvas[rows][cols]) {
		for (int i = 0; i < cols; i++) {
				for (int j = 0; j < rows; j++) {
						if (j == 0 || j == rows - 1) {
							canvas[j][i] = '|';
						} else if (i == 0 || i == cols - 1) {
							canvas[j][i] = '-'; 
						} else {
							canvas[j][i] = ' ';
						}

				}
		}
}

void printCanvas(int rows, int cols, char canvas[rows][cols]) {
		for (int i = 0; i < cols; i++) {
				for (int j = 0; j < rows; j++) {
						printf("%c", canvas[j][i]);
				}
				printf("\n"); 
		}
}

// Generic function for matrix(including vector) initialization 
void initMat(int rows, 
	int cols, 
	void* mat, 
	void (*initMatCallBack)(int, int, void*)) {
	
	initMatCallBack(rows, cols, mat);
}


// Init by integer value 0
void intMat(int rows, int cols, void* mat) {
	int** int_mat = (int**)mat; 

	for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				int_mat[j][i] = 0; 
			}
	}
}

// Init by double value 0.0
void doubleMat(int rows, int cols, void* mat) {
	double** double_mat = (double**)mat;

	for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				double_mat[j][i] = 0.0; 
			}
	}
}


