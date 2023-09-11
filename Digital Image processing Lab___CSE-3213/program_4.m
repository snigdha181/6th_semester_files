clc;
clear all;
close all;
img1=imread("images/cameraman.tif");
for i=1:256
    for j=1:256
        m(i,j)=255-img1(i,j);
             
        end
end
    
imshow(m)