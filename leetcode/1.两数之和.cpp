// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a,b,flag=false;
        vector<int > v;
        for(int i=0;i<=nums.size()-2;i++){
            for(int j=i+1;j<=nums.size()-1;j++){
                if(nums[i]+nums[j]==target){
                    a=i;
                    b=j;
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};
// @lc code=end

