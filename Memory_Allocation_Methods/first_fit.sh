#!/bin/bash

echo "First Fit Memory Allocation"

echo "Enter Number of Blocks:"
read nb

echo "Enter Block Sizes:"
for ((i=0; i<nb; i++))
do
    read block[$i]
done

echo "Enter Number of Processes:"
read np

echo "Enter Process Sizes:"
for ((i=0; i<np; i++))
do
    read process[$i]
    allocation[$i]=-1
done

for ((i=0; i<np; i++))
do
    for ((j=0; j<nb; j++))
    do
        if [ ${block[$j]} -ge ${process[$i]} ]
        then
            allocation[$i]=$j
            block[$j]=$((block[j] - process[i]))
            break
        fi
    done
done

echo
echo -e "Process\tSize\tBlock"

for ((i=0; i<np; i++))
do
    if [ ${allocation[$i]} -ne -1 ]
    then
        echo -e "P$((i+1))\t${process[$i]}\tB$((allocation[i]+1))"
    else
        echo -e "P$((i+1))\t${process[$i]}\tNot Allocated"
    fi
done
