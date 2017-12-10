//Finite Difference 
#include<stdio.h>
#include<math.h>
#define pi 3.14159265359
#define N 2

double p(double t);
double q(double t);
double r(double t);
double y(double t);

int main(int argc,char**argv){
double a[N+1],b[N+1],c[N+1],d[N+1],l[N+1],u[N+1],z[N+1];

double A =0;
double B=pi/2;
double alpha=-0.3;
double beta=-0.1;
double h=(B - A) / N;
double x = A+h;
a[1]=2.0+(h*h)*q(x);
b[1]=-1.0+(h/2.0)*p(x);
d[1]=-(h*h)*r(x)+(1.0+(h/2.0)*p(x))*alpha;
for (int i = 2; i < N ; i++){
x=A+i*h;
a[i]=2.0+(h*h)*q(x);
b[i]=-1.0+(h/2.0)*p(x);
c[i] = -1.0 - (h / 2.0)*p(x);
d[i] = -(h*h)*r(x);
}
x=B-h;
a[N]=2.0+(h*h)*q(x);
c[N]=-1.0-(h/2.0)*p(x);
d[N]=-(h*h)*r(x)+(1.0-(h/2.0)*p(x))*beta;

l[1]=a[1];
u[1]=b[1]/a[1];
z[1]=d[1]/l[1];
for (int i=2;i<N;i++){
	l[i] = a[i] - c[i] * u[i - 1];
	u[i]=b[i]/l[i];
	z[i]=(d[i]-c[i]*z[i-1])/l[i];
}
l[N]=a[N]-c[N]*u[N-1];

z[N]=(d[N]-c[N]*z[N-1])/l[N];

double w[N+1]={0};
w[0]=alpha;
w[N]=beta;
w[N-1]=z[N-1];
for(int i = N-1;i>=1;i--){
w[i]=z[i]-u[i]*w[i+1];
}

for(int i=0;i<N;i++){
	x = A + i*h;

printf("(x,wi,yi)=(%lf,%lf,%lf)\n",x,w[i],y(x));}



return 0;}

double p(double t){
double y=1.0;
return y;
}
double q(double t){
double y=2.0;
return y;
}
double r(double t){
double y=cos(t);
return y;
}
double y(double t){
double f=(-sin(t)-3.0*cos(t))/10.0;
return f;
}



