## Key Points/Tricks
1. INT_MIN (4 bytes) in binary ```10000000000000000000000000000000```
2. INT_MAX (4 bytes) in binary ```01111111111111111111111111111111```
3. -1 (4 bytes) in binary ```11111111111111111111111111111111```
4. Right shift by 1 (num >> 1) is same as dividing by 2
5. Left shift by 1 (num << 1) is same as multiplying by 2
6. bitwise & of num with 1 (num & 1) is same as remainder of a number after dividing by 2 (num % 2)
7. hexadecimal numbers can be represented like 0x1010 in C++
8. Binary numbers can be represented like 0b1010 in C++
9. ```>>>``` operator is not available in C++, ```static_cast<unsigned int>``` can be used
10. ```n & (n-1)) == 0```. This is only true when n is a power of 2.
