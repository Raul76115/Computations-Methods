
dV=0;
for i=2:N-1
    for j=2:N-1
        if i<8 || i>14 && j<8 || j>14 && V(i,j)!=0
        V_new(i,j)=(V(i-1,j)+V(i+1,j)+V(i,j-1)+V(i,j+1))/4;
        dV=dV+abs(V(i,j)-V_new(i,j));
        end
    end
end

