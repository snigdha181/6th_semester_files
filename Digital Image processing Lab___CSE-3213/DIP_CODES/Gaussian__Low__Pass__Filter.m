clc;
clear all;
close all;

img = imread('cameraman.tif');

[M, N] = size(img);
f_img = fftshift(fft2(img));

C0 = 30; % Cut Off Frequency

[u, v] = meshgrid(-floor(M/2):floor((M-1)/2), -floor(N/2):floor((N-1)/2));
D = sqrt(u.^2 + v.^2);

g_filter = exp(-D.^2/(2*C0.^2));    % Gaussian Low Pass Filter
output_img = f_img .* g_filter;
output_img1 = ifft2(ifftshift(output_img));
output_img2 = mat2gray(abs(output_img1));

subplot(221);imshow(img);title("Original Image");
subplot(222);imshow(log(1 + abs(fftshift(g_filter))),[]);title("Filter Spectrum");
subplot(223);imshow(output_img2);title("Filtered Image");
subplot(224);surf(u, v, g_filter);title("3D Filter");

