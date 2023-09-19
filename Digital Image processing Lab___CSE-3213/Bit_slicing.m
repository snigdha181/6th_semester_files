clc;
close all;
clear all;

img=imread("Image for DIP Lab\Tulips.jpg");
[r,c]=size(img);
for i=1:r
    for j=1:c
        i1(i,j)=bitand(img(i,j),1);
        i2(i,j)=bitand(img(i,j),2);
        i3(i,j)=bitand(img(i,j),4);
        i4(i,j)=bitand(img(i,j),8);
        i5(i,j)=bitand(img(i,j),16);
        i6(i,j)=bitand(img(i,j),32);
        i7(i,j)=bitand(img(i,j),64);
        i8(i,j)=bitand(img(i,j),128);
    end
end
subplot(241);imshow(i1);title("Image 1");
subplot(242);imshow(i2);title("Image 2");
subplot(243);imshow(i3);title("Image 3");
subplot(244);imshow(i4);title("Image 4");
subplot(245);imshow(i5);title("Image 5");
subplot(246);imshow(i6);title("Image 6");
subplot(247);imshow(i7);title("Image 7");
subplot(248);imshow(i8);title("Image 8");