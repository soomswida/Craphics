#ifndef SIMPLEGRID_H
#define SIMPLEGRID_H

// Requires a type `pixter` which contains
// 1. intersections(x-up, y-left)
// 2. degree(0: None, 1: Weak, 2: Normal, 3: Strong)
typedef struct {
	double inters[2];
	int degree;
} pixter;

typedef struct {
	pixter** mat;
	int rows;
	int cols; 
} pgrid; 

// Requires a type `unit` for further `polygon` approach
typedef struct {
	int coords[2];
} udot;


enum units {
	FLAT,
	UP,
	RIGHTUP,
	LEFTUP,
};

typedef struct {
	udot uline[2];		
} unit;

void buildGrid(matt* canvas, pgrid* grid);
void destroyGrid(pgrid grid); 

void unitLinePainter(matt* canvas, udot origin, int len, double rad); 

#endif /* SIMPLEGRID_H */

  
