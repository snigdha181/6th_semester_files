clc;
clear all;
close all;
a=imread("images/Tulips.jpg");
b=rgb2gray(a);
a=double(b);
[r,c]=size(a);
for i=1:r
    for j=1:c
        i1(i,j)=bitand(a(i,j),1);
        i2(i,j)=bitand(a(i,j),2);
        i3(i,j)=bitand(a(i,j),4);
        i4(i,j)=bitand(a(i,j),8);
        i5(i,j)=bitand(a(i,j),16);
        i6(i,j)=bitand(a(i,j),32);
        i7(i,j)=bitand(a(i,j),64);
        i8(i,j)=bitand(a(i,j),128);
    end
end
subplot(241);imshow(i1);title("Bitplane 1");
subplot(242);imshow(i2);title("Bitplane 2");
subplot(243);imshow(i3);title("Bitplane 3");
subplot(244);imshow(i4);title("Bitplane 4");
subplot(245);imshow(i5);title("Bitplane 5");
subplot(246);imshow(i6);title("Bitplane 6");
subplot(247);imshow(i7);title("Bitplane 7");
subplot(248);imshow(i8);title("Bitplane 8");
