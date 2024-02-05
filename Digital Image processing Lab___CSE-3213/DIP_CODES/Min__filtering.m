clc;
clear all;
close all;

a= imread("cameraman.tif");
[Mi,Ni]=size(a);

w=ones(3,3);
[m,n]=size(w);

f=padarray(a, [m-1,n-1]);
[M,N]=size(f);

filter_img=zeros(M,N);

sM=(m+1)/2;
sN=(n+1)/2;

eM=sM-1;
eN=sN-1;

w=w';
w1=w(:);
[r,c]=size(w1);

for i = sM:M-eM
    for j = sN:N-eN
        array = zeros(r,c);
        iw=1;
        for ii = i-eM:i+eM
            for jj = j-eN:j+eN
                array(iw) = w1(iw) * f(ii,jj);
                iw=iw+1;
            end
        end
        filter_img(i,j)=ceil(min(array));
    end
end
filter_img = filter_img( m:m+Mi-1, n:n+Ni-1);
subplot(121); imshow(a); title("Original Image");
subplot(122); imshow(uint8(filter_img)); title("After min filtering image");