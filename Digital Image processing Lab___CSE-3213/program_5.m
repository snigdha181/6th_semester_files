clc;
clear all;
close all;
img1=imread("images/cameraman.tif");
bw=im2bw(img1)
    
subplot(2,2,1)
imshow(img1);
title('cameraman orginal')

subplot(2,2,2)
imshow(bw);
title('cameraman after edit')


