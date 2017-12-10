#include<stdio.h>
#include<math.h>

double f(int x, int i){
	double y;
	switch (i)
	{case 1:
		break;
	case 2:
		break;

	default:
		break;
	}
}

void Pade(int m, int n){
	int N = m + n;
	double *a = (double*)malloc(N+2*sizeof(double));
	double *q = (double*)malloc(N+2*sizeof(double));
	double *p = (double*)malloc(N+2*sizeof(double));
	double**b = (double**)malloc(N + 2 * sizeof(double*));
	for (int i = 0; i <= N + 2; i++){
		b[i]= (double*)malloc(N+2*sizeof(double));
	}
	for (int i = 0; i <= N; i++){
		a[i] = f(0,i) / factorial(i);
	}
	q[0] = 1;
	p[0] = a[0];
	for (int i = 1; i <= N; i++){
		for (int j = 1; j < i - 1; j++){
			if (j <= n){
				b[i][j] = 0;
			}
		}
		if (i <=n){
			b[i][i] = 1;
		}
		for (int j = i + 1; j <= N; j++){
			b[i][j] = 0;
		}
		for (int j = 1; j <= i; j++){
			b[i][n + j] == a[i - j];
		}
		for (int j = n + i + 1; j <= N; j++){
			b[i][N + 1] = a[i];
		}}
	for (int i = n + 1; i <= N - 1; i++){
		int k = i;
		double max = abs(b[i][i]);
		for (int j = i; j <= N; j++){
			if (abs(b[j + 1][i]) > max){
				max = abs(b[j + 1][i]);
			}
		}

		b[k][i] = max;
		if (b[k][i] == 0){
			printf("The system is singular\n");
			break;
		}
		if (k != i){
			for (int j = i; j <= N + 1; j++){
				double temp = b[i][j];
				b[i][j] = b[k][j];
				b[k][j] = temp;
			}
		}
		for (int j = i + 1; j <= N; j++){
			double xm = b[j][i] / b[i][i];
			for (k = i + 1; k <= N + 1; k++){
				b[j][k] = b[j][k] - xm*b[i][k];
			}
			b[j][i] = 0;
			if (b[N][N] == 0){
				printf("The system is singular\n");
				break;
			}
		}
	}
			
			if (m > 0){
				q[m] = b[N][N + 1] / b[N][N];
			}
			for (int i = N - 1; i >= n + 1;i--){
				double sum = 0;
				for (int j = i + 1; j <= N; j++){
					sum = sum + b[i][j] * q[i - n];
				}
				q[i - n] = (b[i][N + 1] - sum) / b[i][i];
			}
			for (int i = n; i >= 1; i--){
				double sum = 0;
				for (int j = n + 1; j <= N; j++){
					sum = sum + b[i][j] * q[j - n];
				}
				p[i] = b[i][N + 1] - sum;
			}
			for (int i = 0; i <= m; i++){
				printf("q%d=%f\n", i, q[i]);
			}
			for (int i = 0; i <= m; i++){
				printf("p%d=%f\n", i, p[i]);
			}
			free(p);
			free(q);
			free(a);
			for (int i = 0; i < N + 2; i++){
				free(b[i]);
			}
			free(b);

}
