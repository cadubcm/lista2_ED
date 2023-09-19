#include <stdio.h>
#include <stdlib.h>
#define MAX 4

void insertionSort(int *a){
	int i, j, tmp;
	for(i=1; i < MAX; i++){
		tmp = a[i];
		for(j = i-1; j>=0 && tmp<a[j]; j--){
			a[j+1] = a[j];
		}
		a[j+1] = tmp;
	}
}

int main(int argc, char** argv){
	int i, vet[MAX];
	for(i=0; i < MAX; i++){
		printf("Digite um valor: \n");
		scanf("%d", &vet[i]);
	}
	
	insertionSort(vet);
	
	printf("\nValores ordenados\n");
	for(i=0; i < MAX; i++){
		printf("%d\t", vet[i]);
	}
}
