#!/usr/bin/env bash 

counter=1
tmp=0
amount=0
while [ $counter -le 20 ]
do
    tmp=$(./swap)
    amount=$((tmp+amount))
    echo -e $tmp
    ((counter++))
done

amount=$((amount/20))

echo -e
echo $amount

echo All done
