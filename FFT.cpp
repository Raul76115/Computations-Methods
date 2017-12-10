#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void pwr(double** A, double* x, int n, int N, double TOL){
	int k = 1;
	int i, j, p;
	double max = 0;
	for (i = 0; i<n; i++){
		if (abs(x[i])>max){
			max = abs(x[i]);
			p = i;
		}
	}
	for (i = 0; i<n; i++){
		x[i] = x[i] / (double)x[p];
	}
	double  mu, err = 0;
	double *y = (double*)calloc(n,sizeof(double));
	while (k <= N){
		for (i = 0; i<n; i++){
			for (j = 0; j<n; j++){
				y[i] = y[i] + A[i][j] * x[j];
			}
		}
		mu = y[p];
		
		max = abs(y[0]);
		for (i = 0; i<n; i++){
			if (abs(y[i])>max){
				max = abs(y[i]);
				p = i;
			}
		}

		if (y[p] == 0){
			printf("Eigenvector\n");

			for (i = 0; i<n; i++){
				for (j = 0; j<n; j++){
					printf("%f\t", x[j]);
				}
				printf("\n");
			}
			printf("Select new vector x\n");
			break;
		}
		err = 0;
		for (i = 0; i<n; i++){

			err = abs(x[i] - (y[i] / y[p])) + err;

		}
		for (i = 0; i<n; i++){
			x[i] = (y[i] / (double)y[p]);
		}

		if (err<TOL){
			printf("Mu =%f\n", mu);
			for (i = 0; i<n; i++){
				for (j = 0; j<n; j++){
					printf("%f\t", x[j]);
				}
				printf("\n");
			}
			break;
		}
		
		k++;
		
	}

	 free(y);

	
}

void NGauss(int n, double q, double **A, double *y, double *x){
	double** temp = (double**)calloc(n, sizeof(double*));
	for (int i = 0; i<n; i++){
		temp[i] = (double*)calloc(n, sizeof(double));
	}
	double** I = (double**)calloc(n, sizeof(double*));
	for (int i = 0; i<n; i++){
		I[i] = (double*)calloc(n, sizeof(double));
	}
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			if (i == j){
				I[i][j] = 1;
			}
		}
	}


	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			temp[i][j] = A[i][j] - q*I[i][j];
		}
	}

	double xmult, sum;
	for (int k = 0; k < n - 1; k++){
		for (int i = k + 1; i < n; i++){
			xmult = temp[i][k] / temp[k][k];
			temp[i][k] = xmult;
			for (int j = k + 1; j < n; j++){
				temp[i][j] = temp[i][j] - xmult*A[k][j];
			}
			x[i] = x[i] - xmult*x[k];
		}
	}
	y[n-1] = x[n-1] / temp[n-1][n-1];
	for (int i = n - 2; i >= 0; i--){
		sum = x[i];
		for (int j = i + 1; j<n; j++){
			sum = sum - temp[i][j] * y[j];
		}
		y[i] = sum /temp[i][i];
	}
	for (int i = 0; i<n; i++){
		free(I[i]);
		free(temp[i]);
	}
	free(I);
	free(temp);

}


void invpwr(double **A,double *x,int n,int N,double TOL){
	
	double* temp = (double*)calloc(n, sizeof(double));
	
	double q=0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			temp[i] = temp[i] + x[j] * A[j][i];
		}
	}

	for (int i = 0; i < n; i++){
		q = q + temp[i] * x[i];
	}
	int k = 1,p;
	double max = 0;
	for (int i = 0; i<n; i++){
		if (abs(x[i])>max){
			max = abs(x[i]);
			p = i;
		}
	}
	for (int i = 0; i<n; i++){
		x[i] = x[i] / (double)x[p];
	}
	double *y = (double*)calloc(n, sizeof(double));
	double mu,err;
	while (k <= N){
		//Guassian Elimination(A-qI)y=x
		NGauss(n, q, A, y, x);
		mu = y[p];
		max = abs(y[0]);
		for (int i = 0; i<n; i++){
			if (abs(y[i])>max){
				max = abs(y[i]);
				p = i;
			}
		}
		err = 0;
		for (int i = 0; i<n; i++){

			err = x[i] - (y[i] / y[p]) + err;

		}

		for (int i = 0; i<n; i++){
			x[i] = (y[i] / (double)y[p]);
		}
		if (err<TOL){
			mu = (1.0 / mu) + q;
			printf("Mu =%f\n", mu);
			for (int i = 0; i<n; i++){
				for (int j = 0; j<n; j++){
					printf("%f\t", x[j]);
				}
				printf("\n");
			}
			break;
		}

		k++;
	}

	
	free(y);
	free(temp);
	
}



int main(int argc, char**argv){
	int n=4;
	int N=5;
	double tol = 0.0001;
	double** A = (double**)calloc(n, sizeof(double*));
	double *x = (double*)calloc(n,sizeof(double));
	int i;
	for (i=0;i<n;i++){
	A[i] = (double*)calloc(n,sizeof(double));
	}

	 double B[4][4] =
	{{ -4, 0, .5, .5 },
	 {.5, -2, 0, .5 },
	 { .5, .5, 0, 0 },
	 { 0, 1, 1, 4 } };
	 double C[4] = { 0, 0, 0, 1 };
	 for (int i = 0; i < n; i++){
		 x[i] = C[i];
		 for (int j = 0; j < n; j++){
			 A[i][j] = B[i][j];
		 }
		
	 }

	invpwr(A, x, n, N, tol);
	for (i=0;i<n;i++){
	free(A[i]);
	}
	free(x);
	free(A);
	return 0;
}
