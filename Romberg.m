n=8;
a=0;
b=1;
h=(b-a);
r(1,1)=(h/2)*(f(a)+f(b));
for i=2:n
    h=(h/2);
    sum=0;
    for k =1:2:(2.^(i-1)-1)
        sum=sum+f(a+k*h);
    end
    r(i,1)=(1/2)*r(i-1,1)+(sum)*h;
    for j=2:i
        r(i,j)=r(i,j-1)+((r(i,j-1)-r(i-1,j-1))/(4.^(j-1)-1));
    end
end

format long