#include<stdio.h>
#include<math.h>
 
#define N 20
#define m 10
#define pi 3.14159265359
 
double f(double x){
	double c;
 if(x==0||x==pi){
 	c=0;
 }
 else{
 c=sin(x);
}
return c;
}
 
double g(double x){
	return 0;
}
 
int main(int argc,char**argv){
double h=pi/10.0;
double k=0.05;
double lambda=k/h;
double l = pi;
double w[m+1][N+1]={0};
w[0][0]=f(0);
w[m][0]=f(l);
int i,j;
for (i=1;i<=m-1;i++){
w[i][0]=f(i*h);
w[i][1]=(1-(lambda*lambda))*f(i*h)+.5*(lambda*lambda)*(f((i+1)*h)+f((i-1)*h))+k*g(i*h);
}
for ( j=1;j<=N-1;j++){
	for ( i =1;i<=m-1;i++){
		w[i][j+1]=2.0*(1-(lambda*lambda))*w[i][j]+(lambda*lambda)*(w[i+1][j]+w[i-1][j])-w[i][j-1];
}}
for (j=0;j<=N;j++){
double t=j*k;
for ( i =0;i<=m;i++){
double x=i*h;
printf("(x,t,wij,u(x,t))=(%f,%f,%f,%f)\n",x,t,w[i][j],cos(t)*sin(x));
}}
return 0;}