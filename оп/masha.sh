#! /bin/bash

if [[ $# -ne 3 ]]
then echo "usage: 3 args"
exit -1
fi

case "$2" in 
  Jan|Feb|Mar|Apr|May|June|July|Aug|Sept|Oct|Nov|Dec)
  ;;
  *) echo "wrong month format"
  exit -1;;
esac

case "$3" in
  Mon|Tue|Wed|Thu|Fri|Sat|San)
  ;;
  *) echo "wrong day format" 
  exit -3;;
esac

a=${1//[0-9\-]/''}

if [[ "${#a}" -ne 0 ]]
then echo "wrong year format"
exit -4 
fi

y1=${1:0:4}
y2=${1:(-4):4}

month=0
day=0

if [[ $y1 -gt $y2 ]]
then exit 0
fi

for ((i=1; i < 13; i++))
do
tmp=$(date -d "$i/01/2022" +%b)

if [[ $tmp == $2 ]]
then
month=$(date -d "$i/01/2022" +%m)
fi
done

day=$(date -d "$(( ($month+1)%12 ))/01/2022 yesterday" +%d)


for (( i = 0; i < $(( $y2 - $y1 + 1)); i++ ))
do 
tmp=$(date -d "$month/$day/$(( $y1 + $i ))" +%a)
if [[ $tmp == $3 ]]
then echo "$(( $y1+$i ))"
fi
done