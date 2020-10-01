#include <bits/stdc++.h>
using namespace std;

int N;

int A[1000][1000], B[1000][1000], result[1000][1000];

void multiplica() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			result[i][j] = 0;
			for (int k=0; k<N; k++) {
				result[i][j] += (A[i][k] * B[k][j]);
			}
		}
	}
}


int main() {
		
	while (scanf("%d", &N) != EOF) {
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++) {
				scanf("%d", &A[i][j]);
			}
		}

		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++) {
				scanf("%d", &B[i][j]);
			}
		}

		clock_t begin = clock();
		
		multiplica();
		
		clock_t end = clock();
  		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

		printf("%lf seconds\n", elapsed_secs);
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++) {
				printf("%d ", result[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
