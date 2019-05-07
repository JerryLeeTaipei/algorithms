#include <stdio.h>

int main(int argc, char *argv[] ){

	char A[6] = {5, 2, 4, 6, 1, 3};
	int i=0, j=0, l=0, key=0;

	l = sizeof(A);
	
	for ( j=1; j<l; j++ ) {
		key = A[j]; 
		i = j-1;
		while ( (i > -1) && (A[i] >  key) ){
			A[i+1] = A[i];
			i=i-1;
		}
		A[i+1] = key;
	} 

	printf("Sorted: ");
	i = 0;
	while (i< l){
		printf("%d ", A[i]);
		i++;
	}
	printf("¥n");
}