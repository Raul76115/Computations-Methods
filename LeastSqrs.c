//Linear Least Squares
#include<stdio.h>
#include<math.h>
#define N 2
double nth(double x,int n){
double s=1;
for (int i=1;i<=n;i++){
s=s*x;
}
return s;
}


int main(){

double x[10]={4.0 ,4.2 ,4.5 ,4.7 ,5.1 ,5.5, 5.9 ,6.3, 6.8 ,7.1};
double y[10]={102.56, 113.18, 130.11, 142.05, 167.53, 195.14, 224.87, 256.73 ,299.50 ,326.72};
double a[N+1]={0};
double sum[N+1][N+1]={0};
int k=0;
double b[N+1]={0};
while(k<N+1){
for(int i=0;i<10;i++){
sum[k][0]=sum[k][0]+ nth(x[i],k);
sum[k][1]=sum[k][1]+ nth(x[i],k+1);
sum[k][2]=sum[k][2]+ nth(x[i],k+2);
b[k]=b[k]+y[i]*nth(x[i],k);
}
k++;}

for (int k=0;k<N;k++){
	for(int i=k+1;i<N+1;i++){
double xmult = sum[i][k]/sum[k][k];
sum[i][k]=xmult;
	for(int j=k+1;j<N+1;j++){
sum[i][j]=sum[i][j]-xmult*sum[k][j];
}
b[i]=b[i]-xmult*b[k];
}}
a[N]=b[N]/sum[N][N];
for(int i = N;i>=0;i--){
double z=b[i];	
	for (int j=i+1;j<N+1;j++){
z=z-sum[i][j]*a[j];
}
a[i]=z/sum[i][i];}

for (int i=0;i<N+1;i++){
printf("a%d=%f\n",i, a[i]);

}

return 0;}