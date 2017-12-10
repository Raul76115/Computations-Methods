#include<stdio.h>
#include<math.h>

double f(double t, double w){
	double y = -20*(w - t*t) + 2*t;
	return y;
}

double fy(double t, double w){
	double y = -20;
	return y;
}
int main(int argc, char**argv){
	double TOT = pow(10,-6);
	double a = 0;
	double b = 1; 
	double h = 0.1;
	int N = (b - a) / h;
	double t = a;
	double alpha = 1/3.0;
	double w = alpha;
	for (int i = 1; i <= N; i++){
		
		double k1 = w + h*f(t, w);
		double w0 = k1;
		int j = 1;
		int FLAG = 0;
		while (FLAG == 0){
			
			w = w0 - ((w0 - h*f(t + h, w0)-k1) / (1 - h*fy(t + h, w0)));
			if (abs(w - w0) < TOT){
				FLAG = 1;
			}
			else {
				j = j + 1;
				w0 = w;
			}

		}
		t = a + i*h;
		printf("(t,y) = (%f,%f)\n", t, w);
		
	}

	return 0;
}