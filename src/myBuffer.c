#include <stdio.h>
#include <stdlib.h>
#include "myBuffer.h" 

// Data structure for buffer
void myPop(int len, void* buffer, popCallBack callback) {
	callback(len, buffer);
} 

void myPush(int len, void* item, void* buffer, void (*myPushCallBack)(int, void*, void*)) {
	myPushCallBack(len, item, buffer);
} 

void intPop(int len, void* buffer) {
	int* int_buffer = (int*)buffer;
	int_buffer[0] = 0;
	for (int i = 0; i < len - 1; i++) {
		int_buffer[i] = int_buffer[i+1];
	}
}

void doublePop(int len, void* buffer) {
	double* double_buffer = (double*)buffer;
	double_buffer[0] = 0.0;
	for (int i = 0; i < len - 1; i++) {
		double_buffer[i] = double_buffer[i+1]; 
	}
}

void charPop(int len, void* buffer) {
	char* char_buffer = (char*)buffer;
	char_buffer[0] = ' ';
	for (int i = 0; i < len - 1; i++) {
		char_buffer[i] = char_buffer[i+1];
	}
}

void intPush(int len, void* item, void* buffer) {
	int fetched = *(int *)item;
	int* int_buffer = (int*)buffer;
	for (int i = len - 2; i >= 0; i--) {
		int_buffer[i+1] = int_buffer[i];
	}
	int_buffer[0] = fetched; 
}

void doublePush(int len, void* item, void* buffer) {
	double fetched = *(double *)item; 
	double* double_buffer = (double*)buffer;
	for (int i = len - 2; i >= 0; i--) {
		double_buffer[i+1] = double_buffer[i];
	}
	double_buffer[0] = fetched; 
}

void charPush(int len, void* item, void* buffer) {
	char fetched = *(char *)item;
	char* char_buffer = (char*)buffer;
	for (int i = len - 2; i >= 0; i--) {
		char_buffer[i+1] = char_buffer[i];
	}
	char_buffer[0] = fetched; 
}


