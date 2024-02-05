clc;
clear all;
close all;

a=imread("cameraman.tif");
[m,n]=size(a);
fi=fftshift(fft2(a));
c=50;
[u,v]=meshgrid(-floor(m/2):floor(m-1)/2, -floor(n/2):floor(n-1)/2);
z=sqrt(u.^2+v.^2);
ideal_filter = z>c;
o1=fi*ideal_filter;
o2=ifft2(o1);
o3=mat2gray(abs(o2));

subplot(221);imshow(a);title("Original Image");
subplot(222);imshow(ideal_filter);title("Radius Image");
subplot(223);surf(z);title("3D Image");
subplot(224);imshow(o3);title("Ideal High Pass Filtering Image");