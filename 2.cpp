#include <stdio.h>
#define MAX 4

void quickSort(int *a, int left, int right){
	int i,j,x,y;
	
	i = left;
	j = right;
	x = a[(left + right)/2];
	
	while(i <= j){
		while(a[i] < x && i < right){
			i++;
		}
		while(a[j] > x && j > left){
			j--;
		}
		if(i <= j){
			y = a[i];
			a[i] = a[j];
			a[j] = y;
			i++;
			j--;
		}
		if(j > left){
			quickSort(a, left, j);
		}
		if(i < right){
			quickSort(a, i, right);
		}
	}
}

int main(int argc, char** argv){
	int i, vet[MAX];
	for(i=0; i<MAX; i++){
		printf("Digite um valor: \n");
		scanf("%d", &vet[i]);
	}
	quickSort(vet,0,MAX - 1);
	printf("Valores ordenados\n");
	for(i=0; i<MAX; i++){
		printf("%d\t", vet[i]);
	}
	
	return 0;
}

/*TEMPO DE EXECUCAO DO BUBBLESORT: 3,27s
TEMPO DE EXECUCAO DO QUICKSORT: 3,03s
TEMPO DE EXECUCAO DO MERGESORT: 1,83s*/
