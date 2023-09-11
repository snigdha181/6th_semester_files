clc;
clear all;
close all;
img=imread("images/Tulips.jpg");
r=img(:,:,1);
g=img(:,:,2);
b=img(:,:,3);

new(:,:,1)=r
new(:,:,2)=g
new(:,:,3)=b

imshow(new)

