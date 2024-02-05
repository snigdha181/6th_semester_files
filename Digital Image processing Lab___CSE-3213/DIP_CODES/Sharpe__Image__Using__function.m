clc;
clear all;
close all;

a=im2double(imread("images/moon.tif"));
lap=[-1 -1 -1; -1 8 -1;-1 -1 -1];
resp=imfilter(a,lap,'conv');
minR= min(resp(:));
maxR= max(resp(:));
resp= (resp-minR)/(maxR-minR);

sharp= a+resp;
minS= min(sharp(:));
maxS= max(sharp(:));
sharp= (sharp-minS)/(maxS-minS);
sharp= imadjust(sharp, [60/255 200/255], [0 1]);

subplot(131);imshow(a);title("Original Image");
subplot(132);imshow(resp);title("Laplacian Filter Image");
subplot(133);imshow(sharp);title("Sharpned Image");
