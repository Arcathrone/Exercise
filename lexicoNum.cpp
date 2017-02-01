#include <iostream>
#include <vector>
using namespace std;

//Re-order numbers in lexicographical order.
    vector<int> lexicalOrder(int n) {
        vector<double> temp(1,1);
        vector<int> res(1,1);
        int len,i,j;
        double transNum;
        if (n > 1)
        {
            for(i = 2; i<=n; i++)
            {
                transNum = trans(i);
                len = res.size();
                j = 0;
                while(j <= len)
                {
                    if(j == len)
                    {
                        temp.push_back(transNum);
                        res.push_back(i);
                    }
                    else
                    {
                        if(temp[j]>transNum)
                        {
                            temp.insert(temp.begin()+j,transNum);
                            res.insert(res.begin()+j,i);
                            break;
                        }
                    }
                    j = j+1;
                }
            }
        }
        return res;
    }
    double trans(int i)
    {
        double res = (double)i;
        double temp = res;
        if(temp < 10)
            temp*=10;
        while(temp >= 10)
        {
            res = temp;
            temp = temp/10;
        }
        return res;
    }
