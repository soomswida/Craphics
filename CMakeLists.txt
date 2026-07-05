cmake_minimum_required(VERSION 3.23) 

project(Cimulation LANGUAGES C)

add_executable(Cimulation
		./src/main.c
		./src/canvas.c
		./src/geometry.c
		./src/myBuffer.c
		./src/simpleGrid.c
) 
