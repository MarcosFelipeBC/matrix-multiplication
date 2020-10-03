#include <bits/stdc++.h>
using namespace std;

const int N = 805;

struct matrix {
    int sz;
    int mat[N/2][N/2];
};

int x[N][N], y[N][N], result[N][N];

matrix a, b, c, d, e, f, g, h;
matrix p1, p2, p3, p4, p5, p6, p7;

matrix add(matrix a, matrix b) {
    matrix c;
    c.sz = a.sz;
    int n = c.sz;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
        }
    }
    return c;
}

matrix diff(matrix a, matrix b) {
    matrix c;
    c.sz = a.sz;
    int n = c.sz;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c.mat[i][j] = a.mat[i][j] - b.mat[i][j];
        }
    }
    return c;
}

void mult(matrix a, matrix b, matrix &c) {
    c.sz = a.sz;
    int n = c.sz;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c.mat[i][j] = 0;
            for (int k=0; k<n; k++) {
                c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]); 
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++){
            scanf("%d", &x[i][j]);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++){
            scanf("%d", &y[i][j]);
        }
    }

    a.sz = b.sz = c.sz = d.sz = e.sz = f.sz = g.sz = h.sz = n/2;

    // Build A matrix
    for (int i=0, k=0; i<n/2; i++, k++) {
        for (int j=0, l=0; j<n/2; j++, l++) {
            a.mat[k][l] = x[i][j];
        }
    }
    
    // Build B matrix
    for (int i=0, k=0; i<n/2; i++, k++) {
        for (int j=n/2, l=0; j<n; j++, l++) {
            b.mat[k][l] = x[i][j];
        }
    }

    // Build C matrix
    for (int i=n/2, k=0; i<n; i++, k++) {
        for (int j=0, l=0; j<n/2; j++, l++) {
            c.mat[k][l] = x[i][j];
        }
    }

    // Build D matrix
    for (int i=n/2, k=0; i<n; i++, k++) {
        for (int j=n/2, l=0; j<n; j++, l++) {
            d.mat[k][l] = x[i][j];
        }
    }

    // Build E matrix
    for (int i=0, k=0; i<n/2; i++, k++) {
        for (int j=0, l=0; j<n/2; j++, l++) {
            e.mat[k][l] = y[i][j];
        }
    }
    
    // Build F matrix
    for (int i=0, k=0; i<n/2; i++, k++) {
        for (int j=n/2, l=0; j<n; j++, l++) {
            f.mat[k][l] = y[i][j];
        }
    }

    // Build G matrix
    for (int i=n/2, k=0; i<n; i++, k++) {
        for (int j=0, l=0; j<n/2; j++, l++) {
            g.mat[k][l] = y[i][j];
        }
    }

    // Build H matrix
    for (int i=n/2, k=0; i<n; i++, k++) {
        for (int j=n/2, l=0; j<n; j++, l++) {
            h.mat[k][l] = y[i][j];
        }
    }

    clock_t begin = clock();
	
    mult(a, diff(f, h), p1);
    mult(add(a, b), h, p2);
    mult(add(c, d), e, p3);
    mult(d, diff(g, e), p4);
    mult(add(a, d), add(e, h), p5);
    mult(diff(b, d), add(g, h), p6);
    mult(diff(a, c), add(e, f), p7);

    clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    for (int i=0, k=0; i<n/2; i++, k++) {
        for (int j=0, l=0; j<n/2; j++, l++) {
            result[i][j] = p5.mat[k][l] + p4.mat[k][l] - p2.mat[k][l] + p6.mat[k][l];
        }
    }
    
    for (int i=0, k=0; i<n/2; i++, k++) {
        for (int j=n/2, l=0; j<n; j++, l++) {
            result[i][j] = p1.mat[k][l] + p2.mat[k][l];
        }
    }

    for (int i=n/2, k=0; i<n; i++, k++) {
        for (int j=0, l=0; j<n/2; j++, l++) {
            result[i][j] = p3.mat[k][l] + p4.mat[k][l];
        }
    }

    for (int i=n/2, k=0; i<n; i++, k++) {
        for (int j=n/2, l=0; j<n; j++, l++) {
            result[i][j] = p1.mat[k][l] + p5.mat[k][l] - p3.mat[k][l] - p7.mat[k][l];
        }
    }
    
    printf("%lf seconds\n", elapsed_secs);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}