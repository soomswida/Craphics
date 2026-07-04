// On collision - How we can deal with it? 

// Assume a location != ' ' means 'occupied'
// Require another datastructure

// Need to iterate all objects(every pixel it occupies)

// Then:

// 1. Need to store all points that already has been occupied.
// 2. Need to iterate the database when the clk is updated.
// 3. Need each geometry have its attributes like:
//	- direction
//	- speed
//	- location


// The pipeline would be:

// (1) When it comes to autonomous system [primary]
//	geometries ----> location DB ----> printFunction
//		|_____feedback_____|

// (2) When it comes to defined animation [secondary]
//	---> But it's utterly different to the problem above!.
