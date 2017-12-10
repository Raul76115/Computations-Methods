#include<stdio.h>
#include<math.h>
# define N 9
# define M 10

double f(double x, double w, double t);
double g(double x, double w, double t);
double H(double x, double w, double t);
double y(double x);

int main(int argc,char**argv){
double A=1;
double B=2;
double alpha=0.5;
double beta=1/3.0;
double h = (B - A) / (N+1);
double w[N+2];
w[0]=alpha;
w[N+1]=beta;
for(int i=1;i<N+1;i++){
w[i]=alpha+i*((beta-alpha)/((B-A)*h));
}
int k=1;
double a[N+1],b[N+1],c[N+1],d[N+1];
while (k<=M){
double x=A+h;
double t=(w[2]-alpha)/(2.0*h);
a[1]=2.0+(h*h)*g(x,w[1],t);
b[1]=-1.0+(h/2.0)*H(x,w[1],t);
d[1]=-(2*w[1]-w[2]-alpha+(h*h)*f(x,w[1],t));
for (int i=2;i<N;i++){
x=A+i*h;
t=(w[i+1]-w[i-1])/(2.0*h);
a[i]=2.0+(h*h)*g(x,w[i],t);
b[i]=-1.0+(h/2.0)*H(x,w[i],t);
c[i]=-1.0-(h/2.0)*H(x,w[i],t);
d[i]=-(2.0*w[i]-w[i+1]-w[i-1]+(h*h)*f(x,w[i],t));
}
x=B-h;
t=(beta-w[N-1])/(2.0*h);
a[N]=2.0+(h*h)*g(x,w[N],t);
b[N]=-1.0+(h/2.0)*H(x,w[N],t);
c[N] = -1.0 - (h / 2.0)*H(x, w[N], t);
d[N]=-(2.0*w[N]-w[N-1]-beta+(h*h)*f(x,w[N],t));

double l[N+1],u[N+1],z[N+1];
l[1]=a[1];
u[1]=b[1]/a[1];
z[1] = d[1] / l[1];
for (int i =2;i<=N;i++){
l[i]=a[i]-c[i]*u[i-1];
u[i]=b[i]/l[i];
z[i]=(d[i]-c[i]*z[i-1])/l[i];
}
l[N]=a[N]-c[N]*u[N-1];
z[N]=(d[N]-c[N]*z[N-1])/l[N];

double v[N+1];
v[N]=z[N];
w[N]=w[N]+v[N];
for (int i =N-1;i>=1;i--){
v[i]=z[i]-u[i]*v[i+1];
w[i] = w[i] + v[i];
}
double TOL=pow(10.0,-4.0);
double sum = 0;
for (int i = 1; i<=N; i++){
	sum = sum + (v[i] * v[i]);
}
double norm = sqrt(sum);

if(norm<=TOL){
for (int i=0;i<=N+1;i++){
x=A+i*h;
printf("(x,wi,yi)=(%lf,%lf,%lf)\n",x,w[i],y(x));
}

}
k++;

}
return 0;}


double f(double x,double w,double t){
	double y = (w*w*w) - w*t;
return y;
}

double g(double x,double w,double t){
	double y = 3.0*(w*w)-t;
return y;}

double H(double x,double w,double t){
	double y = -w;
return y;
}

double y(double x){
	double f = 1.0 / (x + 1.0);
	return f;
}