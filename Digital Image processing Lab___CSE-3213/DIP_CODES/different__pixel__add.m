clc;
clear all;
close all;
i1=imread("cameraman.tif");
add_10=imadd(i1,10);
add_50=imadd(i1,50);
add_100=imadd(i1,100);
add_200=imadd(i1,200);
add_300=imadd(i1,300);
subplot(231);imshow(i1);title("Original Image");
subplot(232);imshow(add_10);title("10 pixels");
subplot(233);imshow(add_50);title("50 pixels");
subplot(234);imshow(add_100);title("100 pixels");
subplot(235);imshow(add_200);title("200 pixels");
subplot(236);imshow(add_300);title("300 pixels");