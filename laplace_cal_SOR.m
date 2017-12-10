DV=1*10^-5;
initialize_V;
update_SOR;
for i=2:N-1
    for j=2:N-1
       V(i,j)=V_new(i,j);
    end
end
while DV<dV
    update_SOR;
    for i=2:N-1
    for j=2:N-1
       V(i,j)=V_new(i,j);
    end
    end
end

for i=2:N-1
    for j=2:N-1
    Ex(i,j)=-(V(i+1,j)-V(i-1,j))/(2*.1);
    Ey(i,j)=-(V(i,j+1)-V(i,j-1))/(2*.1);
    end
end