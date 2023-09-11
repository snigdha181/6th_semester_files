clc;
clear all;
close all;

a=imread("images/tulips.jpg");
subplot(1,2,1)
imshow(a)
impixelinfo

x=rgb2gray(a);
subplot(1,2,2)
imshow(x)
impixelinfo