#ifndef SIMPLEGRID_H
#define SIMPLEGRID_H

#endif /* SIMPLEGRID_H */

// Requires a type which contains
// 1. intersections(x-up, y-left)
// 2. degree(0: None, 1: Weak, 2: Normal, 3: Strong)
typedef struct {
	double inters[2],
	int degree, 
}
