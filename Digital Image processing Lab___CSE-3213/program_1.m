clc;
clear all;
close all;
img1=imread("images/cameraman.tif");
img2=imread("images/concordorthophoto.png");
img3=imread("images/eight.tif");
img4=imread("images/koala_gray.jpg");
%plot(img);
subplot(2,2,1)
imshow(img1);
title('cameraman')
subplot(2,2,2)
imshow(img2);
title('concordorthophoto')
subplot(2,2,3)
imshow(img3);
title('eight')
subplot(2,2,4)
imshow(img4);
title('koalagray') 