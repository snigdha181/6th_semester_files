clc;
clear all;
close all;
i=imread("images/Tulips.jpg");
I=im2double(i);
r=size(I,1);
c=size(I,2);

for i=1:r
    for j=1:c
        I1(i,j)=I(i,j)^.5;
    end
end

for i=1:r
    for j=1:c
        I2(i,j)=I(i,j)^.1;
    end
end

for i=1:r
    for j=1:c
        I3(i,j)=I(i,j)^1.667;
    end
end
subplot(221);imshow(I);title("Original Image");
subplot(222);imshow(I1);title("Power law 0.5");
subplot(223);imshow(I2);title("Power law 0.1");
subplot(224);imshow(I3);title("Power law 1.667");