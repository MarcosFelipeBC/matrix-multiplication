#include <bits/stdc++.h>
using namespace std;

int mat[1000][1000];

int main()
{
	int n;
	scanf("%d", &n);
	srand(time(NULL));
		
	printf("%d\n", n);
		
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			mat[i][j] = rand() % 11;
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			mat[i][j] = rand() % 11;
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
