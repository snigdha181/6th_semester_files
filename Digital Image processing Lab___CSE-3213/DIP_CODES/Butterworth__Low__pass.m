clc; 
clear all; 
close all;

img = imread('cameraman.tif');

[M, N] = size(img);
f_img = fftshift(fft2(img));

C0 = 60; % Cut Off Frequency
n = 2;   % Order of the filter

[u, v] = meshgrid(-floor(M/2):floor(M-1)/2, -floor(N/2):floor(N-1)/2);
D = sqrt(u.^2 + v.^2);

butterworth_filter = 1 ./ (1 + (D./C0).^(2*n));    %low pass 
output_img = f_img .* butterworth_filter;
output_img1 = ifft2(output_img);
output_img2 = mat2gray(abs(output_img1));

subplot(221);imshow(img);title("Original Image");
subplot(222);imshow(butterworth_filter);title("Radius Image");
subplot(223);imshow(output_img2);title("BLF Image");
subplot(224);surf(butterworth_filter);title("3D Image");
