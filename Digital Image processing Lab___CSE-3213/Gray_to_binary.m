clc;
clear all;
close all;

a=imread("images/concordorthophoto.png");
subplot(121);imshow(a);impixelinfo;

x=im2bw(a);
subplot(122);imshow(x);impixelinfo;