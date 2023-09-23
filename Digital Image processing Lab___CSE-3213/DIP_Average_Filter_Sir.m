clc;
clear all;
close all;
row = 2;
col = 2;
img = imread('cameraman.tif');

w = ones(3, 3) / 9; % 3x3 Box Average Mask

[Mi, Ni] = size(img); % Input Image's Dimension
[m, n] = size(w); % Mask Window's Dimension

f = padarray(img, [m-1, n-1]); % Padding the input image by m-1 & n-1 dimension
[M, N] = size(f); % Padded Image's Dimension
filtered_img = zeros(M, N); % Output Image with New Dimension

sM = (m+1)/2; % Starting Index of Mask
sN = (n+1)/2;

eM = sM-1; % Ending Index of Mask E
eN = sN-1;

for i = sM:M-eM
    for j = sN:N-eN
        sum = 0;
        iw = 1;
        for ii = i-eM:i+eM
            for jj = j-eN:j+eN
                sum = sum + f(ii, jj) * w(iw);
                iw = iw + 1;
            end
        end
        filtered_img(i, j) = sum; % Assigning the average value to the middle position of the window
    end
end
filtered_img = filtered_img(m:m+Mi-1, n:n+Ni-1); % Cropping Image to Previous Dimension

subplot(121);
imshow(img);
title('Before Filtering');

subplot(122);
imshow(uint8(filtered_img))
title('After Average Filtering');
