clc;
clear all;
close all;

img = imread("images/moon.tif");

g = [0 1 0; 1 -4 1; 0 1 0];

lap = imfilter(img, g);

sharpened_image = img - lap;
subplot(131);imshow(img);title('Original Image');
subplot(132);imshow(lap);title('Laplacian Filtered Image');
subplot(133);imshow(sharpened_image);title('Sharpened Image');