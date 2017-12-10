#include<stdio.h>
#include<math.h>

#define m 5
#define N 10
#define pi 3.14159265359

double f(double x){
	return sin(2.0 * pi*x);
}

int main(int argc,char**argv){
double w[m] = { 0 }, z[m] = { 0 };
double h=0.4;
double k=0.1;
double a = 1.0;
double lambda=(a*a)*k/(h*h);

for (int i=1 ;i <= (m-1) ;i++){
w[i]=f(i*h);}

double l[m] = { 0 }, u[m] = { 0 };
l[0] = 2.0;
l[1]=1+lambda;
u[1]=(-lambda)/(2.0*l[1]);

for (int i = 2; i <= (m - 2); i++){
l[i]=1+lambda+lambda*u[i-1]*.5;
u[i]=.5*(-lambda/l[i]);}

l[m-1]=1+lambda+lambda*u[m-2]*.5;

for(int j=1;j<=N;j++){
double t=j*k;
z[1]=((1-lambda)*w[1]+(.5*lambda)*w[2])/l[1];
for(int i=2;i<=(m-1);i++){
z[i]=((1-lambda)*w[i]+(.5*lambda)*(w[i+1]+w[i-1]+z[i-1]))/l[i];
}
w[m-1]=z[m-1];

for (int i=(m-2);i>=1;i--){
w[i]=z[i]-(u[i]*w[i+1]);
}
printf("t=%f\n",t);
for(int i=1;i<=m-1;i++){
double x=i*h;
printf("(x,wi)=(%f,%.9f)\n",x,w[i]);
}

}

return 0;}