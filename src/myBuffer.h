#ifndef MYBUFFER_H
#define MYBUFFER_H

typedef void (*popCallBack)(int, void*); 

void myPop(int len, void* buffer, popCallBack callback);

void myPush(int len, void* item, void* buffer, void (*myPushCallBack)(int, void*, void*));

void intPop(int len, void* buffer);

void doublePop(int len, void* buffer);

void charPop(int len, void* buffer);

void intPush(int len, void* item, void* buffer);

void doublePush(int len, void* item, void* buffer);

void charPush(int len, void* item, void* buffer); 

#endif /* MYBUFFER_H */
