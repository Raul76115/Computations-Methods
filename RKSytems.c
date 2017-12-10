//Runge-Kutta For Systems

#include <stdio.h>
#include <math.h>
double f1(double t,double u1,double u2){
	double y = u2;
return y;
}
double f2(double t,double u1,double u2){
	double y= t*exp(t)-t+2*u2-u1;
return y;
}

int main(int argc, char**argv){

double a = 0.0;
double b = 1.0;
double h = 0.1;
int N = (b-a)/h;
double alpha1 = 0;
double alpha2 = 0;
double t = a;
double w1 = alpha1;
double w2 = alpha2;
printf("(t,w1,w2) = (%f,%f,%f)\n", t,w1,w2);
double k[4][2];
for(int i=1; i<=N;i++){
	k[0][0]=h*f1(t,w1,w2);
	k[0][1]=h*f2(t,w1,w2);
	k[1][0]=h*f1(t+.5*h,w1+.5*k[0][0],w2+.5*k[0][1]);
	k[1][1]=h*f2(t+.5*h,w1+.5*k[0][0],w2+.5*k[0][1]);
	k[2][0]=h*f1(t+.5*h,w1+.5*k[1][0],w2+.5*k[1][1]);
	k[2][1]=h*f2(t+.5*h,w1+.5*k[1][0],w2+.5*k[1][1]);
	k[3][0]=h*f1(t+h,w1+k[2][0],w2+k[2][1]);
	k[3][1]=h*f2(t+h,w1+k[2][0],w2+k[2][1]);
	w1=w1+(k[0][0]+2*k[1][0]+2*k[2][0]+k[3][0])/6.0;
	w2=w2+(k[0][1]+2*k[1][1]+2*k[2][1]+k[3][1])/6.0;
	t = a+(double)i*h;
	printf("(t,w1,w2) = (%f,%f,%f)\n", t,w1,w2);
}
return 0;
}