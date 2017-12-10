

format long
n=10;
h=5/n;
for k= 1 : n
    x(k)=k*h;
    y(k)=(1+(x(k))^2)^-1;
end
for i=1:n
    a(i)=y(i);
end

for j=2:n-1
    for i=n:-1:j+1
        a(i)=(a(i)-a(i-1))/(x(i)-x(i-j));
    end
end
t1=1;
t2=0;
pn_1=Eval(n,x,a,t1)
pn_0=Eval(n,x,a,t2)
h=1;
n=4;
d=zeros(n,n);

for i=1:n
    f1=Eval(n,x,a,t1+h);
    f2=Eval(n,x,a,t1-h);
    d(i,1)=(f1-f2)/(2.0*h);
    for j=2:i
        d(i,j)=d(i,j-1)+((d(i,j-1)-d(i-1,j-1))/(4.^(j-1)-1));
    end
    h=h/2.0;
end
d_1=d(n,n)
h=(t1-t2);
r(1,1)=(h/2)*(Eval(n,x,a,t2)+Eval(n,x,a,t1));
for i=2:n
    h=(h/2);
    sum=0;
    for k =1:2:(2.^(i-1)-1)
        sum=sum+Eval(n,x,a,t2+k*h);
    end
    r(i,1)=(1/2)*r(i-1,1)+(sum)*h;
    for j=2:i
        r(i,j)=r(i,j-1)+((r(i,j-1)-r(i-1,j-1))/(4.^(j-1)-1));
       
    end
end
r_0_1=r(n,n)   
    
    
    