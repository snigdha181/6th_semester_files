clc;
clear all;
close all;
img1=imread("images/cameraman.tif");
for i=1:256
    for j=1:256
        if img1(i,j)>128
            m(i,j)=1;
        else
            m(i,j)=0;
        end
            
            
        end
    end
        
%imshow(m)

subplot(2,2,1)
imshow(img1);
title('cameraman orginal')

subplot(2,2,2)
imshow(m);
title('cameraman after edit')


