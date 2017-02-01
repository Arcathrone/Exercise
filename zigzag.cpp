#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//Write a string in zigzag pattern and read line by line. Conversion rows are arbitrary.
    string convert(string s, int numRows) {
        int len = s.size();
        string result;
        if (numRows > 1)
        {
            vector<char> rows[numRows];
            int i = 0;
            int r = 0;
            int flag = 1;
            while(i<len)
            {
                rows[r].push_back(s[i]);
                if (r == 0)
                    flag = 1;
                if (r == numRows - 1)
                    flag = -1;
                r = r+flag;
                i = i + 1;
            }
            vector<char> res = rows[0];
            for (int j = 1; j < numRows; j++)
            {
                res.insert(res.end(),rows[j].begin(),rows[j].end());
            }
            result = string(res.begin(),res.end());
        }
        else
        {
            result = s;
        }
        return result;
    }


