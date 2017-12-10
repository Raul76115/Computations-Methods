#include<stdio.h>
#include<math.h>

#define T 1
#define m 5
#define N 10
#define pi 3.14159265359

double f(double x){
	return sin(2 * pi*x);

}

int main(int argc,char**argv){
	double l[m] = { 0 }, u[m] = { 0 }, z[m] = { 0 }, w[m] = { 0 };
	double t;

double a = 1.0;
double h=0.4;
double k=0.1;
double lambda=(a*a)*(k/(h*h));


for(int i=1;i<=m-1;i++){
	w[i] = f(i*h);
}

l[1]=1+2*lambda;
u[1]=-lambda/l[1];

for(int i=2;i<=m-2;i++){
l[i]=1+2*lambda+lambda*u[i-1];
u[i]=-lambda/l[i];
}

l[m-1]=1+2*lambda+lambda*u[m-2];

for (int j=1;j<=N;j++){
t=j*k;
z[1]=w[1]/l[1];

for(int i=2;i<=m-1;i++){
z[i]=(w[i]+lambda*z[i-1])/l[i];}
w[m-1]=z[m-1];

for(int i=m-2;i>=1;i--){
w[i]=z[i]-u[i]*w[i+1];}
printf("t=%f\n",t);
for(int i =1;i<=m-1;i++){
double x=i*h;
printf("(x,wi)=(%f,%f)\n",x,w[i]);
}
}



return 0;}