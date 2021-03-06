

//Euler's Method
#include<stdio.h>
float f(float t, float w){
	float y = w-(t*t)+1;
return y;
}

int main(int argc, char**argv){

float a = 0;
float b = 2;
float alpha = 0.5;
float h = 0.5;
int N = (b-a)/h;
float t=a;
float w = alpha;
printf("(t,w) = (%f,%f)\n", t,w);
for(int i = 1; i<=N; i++){
	w=w+h*f(t,w);
	t = a + i*h;
	printf("(t,w) = (%f,%f)\n", t,w);
}
return 0;
}