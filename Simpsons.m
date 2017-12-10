function [ Sum ] = Simpsons(a,b,n)
x=0;
h=(b-a)/n;
Sum = f(a)+f(b);
Sum1=0;
Sum2=0;
for i=1:n-1
    x=a+i*h;
    if mod(i,2)==0
        Sum2=Sum2+f(x);
    else
    Sum1=Sum1+f(x);
    end
end
Sum_Simpsons=h*(Sum+2*Sum2+4*Sum1)/3;
Sum_Simpsons
end

