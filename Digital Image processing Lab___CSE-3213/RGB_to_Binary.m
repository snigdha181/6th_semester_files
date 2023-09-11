clc;
clear all;
close all;

a=imread("images/tulips.jpg");
subplot(1,2,1)
imshow(a)
impixelinfo

x=im2bw(a);
subplot(1,2,2)
imshow(x)
impixelinfo