clc;
close all;
clear all;

% Read a Color Image
img = imread('images/Tulips.jpg');

% Separate each channel
% greenChannel = Img(:, :, 2);
% blueChannel = Img(:, :, 3);
% 
% % Combine channels
% Img = cat(3, redChannel, greenChannel, blueChannel);

% Apply Gaussian Low Pass Filter to each channel
[row,column] = size(img);
fc = 10;
p = round(row/2);
q = round(column/2);
R=img(:,:,1);
dR=im2double(R);
[row,column]=size(dR);
H = zeros(row,column);
for i=1:row
    for j=1:column
         d = (i-p).^2 + (j-q).^2;
        H(i,j) = exp(-d/2/fc/fc);
    end
end

% for i = 1:m
%     for j = 1:n
%         d = (i-p).^2 + (j-q).^2;
%         H(i,j) = exp(-d/2/fc/fc);
%     end
% end
A_F = fftshift(fft2(dR));
B = A_F.*H;
C = abs(ifft2(B));

% Display the results
subplot(221); imshow(img);title('Original Image');
subplot(222); imshow(H);title('2D view of H');
subplot(223); surf(H);title('3D view of H');
subplot(224); imshow(uint8(C));title('Image after applying GLPF');
