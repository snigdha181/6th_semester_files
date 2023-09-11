clc;
clear all;
close all;
img=imread("images/Tulips.jpg");
r=img(:,:,1);
g=img(:,:,2);
b=img(:,:,3);
%imshow(img)

subplot(2,2,1)
imshow(r);
title('r')

subplot(2,2,2)
imshow(g);
title('g')

subplot(2,2,3)
imshow(b);
title('b')

subplot(2,2,4)
imshow(img);
title('orginal')

