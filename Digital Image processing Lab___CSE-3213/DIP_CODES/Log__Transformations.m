clc;
clear all;
close all;
i1=imread("images/circuit.tif");
I=im2double(i1);
r=size(I,1);
c=size(I,2);
for i=1:r
    for j=1:c
        s(i,j) = log(1 + I(i,j));
    end
end
subplot(121);imshow(I);title("Original Image");impixelinfo;
subplot(122);imshow(s);title("Log Transformation Image");impixelinfo;