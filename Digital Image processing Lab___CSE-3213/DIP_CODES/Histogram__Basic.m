clc;
clear all;
close all;
Img = imread("images/cameraman.tif");
%b = rgb2gray(Img);

subplot(2,2,1);
imshow(Img);
subplot(2,2,2);

 imhist(Img);
b = imhist(Img);
arr = zeros(1,256);
[r,c] = size(Img);
%plot(b);
for i=1:r
    for j=1:c
        arr(Img(i,j))=arr(Img(i,j))+1;
    end
end
disp(arr);
subplot(2,2,3);
bar(b);
%subplot(2,2,2)
