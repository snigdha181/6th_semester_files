clc;
clear all;
close all;

img = imread('cameraman.tif');
b=imnoise(img,'gaussian');    
b1=imnoise(img,'salt & pepper',0.001);  

w=ones(3,3);                  

[Mi,Ni] = size(b); 
[m,n] = size(w);        

f = padarray(b,[m-1 n-1]); 
[M,N] = size(f);                 
filtered_img = zeros(M,N); 

sM = (m+1)/2; 
sN = (n+1)/2;

eM = sM-1;   
eN = sN-1;
w = w';       
w1 = w(:);    
[r,c] = size(w1);
for i = sM:M-eM
    for j = sN:N-eN
        array = zeros(r,c);
        iw=1;
        sum=0;
        sum1=0;
        Q=1;
        for ii = i-eM:i+eM  
            for jj = j-eN:j+eN
                array(iw) = w1(iw)*f(ii,jj);  
                c=array(iw).^(Q+1);
                sum=sum+c;
                c1=array(iw).^Q;
                sum1=sum1+c1;
                iw = iw+1;
            end
        end
        C=sum/sum1;
        filtered_img(i,j)=C;
    end
end

filtered_img = filtered_img(m:m+Mi-1, n:n+Ni-1);
subplot(221);imshow(img);title('Original Image');
subplot(222);imshow(b);title('Noisy Image using gaussian noise');
subplot(223);imshow(b1);title('Noisy Image using salt & pepper noise');
subplot(224);imshow(uint8(filtered_img));title('Contraharmonic Mean Filter');
