#works like while loop but while works when it is true on the other hand untill works untill the the condition is true

' /
until [ condition ]
do 

done
/ '

i=1
until [ $i -eq 10 ]
do 
   echo "$i"
   i=$((i+1))
   #i=` expr $i + 1`
   

done
