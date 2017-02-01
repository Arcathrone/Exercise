#include <iostream>
#include <vector>
using namespace std;

//Input a vector of numbers and a target sum. If two of the numbers in the vector add up to the sum, they become the output
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int indFirst = 0;
        int res[2];
        int loop = 1;
        while(loop)
        {
            int seek = target - nums[indFirst];
            for (int i = indFirst + 1; i < len; i++)
            {
                if(nums[i] == seek)
                {
                    res[0] = indFirst;
                    res[1] = i;
                    loop = 0;
                    cout<<res[0]<<" "<<res[1]<<endl;
                    break;
                }
            }
            if(indFirst != len-2)
                {
                    indFirst = indFirst + 1;
                }
            else
                {
                    if(loop != 0)
                    {
                        res[0] = 0;
                        res[1] = 0;
                        loop = 0;
                        cout<<"No match found for target"<<endl;
                    }
                }

        }
        vector<int> resOut (res, res + sizeof(res)/sizeof(int));
        return resOut;
    }

