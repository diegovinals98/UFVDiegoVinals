#include <stdio.h>
void escribir(int **q);


int main(){
	int a[2][2] = {210, 330, 415, 101};
	int *b[2] =  {a[0] , &a[1][0]};
	int **p = b;
	//printf("%d\n" , a[1][0]);
	printf("%d, %d, %d, ",**p, b[1][1], **(p+1));
	escribir(b);
	// for(int i = 0; i < 2 ; i++){
	// 	for(int j = 0; j < 2 ; j++){
	// 		printf("\nCon a = %d, y con j = %d: %d\n",i,j,b[i][j] );
	// 	}
	// }
} 


void escribir(int **q)
{ 
	printf("%d",**(q+1)); 
}

	

