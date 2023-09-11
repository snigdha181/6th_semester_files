clc;
clear all;
close all;

i1=imread("images/ss.jpg");

add_10 = imadd(i1,10);
add_50 = imadd(i1,50);
add_100 = imadd(i1,100);
add_200 = imadd(i1,200);
add_300 = imadd(i1,300);

subplot(2,3,1),imshow(i1);title("Original Photo");

subplot(2,3,2),imshow(add_10);title("Add_10 Photo");
subplot(2,3,3),imshow(add_50);title("add_50 Photo");
subplot(2,3,4),imshow(add_100);title("add_100 Photo");
subplot(2,3,5),imshow(add_200);title("add_200 Photo");
subplot(2,3,6),imshow(add_300);title("add_300 Photo");





%i2=imread("images/concordorthophoto.png");
%subplot(2,3,2)
%imshow(i2)


%i3=imread("images/eight.tif");
%subplot(2,3,3)
%imshow(i3)

%i4=imread("images/Jellyfish.jpg");
%subplot(2,3,4)
%imshow(i4)

%i5=imread("images/Koala.jpg");
%subplot(2,3,5)
%imshow(i5)

