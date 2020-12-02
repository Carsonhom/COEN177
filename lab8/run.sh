#!/bin/bash
make; 
echo "----------FIFO----------"
cat accesses.txt | ./fifo 10 
echo "----------End FIFO----------"
echo
echo "----------LRU----------"
cat accesses.txt | ./lru 10 
echo "----------End LRU----------"
echo
echo "----------Second Chance----------"
cat accesses.txt | ./sec_chance 10 
echo "----------End Second Chance----------"

echo "FIFO 10K Test with cache size = 10, 50, 100, 250, 500"
cat accesses.txt | ./fifo 10 fifo
cat accesses.txt | ./fifo 50 fifo
cat accesses.txt | ./fifo 100 fifo
cat accesses.txt | ./fifo 250 fifo
cat accesses.txt | ./fifo 500 fifo
echo
echo "LRU 10K Test with cache size = 10, 50, 100, 250, 500"
cat accesses.txt | ./lru 10 lru
cat accesses.txt | ./lru 50 lru
cat accesses.txt | ./lru 100 lru
cat accesses.txt | ./lru 250 lru
cat accesses.txt | ./lru 500 lru
echo
echo "Second Chance 10K Test with cache size = 10, 50, 100, 250, 500"
cat accesses.txt | ./sec_chance 10 sec_chance
cat accesses.txt | ./sec_chance 50 sec_chance
cat accesses.txt | ./sec_chance 100 sec_chance
cat accesses.txt | ./sec_chance 250 sec_chance
cat accesses.txt | ./sec_chance 500 sec_chance
echo
make clean;
echo
