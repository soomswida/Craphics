#ifndef CANVAS_H
#define CANVAS_H

void makeCanvas(int rows, int cols, char canvas[rows][cols]);

void printCanvas(int rows, int cols, char canvas[rows][cols]); 

void initMat(int rows, int cols, void* mat, void (*initMatCallBack)(int, int, void*));

void intMat(int rows, int cols, void* mat);

void doubleMat(int rows, int cols, void* mat); 

#endif /* CANVAS_H */
