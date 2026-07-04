#ifndef GEOMETRY_H
#define GEOMETRY_H

void drawTrajectory(int rows,
	int cols,
	char canvas[rows][cols], 
	int x,
	int y,
	int len,
	int buffer[len],
	int norm); 

void simpleTrajectory(int rows,
	int cols,
	char canvas[rows][cols], 
	int x,
	int y); 

void drawUnboundedTrajectory();

#endif /* GEOMETRY_H */
