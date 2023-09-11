clc;
clear all;
close all;

i = imread("eight.tif");
m=0:256;
ih = histeq(i,m);
subplot(231);imshow(i);title("Original Image");
subplot(232);imshow(ih);title("Histogram image");
subplot(233);plot(m);title("Plot of matching value range");
subplot(234);imhist(i);title("Histogram of original image");
subplot(235);imhist(ih);title("Histogram of match image");