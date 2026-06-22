cmake_minimum_required(VERSION 3.23) 

project(Cimulation LANGUAGES C)

add_executable(Cimulation
		main.c
		canvas.c
		geometry.c
		myBuffer.c
) 
