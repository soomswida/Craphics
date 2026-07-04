#ifndef CANVAS_H
#define CANVAS_H

typedef struct {
	char** mat;
	int rows;
	int cols;
} matt; 

void makeCanvas(int rows, int cols, char canvas[rows][cols]);
void mmakeCanvas(int rows, int cols, matt* canvas); 

void printCanvas(int rows, int cols, char canvas[rows][cols]); 
void mprintCanvas(matt canvas); 

void initMat(int rows, int cols, void* mat, void (*initMatCallBack)(int, int, void*));

void intMat(int rows, int cols, void* mat);

void doubleMat(int rows, int cols, void* mat); 

#endif /* CANVAS_H */
