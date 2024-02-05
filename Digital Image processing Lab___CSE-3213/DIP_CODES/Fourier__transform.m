clc;
clear all;
close all;
warning off;

a=imread("images/letter.png");

f1=fftshift(fft2(a));

f2=log(1+abs(f1));
fm=max(f2(:));
f2=im2uint8(f2/fm);

f3=mat2gray(log(1+abs(f1)));

subplot(221);imshow(a);title("Original Image");
subplot(222);imshow(f1);title("Fourier Transformed Image With shifting");
subplot(223);imshow(f2);title("Fourier Transformed Image Manual Scaling");
subplot(224);imshow(f3);title("Fourier Transformed Image Automatic Scaling");