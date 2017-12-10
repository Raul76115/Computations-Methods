alpha=2/(1+pi);
dV=0;
for i=2:N-1
    for j=2:N-1
        if i<8 || i>14 && j<8 || j>14 && V(i,j)!=0
        V_GS(i,j)=(V_GS(i-1,j)+V(i+1,j)+V_GS(i,j-1)+V(i,j+1))/4;
        dv(i,j)=V_GS(i,j)-V(i,j);
        V_new(i,j)=alpha*dv(i,j)+V(i,j);
        dV=dV+abs(V(i,j)-V_new(i,j));
        end
    end
end

