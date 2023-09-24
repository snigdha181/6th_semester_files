% Spatial Filtering Page-156 Low Pass Filter
% Non Linear(Order Statistic) Smoothing Filter- (Median, Max, Min)
clc;
clear all;
close all;

img = imread('cameraman.tif');
w=[1,3,1;2,4,2;1,2,1];
[Mi,Ni] = size(img); % Input Image's Dimension
[m,n] = size(w);        % Mask Window's Dimension

f = padarray(img,[m-1 n-1]); % Padding the input image by m-1 & n-1 dimension
[M,N] = size(f);                   % Padded Image's Dimension
filtered_img = zeros(M,N);         % Output Image with New Dimension

sM = (m+1)/2;  % Starting Index of Mask 
sN = (n+1)/2;

eM = sM-1;     % Ending Index of Mask  E
eN = sN-1;

w = w';        % Converting Weight Matrix to Weight Vector
w1 = w(:);     % w1 is the weight vector

[r,c] = size(w1);

for i = sM:M-eM
    for j = sN:N-eN
        array = zeros(r,c);
        iw=1;
        for ii = i-eM:i+eM  
            for jj = j-eN:j+eN
                array(iw) = (w1(iw)*f(ii,jj));
                iw = iw+1;
            end
        end
        
        filtered_img(i, j) = mean(array);
    end
end
filtered_img = filtered_img(m:m+Mi-1, n:n+Ni-1);

subplot(121);imshow(img);title('Before Filtering');
subplot(122);imshow(uint8(filtered_img));title('After Weighted Average Filtering');
