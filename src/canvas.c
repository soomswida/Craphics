#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "canvas.h"

// Note. The structure of `matt`
/*
   typedef struct {
   		char** mat;
		int rows;
		int cols; 
   }
*/

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

// ## Lesson on pass-by-value
/*

   ```
   void buildMmat(int rows, int cols, matt mmatrix)
   ```

   When we paas `canvas` into `buildMat`, the function receives a *copy* of the structure. Any Modification inside `buildMmat` are lost as soon as the function returns --> Namely, it was a basic 'scope' pitfall!

   In short, I've changed the parameter `mmatrix`'s type from matt to matt*.  

	[o] The issue has resolved.
*/
void buildMmat(int rows, int cols, matt* mmatrix) {
	mmatrix->rows = rows;
	mmatrix->cols = cols;
	
	// Malloc
	// Option 1
	char **mat = (char **)malloc(rows * sizeof(char*)); 
	for (int i = 0; i < rows; i++) mat[i] = (char *)malloc(cols * sizeof(char)); 
	
	// Option 2
	//char *mat = (char *)malloc(rows * cols * sizeof(char));

	// Assign it
	mmatrix->mat = mat; 
}

// ## Lesson on memory leak
/*
	Since we allocated our memory using Option 1(an array of pointer), the below version of free() will only free the top-level array of pointers. 

	```
	free(mmatrix.mat); 
	```

	So I've edited code to free the memory in the exact reverse order that we allocated it. 

	[o] The issue has resolved.

*/
void destroyMmat(matt mmatrix) {
	// free(mmatrix.mat); // Wrong!
		if (mmatrix.mat != NULL) { // Safe condition
				for (int i = 0; i < mmatrix.rows; i++) {
					free(mmatrix.mat[i]);
				}
				free(mmatrix.mat);
		}
}

// Receive a pointer of matt
void mmakeCanvas(int rows, int cols, matt* canvas) {
	// Put parameters &&
	// Memory Allocation — Sedfault seems from its absence
	buildMmat(rows, cols, canvas); // Pass a pointer of it

	//char** mat = canvas.mat; 

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			if (j == 0 || j == rows - 1) {
				canvas->mat[j][i] = '|';
			} else if (i == 0 || i == cols - 1) {
				canvas->mat[j][i] = '-'; 
			} else {
				canvas->mat[j][i] = ' ';				
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

void mprintCanvas(matt canvas) {
		printf("is it even working?\n");
		int rows = canvas.rows;
		int cols = canvas.cols;
		printf("rows:%d, cols:%d\n", rows, cols);
		//char **mat = canvas.mat; 
		for (int i = 0; i < cols; i++) {
				for (int j = 0; j < rows; j++) {
						printf("%c", canvas.mat[j][i]);
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


