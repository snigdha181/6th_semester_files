clc;
clear all;
close all;
a=imread("images/cameraman.tif");
I=im2bw(a);
b=imbinarize(a);
c=0;
for i=1:256
    for j=1:256
        if b(i,j)==1
            c=c+1;
        end
    end
end
subplot(131);imshow(a);title("Original Image");
subplot(132);imshow(I);title("Black and White Image");
subplot(133);imshow(b);title("Binary Image");