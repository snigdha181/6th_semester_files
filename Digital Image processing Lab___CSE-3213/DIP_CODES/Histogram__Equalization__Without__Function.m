clc;
clear all;
close all;
img=imread("cameraman.tif");
total=0;

for i=1:256
   M(2,i)=0; 
end

for l=1:256
    M(1,l)=l-1;
for i=1:256
  for j=1:256
      if img(i,j)==l-1 
          M(2,l)=M(2,l)+1;
      end
  end
end
total=total+M(2,l);
end

PDF=M(2,:)/total;
c=0;
for k=1:256
   cdf(k)=c+PDF(1,k);
   c=cdf(k);
end
for k=1:256
   h(k)=255*cdf(k);
   y(k)=round(h(k));

end

for l=1:256
for i=1:256
  for j=1:256
      if img(i,j)==l-1 
          img2(i,j)=y(l);
      end
  end
end
end

img2=uint8(img2); 

subplot(2,2,1);imshow(img);title("Before Histogram");
subplot(2,2,2);imhist(img);title("Before Histogram");
subplot(2,2,3);imshow(img2);title("After Histogram Equalization(Without function)");
subplot(2,2,4);imhist(img2);title("After Histogram Equalization(Without function)");


