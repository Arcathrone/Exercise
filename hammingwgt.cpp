#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//calculating the Hamming Weight of 32bit int.
    int hammingWeight(uint32_t n) {
        int resid = 0;
        int bin = 0;
        while(n > 1)
        {
            resid = n%2;
            if (resid == 1)
                bin = bin+1;
            n = n / 2;
        }
        if (n == 1)
            bin = bin+1;
        return bin;
    }
