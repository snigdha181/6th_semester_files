clc;
clear all;
close all;
i1=imread("cameraman.tif");
b=im2bw(i1);
for i=1:256
    for j=1:256
        if i1(i,j)>128
            m(i,j)=1;
        else
            m(i,j)=0;
        end
    end
end
subplot(131);imshow(i1);title("Original Image");
subplot(132);imshow(b);title("B&W using function");
subplot(133);imshow(m);title("B&W without function");