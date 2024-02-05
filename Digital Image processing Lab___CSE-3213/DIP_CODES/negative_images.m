clc;
clear all;
close all;
a=imread("cameraman.tif");
for i=1:256
    for j=1:256
        m(i,j)=255-a(i,j);
    end
end
subplot(121);imshow(a);title("Original Image");
subplot(122);imshow(m);title("Negative image");