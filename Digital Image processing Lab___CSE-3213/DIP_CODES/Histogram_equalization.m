clc;
clear all;
close all;

a=imread("eight.tif");
r=size(a,1);               %row
c=size(a,2);               %column
ah=uint8(zeros(r,c));      %final value
n=r*c;                     %total number of pixels
f=zeros(256,1);            %frequency(variable....intensity levels 256)
pdf=zeros(256,1);
cdf=zeros(256,1);
cum=zeros(256,1);
out=zeros(256,1);

for i=1:r
    for j=1:c
        value=a(i,j);
        f(value+1)=f(value+1)+1;
        pdf(value+1)=f(value+1)/n;
    end
end

sum=0;L=255;
for i=1:size(pdf)
    sum=sum+f(i);
    cum(i)=sum;
    cdf(i)=cum(i)/n;
    out(i)=round(cdf(i)*L);
end

for i=1:r
    for j=1:c
        ah(i,j)=out(a(i,j)+1);
    end
end
subplot(121);imshow(a);title("Original Image");

he=histeq(a);
subplot(122);imshow(he);title("Histogram Equalization Image");