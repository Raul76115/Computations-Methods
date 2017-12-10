
//Runge-Kutta Fourth Order

#include<stdio.h>
double f(double t, double w){
	double y=w-(t*t)+1;
return y;
}

int main(int argc, char**argv){

double a=0;
double b=2;
double alpha=0.5;
double h=0.5;
double N = (b-a)/h;
double t=a;
double w= alpha;
printf("(t,w) = (%f,%f)\n", t,w);
double  k1,k2,k3,k4;
for(int i = 1;i<=N;i++){
	k1= h*f(t,w);
	k2= h*f((t+.5*h),w+.5*k1);
	k3= h*f(t+.5*h,w+.5*k2);
	k4= h*f(t+h,w+.5*k3);
	w=w+((k1+2*k2+2*k3+k4)/6.0);
	t=a+(double)i*h;
printf("(t,w) = (%f,%f)\n", t,w);
}
return 0 ;
}