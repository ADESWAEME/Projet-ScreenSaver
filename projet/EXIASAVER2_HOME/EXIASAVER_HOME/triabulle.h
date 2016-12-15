#include <stdio.h>
#include <stdlib.h>

void triabulle (int T[], int N)
{
	int i,j,temp;
	for(i=N-1;i>0;i--){
		for(j=1;j<=i;j++){
			if(T[j-1]<T[j]){
			}
		temp=T[j-1];
		T[j-1]=T[j];
		T[j]=temp;
		}
	}
}
