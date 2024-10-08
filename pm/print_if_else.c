#include <stdio.h>
#include <unistd.h>

void func_1(){
	if (printf("Hello ") == 0)
		printf("Hello ");
	else
		printf("world\n");
}

void func_2(){
	if (fork())
		printf("Hello ");
	else
		printf("world\n");
}

void main(){
	func_1();
	func_2();
}
