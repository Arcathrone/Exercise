#include <iostream>
#include <vector>
using namespace std;

//Largest product of contiguous subarray within an array. Input is vector of int.
    int maxProduct(vector<int>& nums) {
        int res;
        if(nums.size()==1)
            res = nums[0];
        else
        {
            res = INT_MIN;
            int temp;
            vector<bool> numZero = zSign(nums);
            vector<int> sub;
            for(int i=0;i<nums.size();i++)
            {
                if(numZero[i])
                {
                    sub.push_back(nums[i]);
                }
                else
                {
                    if(sub.size())
                        temp = nonZero(sub);
                    else
                        temp = 0;
                    if(res<0)
                        res = max(temp,0);
                    else
                        res = max(res,temp);
                    sub.erase(sub.begin(),sub.end());
                }
            }
            if(sub.size())
            {
                temp = nonZero(sub);
                res = max(res,temp);
            }
        }
        return res;
    }
    vector<bool> vSign(vector<int>& nums)
    {
        vector<bool> res;
        for(int i = 0; i<nums.size();i++)
            res.push_back(signbit(nums[i]));

        return res;
    }
    bool Neg(vector<bool>& sig)
    {
        int cnt = 0;
        for(int i = 0; i<sig.size();i++)
            cnt+=(int)sig[i];
        return (bool)(cnt%2);
    }
    vector<bool> zSign(vector<int>& nums)
    {
        vector<bool> res;
        for(int i = 0; i<nums.size();i++)
            res.push_back((bool)nums[i]);

        return res;
    }
    int nonZero(vector<int>& nums)
    {
        int res;
        if(nums.size()==1)
            res = nums[0];
        else
        {
            vector<bool> sig = vSign(nums);
            bool negNum = Neg(sig);

            if(negNum)
            {
                int res1=1;
                int res2=1;
                int n1=0;
                int n2=sig.size()-1;
                while(sig[n1] == 0)
                {
                    n1+=1;
                }
                for(int i = n1+1; i<=n2;i++)
                    res2*=nums[i];
                while(sig[n2]==0)
                {
                    n2-=1;
                }
                for(int i = 0; i<n2;i++)
                    res1*=nums[i];
                res = max(res1,res2);
            }
            else
            {
                res = 1;
                for(int i=0;i<nums.size();i++)
                    res*=nums[i];
            }
        }
        return res;
    }
