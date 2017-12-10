#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Householder(int n,double** a){
	double* v = (double*)calloc(n, sizeof(double));
	double* u = (double*)calloc(n, sizeof(double));
	double* z = (double*)calloc(n, sizeof(double));
	double q = 0, alpha=0, PROD = 0,RSQ=0;
	for (int k = 0; k < n - 2;k++){
		q = 0;
		for (int j = k + 1; j < n; j++){
			q = q + (a[j][k] * a[j][k]);
		}
		if (a[k + 1][k] == 0){
			 alpha = -sqrt(q);
		}
		else{
			alpha = -(sqrt(q)*a[k + 1][k]) / abs(a[k + 1][k]);
		}
		 RSQ = (alpha*alpha) - alpha*a[k + 1][k];
		v[k] = 0;
		v[k + 1] = a[k + 1][k] - alpha;
		for (int j = k + 2; j < n; j++){
			v[j] = a[j][k];
		}
		for (int j = k ; j < n; j++){
			for (int i = k + 1; i < n; i++){
				u[j] = (a[j][i] * v[i])/RSQ;
			}
		}
		PROD = 0;
		for (int i = k + 1; i< n; i++){
			PROD = PROD + v[i]*u[i];
		}
		for (int j = k ; j < n; j++){
			z[j] = u[j] - (PROD*v[j] / (2.0*RSQ));
		}
		for (int l = k + 1; l < n - 1; l++){
			for (int j = l + 1; j < n; j++){
				a[j][l] = a[j][l] - v[l] * z[j] - v[j] * z[l];
				a[l][j] = a[j][l];
			}
			a[l][l] = a[l][l] - 2 * v[l] * z[l];
		}
			a[n - 1][n - 1] = a[n - 1][n - 1] - 2 * v[n - 1] * z[n - 1];
			for (int j = k + 2; j < n; j++){
				a[j][k] = 0;
				a[k][j] = 0;
			}
			a[k + 1][k] = a[k + 1][k] - v[k + 1]*z[k];
			a[k][k + 1] = a[k + 1][k];
		}
	for (int i=0; i < n; i++){
		for (int j =0; j < n; j++){
			printf("%f\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	free(v);
	free(u);
	free(z);
}



int main(int argc, char**argv){
	int n = 3;
	int m = 5;
	double A[3][3] = {
		{ 4.75, 2.25, -0.25 },
		{ 2.25, 4.75, 1.25 },
		{ -0.25, 1.25, 4.75 } };
	double B[5][5] = {
		{2,-1,-1,0,0}, 
		{-1,3,0,-2,0}, 
		{-1,0,4,2,1}, 
		{0,-2,2,8,3}, 
		{0,0,1,3,9}
	};
	double**c = (double**)calloc(n, sizeof(double*));
	double**d = (double**)calloc(m, sizeof(double*));
	for (int i = 0; i < n; i++){
		c[i] = (double*)calloc(n, sizeof(double));
	}	for (int i = 0; i < m; i++){
		d[i] = (double*)calloc(m, sizeof(double));
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			c[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			d[i][j] = B[i][j];
		}
	}


	Householder(n, c);
	Householder(m, d);
	for (int i = 0; i < m; i++){
		free(d[i]);
	}
	for (int i = 0; i < n; i++){
		free(c[i]);
	}
	free(c);
	free(d);
	return 0;
}