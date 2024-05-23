#include <stdio.h>
int main(void){
	int vector[5] = {2,4,6,8,10};
	int  *p1, *p2;
	p1= &vector[0];  
	p2 = &vector[4];
	printf("\ndirección del primer elemento =%x  ",p1);
	printf("\ndirección del ultimo elemento =%x  ",p2);
	printf("\n p2-p1 = %ld",p2-p1);
	printf("\n *p2-*p1 = %d\n",*p2-*p1);
	return 0;
}