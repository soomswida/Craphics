#include <stdio.h>
#include "myBuffer.h"

int main(void) {
	int len = 5;
	int times = 10;
	int buffer[len];
	for (int i = 0; i < len; i++) {
		buffer[i] = 0;
	}

	while (times != 0) {
		intPush(len, &times, buffer);
		for (int i = 0; i < len; i++) {
			printf("%d,", buffer[i]);
		}
		printf("\n");
		times--; 
	}

	return 0;
}
