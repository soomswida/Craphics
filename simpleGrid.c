#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "simpleGrid.h"

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

// Let's implement a function for an unit line: 
// ([0,0], [0,1]) && ([0,0], [1,0]) && ([0,0], [1,1]) && [(0,1), (1,0)]
**char unitLinePainter(**char canvas, unit geometry) {
	// Get the size of canvas dynamically
	// But the `sizeof` approach is too heavy and bolilerplate
	// Defining a dedicated type for this is way more concise! --> `matt` (on the phase of debugging)

	// Make a pixter matrix w.r.t. the size above

	// Iterate the pixter matrix w.r.t. the given geometry

	// Translate the pixter matrix into the canvas matrix
}
