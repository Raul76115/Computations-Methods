#include<stdio.h>
#include<math.h>
#define N 20
#define TOL 0.0001
#define n 5
#define m 5

double f(double x, double y);
double g(double x, double y);


int main(int argc,char**argv){

double a=0;
double b=1;
double c=0;
double d=1;

double h = (b-a)/n;
double k = (d-c)/m;
double x[n],y[m];
for(int i=1;i<=n-1;i++){
x[i]=a+i*h;}
for(int j=1;j<=m-1;j++){
y[j]=c+j*k;}

double w[n][m]={0};

double lambda = (h*h)/(k*k);
double mu=2.0*(1+lambda);
double l=1.0;
while (l <= N){
	double z = (-(h*h)*f(x[1], y[m - 1]) + g(a, y[m - 1]) + lambda*g(x[1], d) + lambda*w[1][m - 2] + w[2][m - 1]) / mu;

	double Norm = sqrt((z - w[1][m - 1])*(z-w[1][m-1]));
	w[1][m - 1] = z;
	for (int i = 2; i<=n - 2; i++){
		z = (-(h*h)*f(x[i], y[m - 1]) + lambda*g(x[i], d) + w[i - 1][m - 1] + w[i + 1][m - 1] + lambda*w[i][m - 2]) / mu;
		if (sqrt((w[i][m - 1] - z)*(w[i][m-1]-z))>Norm){
			Norm = sqrt((w[i][m - 1] - z)*(w[i][m-1]-z));
		}
		w[i][m - 1] = z;
	}

	z = (-(h*h)*f(x[n - 1], y[m - 1]) + lambda*g(x[n - 1], d) + g(b, y[m - 1]) + w[n - 2][m - 1] + lambda*w[n - 1][m - 2]) / mu;
	if (sqrt((w[n - 1][m - 1] - z)*(w[n-1][m-1]) > Norm)){
		Norm = sqrt((w[n - 1][m - 1] - z)*(w[n-1][m-1]-z));
	}
	w[n - 1][m - 1] = z;

	for (int j = m - 2; j >= 2; j--){
		z = (-(h*h)*f(x[1], y[j]) + g(a, y[j]) + lambda*w[1][j - 1] + lambda*w[1][j + 1] + w[2][j]) / mu;
		if (sqrt((w[1][j] - z)*(w[1][j]-z)) > Norm){
			Norm = sqrt((w[1][j] - z)*(w[1][j]-z));
		}
		w[1][j] = z;


		for (int i = 2; i <= n - 2; i++){
			z = (-(h*h)*f(x[i], y[j]) + w[i - 1][j] + lambda*w[i][j + 1] + lambda*w[i][j - 1] + w[i+1][j]) / mu;
			if (sqrt((w[i][j] - z)*(w[i][j]-z)) > Norm){
				Norm = sqrt((w[i][j] - z)*(w[i][j]-z));
			}
			w[i][j] = z;
		}

		z = (-(h*h)*f(x[n-1], y[j+1]) + g(b, y[j]) + w[n - 2][j] + lambda*w[n - 1][j + 1] + lambda*w[n - 1][j - 1]) / mu;
		if (sqrt((w[n - 1][j] - z)*(w[n-1][j]-z)) > Norm){
			Norm = sqrt((w[n - 1][j] - z)*(w[n-1][j]-z));
		}
		w[n - 1][j] = z;
	}

	z = (-(h*h)*f(x[1], y[1]) + g(a, y[1]) + lambda*g(x[1], c) + w[2][1] + lambda*w[1][2]) / mu;
	if (sqrt((w[1][1] - z)*(w[1][1]-z)) > Norm){
		Norm = sqrt((w[1][1] - z)*(w[1][1] - z));
	}
	w[1][1] = z;

	for (int i = 2; i <= n - 2; i++){
		z = (-(h*h)*f(x[i], y[1]) + lambda*g(x[i], c) + w[i - 1][1] + lambda*w[i][2] + w[i + 1][1]) / mu;
		if (sqrt((w[i][1] - z)*(w[i][1]-z)) > Norm){
			Norm = sqrt((w[i][1] - z)*(w[i][1] - z));
		}
		w[i][1] = z;
	}
	z = (-(h*h)*f(x[n - 1], y[1]) + g(b, y[1]) + lambda*g(x[n - 1], c) + w[n - 2][1] + lambda*w[n - 1][2]) / mu;
	if (sqrt((w[n - 1][1] - z)*(w[n-1][1])) > Norm){
		Norm = sqrt((w[n - 1][1] - z)*(w[n - 1][1]));
	}
	w[n - 1][1] = z;

	if (Norm <= TOL){
		for (int i = 1; i <= n - 1; i++){
			for (int j = 1; j <= m - 1; j++){
				printf("xi,yi,wij)=(%f,%f,%f)\n", x[i], y[j], w[i][j]);
				
			}
		}
	}
	l++;
}
return 0;}


double f(double x, double y){
	double r = 0;
	return r;
}

double g(double x, double y){
	double r;
	if (y == 1){
		r = x;
	}
	else if (x == 1)
	{
		r = y;
	}
	else{
		r = 0;
	}
	return r;
}