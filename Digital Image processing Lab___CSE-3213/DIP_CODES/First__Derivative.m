clc;
close all;
clear all;

I = imread('cameraman.tif');

% Calculate the horizontal derivative
Ix = [-1 0 1];
Ix = Ix / 3;
Ix_filtered = conv2(I, Ix, 'same');

% Calculate the vertical derivative
Iy = [-1; 0; 1];
Iy = Iy / 3;
Iy_filtered = conv2(I, Iy, 'same');

% Calculate the magnitude of the gradient
G = sqrt(Ix_filtered.^2 + Iy_filtered.^2);

% Show the original image and the gradient magnitude image

subplot(121);imshow(I);title('Original image');
subplot(122);imshow(G);title('Gradient magnitude image');