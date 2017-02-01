#include <iostream>
#include <vector>
using namespace std;

//Determine whether nim game can be won.
    bool canWinNim(int n) {
        int res = 0;
        res = n%4;
        if(res == 0)
            return 0;
        else
            return 1;

    }
