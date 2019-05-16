#include <stdio.h>
#include <unistd.h>

void merge(int *A, int p, int q, int r){
	int n1 = q - p +1;
	int n2 = r - q;
	int L[n1], R[n2];
	int i,j,k;

	printf("merge:%d-%d-%d\n", p, q, r);
for (i=p; i< r+1; i++)
	printf("%d ", A[i]);
printf("\n");

	for ( i=0; i<n1; i++)
		L[i] = A[p+i];
	for ( j=0; j<n2; j++)
		R[j] = A[q+1+j];
	i =j = 0;
	for ( k=p; k<r+1; k++){
		if ( (j==n2) || ( (i<n1) && (L[i] <= R[j]) ) ) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
		printf("%d ", A[k]);
	} 
	printf(" <- merged. \n");

}

void mergeSort(int *A, int p, int r){
	int q;
	printf("mergeSort:%d-%d\n", p, r);

    	if (p < r) {
        	q = (p+r)/2;
		sleep(1);
        	mergeSort(A, p, q);
        	mergeSort(A, q+1, r);
        	merge(A, p, q, r);
	}
}

int main(int argc, char *argv[] ){
	int A[8]={5, 2, 4, 7, 1, 3, 2, 6 };
	int i=0;
	int len = sizeof(A)/sizeof(int);
	printf("To sort %d numbers: \n", len);
	for (i=0; i<len; i++)
		printf("%d ", A[i]);
	printf("\n");

	mergeSort(A, 0, len-1);
}
