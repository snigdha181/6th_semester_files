clc;
clear all;
close all;
i1=imread("images/Tulips.jpg");
i2=im2bw(i1);
i3=rgb2gray(i1);
subplot(131);imshow(i1);title("Original image");
subplot(132);imshow(i2);title("Black & White image");
subplot(133);imshow(i3);title("Gray image");