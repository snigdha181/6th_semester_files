clc;
clear all;
close all;
img1=imread("images/cameraman.tif");
k=0;
for i=1:256
    for j=1:256
        if (img1(i,j)==225)
         k=k+1
        end
            
            
        end
    end
        
%imshow(img1)