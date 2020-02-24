#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isOperand(char);
int comparePrecedence(char, char);
int getPrecedence(char);

int main(){
	STACK* s = (STACK*)malloc(sizeof(STACK));
	s->top = -1;

	FILE* fp;
	fp = fopen("infix.txt", "r");
	
	char op = 0; //variable for a operand or operator;

	while(1){
		fscanf(fp, "%c", &op);
		if(op == '#') break;

		/* when op is operand */
		
		if(isOperand(op)){
			printf("%c ", op);
			continue;
		}
		
		/* when op is operator */
		
		if(isEmpty(s)){ //when stack is empty
			Push(s, op); 
			continue;
		}

		if(op == ')'){ //when incoming operator is ')'
			do{
				printf("%c ", Top(s)); //print operators in stack until meets '('
				Pop(s);
			}while(Top(s) != '(');
			Pop(s); //Pop '('
			continue;
		}

		//when precedence of the top operator in stack is MORE than incoming operator
		if(comparePrecedence(Top(s), op) == -1){
			Push(s, op);
		}
		//when precedence of the top operator in stack is equal to or LESS than incoming operator
		else{
			while(!isEmpty(s) && Top(s) != '(' && comparePrecedence(Top(s), op) == 1){
				printf("%c ", Top(s));
				Pop(s);
			}
			Push(s, op);
		}

	}
	
	while(!isEmpty(s)){
		printf("%c ", Top(s));
		Pop(s);
	}
	
	printf("\n");
	free(s);
	fclose(fp);
	return 0;
}

int isOperand(char c){
	return (c >= '0' && c <= '9');
}

int comparePrecedence(char stackOper, char incomingOper){
	int prec_SO = getPrecedence(stackOper);
	int prec_IO = getPrecedence(incomingOper);
	
	if(prec_SO >= prec_IO) return 1;
	else return -1;
}

int getPrecedence(char operator){
	switch (operator) {
		case '(':
		case ')':
			return 3;
			break;

		case '*':
		case '/':
		case '%':
			return 2;
			break;

		case '+':
		case '-':
			return 1;
			break;
		default:
			printf("Error: Wrong operator!");
			return -1;
	}
}

