clc;
clear all;
close all;
A = imread('cameraman.tif');

subplot(211),imshow(A),title('ORIGINAL IMAGE');

%PREALLOCATE THE OUTPUT MATRIX
B=zeros(size(A));

%PAD THE MATRIX A WITH ZEROS
modifyA=padarray(A,[1 1]);

        x=[1:3]';
        y=[1:3]';
       
for i= 1:size(modifyA,1)-2
    for j=1:size(modifyA,2)-2
      
       %VECTORIZED METHOD 
       window=reshape(modifyA(i+x-1,j+y-1),[],1);

       %FIND THE MINIMUM VALUE IN THE SELECTED WINDOW
        B(i,j)=min(window);

    end
end

%CONVERT THE OUTPUT MATRIX TO 0-255 RANGE IMAGE TYPE
B=uint8(B);
subplot(212),imshow(B),title('IMAGE AFTER MIN FILTERING');