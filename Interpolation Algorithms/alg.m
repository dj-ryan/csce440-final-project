%Bethany Krull
%440 Numerical Analysis
%Final Project
%alg.m

clear("SSE","x","sumY","size","rSqd","predictedY","inc","i","errorSamp","equ","dataT","data","avgY","actualY","SST");

dataT = readtable('data.xlsx');
data = table2array(dataT);
size = length(data);
%A = zeros(size-1,1);
%y = zeros(size-1,1);

syms x;
inc = 1000;
predictedY = 0;
sumY = 0;
errorSamp = 2;
SSE = 0;
SST = 0;

for i = 1:inc:size-inc
    sumY = sumY + data(i,3);
end
avgY = sumY/(size/inc);

for i = 1:inc:size-inc
    equ = data(i,3) + ((data(i+inc,3) - data(i,3))/(data(i+inc,1) - data(i,1)))*(x - data(i,1));
    
    
    predictedY = subs(equ,x,(data(i+inc/errorSamp,1)));
    actualY = data((i+inc/errorSamp),3);
    SSE = SSE + ((actualY - predictedY)^2);
    disp(actualY - predictedY);

    SST = SST + ((actualY - avgY)^2);
    disp(actualY - avgY);

    %disp(equ);
    %integer = subs(equ,x,0);
    %y(i,1) = integer;             %Ax + y
    %A(i,1) = subs((equ - integer),x,1);
    
    fplot(equ,[data(i,1),data(i+inc,1)]);
    hold on;
end
hold off;
shg;



disp(SSE);
disp(SST);

rSqd = 1 - (SSE/SST);
disp(eval(rSqd));



