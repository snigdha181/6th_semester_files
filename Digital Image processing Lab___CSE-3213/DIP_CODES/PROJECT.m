% Separate each channel of a color image. Then apply gaussian 
% low pass Filter on each channel then combine those channels 
% and display the final out.

clc;
close all;
clear all;

% Read a Color Image
Img = imread('images/Tulips.jpg');

% Separate each channel
redChannel = Img(:, :, 1);
greenChannel = Img(:, :, 2);
blueChannel = Img(:, :, 3);

% Combine channels
Img = cat(3, redChannel, greenChannel, blueChannel);

% Apply Gaussian Low Pass Filter to each channel
sigma = 1.15;  % Standard Deviation
sz = 3;        % Window size
[x, y] = meshgrid(-sz:sz, -sz:sz);
M = size(x, 1) - 1;
N = size(y, 1) - 1;

% Create Gaussian Kernel
Exp_comp = -(x.^2 + y.^2) / (2 * sigma * sigma);
Kernel = exp(Exp_comp) / (2 * pi * sigma * sigma);

% Initialize filtered channels
filteredRed = zeros(size(redChannel));
filteredGreen = zeros(size(greenChannel));
filteredBlue = zeros(size(blueChannel));

% Pad the channels with zeros
r = padarray(double(redChannel), [sz, sz]);
g = padarray(double(greenChannel), [sz, sz]);
b = padarray(double(blueChannel), [sz, sz]);

% Convolution for each channel
for i = 1:size(r, 1) - M
    for j = 1:size(r, 2) - N
        % Apply Gaussian filter
        TempRed = r(i:i+M, j:j+M) .* Kernel;
        TempGreen = g(i:i+M, j:j+M) .* Kernel;
        TempBlue = b(i:i+M, j:j+M) .* Kernel;
        
        % Sum the values
        filteredRed(i, j) = sum(TempRed(:));
        filteredGreen(i, j) = sum(TempGreen(:));
        filteredBlue(i, j) = sum(TempBlue(:));
    end
end

% Combine filtered channels
filteredImg = cat(3, uint8(filteredRed), uint8(filteredGreen), uint8(filteredBlue));

% Display the results
subplot(331); imshow(Img);title('Original Image');

subplot(332); imshow(redChannel);title('Red Channel Image before filtering');
subplot(335); imshow(greenChannel);title('Green Channel Image before filtering');
subplot(338); imshow(blueChannel);title('Blue Channel Image before filtering');
subplot(334); imshow(Img);title('Combine image before filtering');

subplot(333); imshow(uint8(filteredRed));title('Red channel image after filtering');
subplot(336); imshow(uint8(filteredGreen));title('Green channel image after filtering');
subplot(339); imshow(uint8(filteredBlue));title('Blue channel image after filtering');

subplot(337); imshow(filteredImg);title('Combine image after filtering');