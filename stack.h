#include <stdio.h>
#define STACK_CAPACITY 1024

typedef struct _STACK{
	int top;
	char stack[STACK_CAPACITY];
} STACK;

int isEmpty(STACK* s){
	return s->top == -1;
}

int isFull(STACK* s){
	return s->top == STACK_CAPACITY - 1;
}

char Top(STACK* s){
	if(isEmpty(s)){
		printf("Error: Stack is empty!\n");
		return '\0'; //return NULL
	}

	return s->stack[s->top];
}

void Pop(STACK* s){
	if(isEmpty(s)){
		printf("Error: Stack is empty!\n");
		return;
	}

	(s->top)--;
}

void Push(STACK* s, char data){
	if(isFull(s)){
		printf("Error: Stack is Full!\n");
		return;
	}

	s->stack[++(s->top)] = data;
}
