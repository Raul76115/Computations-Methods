function [ Sum ] = Trapezoid_Uniform(a,b,n)
x=0;
h=(b-a)/n;
Sum = (f(a)+f(b))/2;
for i=0:n-1
    x=a+i*h;
    Sum=Sum +f(x);
end
Sum_Trapezoid=(Sum)*h;
Sum_Trapezoid
end

