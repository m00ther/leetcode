/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
#include<vector>
#include<iostream>
class Solution {
public:
    int getfactorial(int n){
        if(n<=1){
            return 1;
        }
        else{
            return n*getfactorial(n-1);
        }
    }   //求阶乘

    string getPermutation(int n, int k) {
        int nn=n;
        int kk=k;
        string result;
        vector<int> remain; //存储剩余的数
        for(int i=1;i<=n;i++){
            remain.push_back(i);
        }
        int t;      //每次的循环的除数
        int a,b;    //除得的商和余数
        for(int i=1;i<=n;i++){
            if(i==1){
                kk-=1;
            }
            t=getfactorial(nn-1);
            a=kk/t;
            b=kk%t;
            result+=remain[a]+48;   //改为取剩余的第a小的数
            remain.erase(remain.begin()+a);
            kk=b;
            nn--;
        }   //利用商和余数建立索引
        return result;
    }
};
// @lc code=end

