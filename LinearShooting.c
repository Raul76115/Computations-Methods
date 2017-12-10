#include<stdio.h>
#include<math.h> 
# define PI 3.14159265

double f1(int x, double w1, double w2){
	
	double y = w2 + 2 * w1 + cos(x);
	return y;
}

double f2(int x, double w1, double w2){

	double y = w2;
	return y;
}

double g1(int x, double w1, double w2){

	double y = w2 + 2 * w1;
	return y;
}

double g2(int x, double w1, double w2){

	double y = w2;
	return y;
}

int main(int argc, char**argv){
	int a = 0;
	int b = PI / 2; 
	double alpha = -0.3;
	double beta = -0.1;
	double h = PI / 4;
	int N = (b - a) / h;
	double	k[4][2];
	double K[4][2];
	double u1[3];
	u1[0] = alpha;
	double u2[3];
	u2[0] = 0;
	double v1[3];
	v1[0]= 0;
	double v2[3];
	v2[0]= 1;
	for (int i = 0; i < N; i++){

		int t = a + (double)i*h;
		k[0][0] = h*f1(t, u1[i], u2[i]);
		k[0][1] = h*f2(t, u1[i], u2[i]);
		k[1][0] = h*f1(t + .5*h, u1[i] + .5*k[0][0], u2[i] + .5*k[0][1]);
		k[1][1] = h*f2(t + .5*h, u1[i] + .5*k[0][0], u2[i] + .5*k[0][1]);
		k[2][0] = h*f1(t + .5*h, u1[i] + .5*k[1][0], u2[i] + .5*k[1][1]);
		k[2][1] = h*f2(t + .5*h, u1[i] + .5*k[1][0], u2[i] + .5*k[1][1]);
		k[3][0] = h*f1(t + h, u1[i] + k[2][0], u2[i] + k[2][1]);
		k[3][1] = h*f2(t + h, u1[i] + k[2][0], u2[i] + k[2][1]);
		u1[i+1] = u1[i] + (k[0][0] + 2 * k[1][0] + 2 * k[2][0] + k[3][0]) / 6.0;
		u2[i+1] = u2[i] + (k[0][1] + 2 * k[1][1] + 2 * k[2][1] + k[3][1]) / 6.0;

		K[0][0] = h*g1(t, v1[i], v2[i]);
		K[0][1] = h*g2(t, v1[i], v2[i]);
		K[1][0] = h*g1(t + .5*h, v1[i] + .5*K[0][0], v2[i] + .5*K[0][1]);
		K[1][1] = h*g2(t + .5*h, v1[i] + .5*K[0][0], v2[i] + .5*K[0][1]);
		K[2][0] = h*g1(t + .5*h, v1[i] + .5*K[1][0], v2[i] + .5*K[1][1]);
		K[2][1] = h*g2(t + .5*h, v1[i] + .5*K[1][0], v2[i] + .5*K[1][1]);
		K[3][0] = h*g1(t + h, v1[i] + K[2][0], v2[i] + K[2][1]);
		K[3][1] = h*g2(t + h, v1[i] + K[2][0], v2[i] + K[2][1]);
		v1[i+1] = v1[i] + (K[0][0] + 2 * K[1][0] + 2 * K[2][0] + K[3][0]) / 6.0;
		v2[i+1] = v2[i] + (K[0][1] + 2 * K[1][1] + 2 * K[2][1] + K[3][1]) / 6.0;
	
	}	
	double w1 = alpha;
	double w2 = (beta - u1[N]) / v1[N];
	printf("(a,w1,w2) = (%d,%lf,%lf)\n", a, w1, w2);
	double W1, W2,x;
	for (int i = 1; i <= N; i++){
		W1 = u1[i] + w2*v1[i];
		W2 = u2[i] + w2*v2[i];
		x = a + i*h;
		printf("(x,W1,W2)=(%lf,%lf,%lf)\n", x, W1, W2);
	}
	
	return 0;
}