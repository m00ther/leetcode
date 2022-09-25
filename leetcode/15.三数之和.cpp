/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int flag=1;
        if(nums.size()<3){
            return res;
        }
        sort(nums.begin(),nums.end());  //先给原始数组排序
        for(int i=0;i<=nums.size()-3;i++){
            if(i>0){
                if(nums[i]==nums[i-1]){
                    continue;
                }
            }//避免000000重复计算
            if(nums[i]>0){break;}//后面的数加这个数之和不会等于0
            else{
                int l=i+1,r=nums.size()-1;
                while(l<r){ //转化为O(n^2),使用左指针和右指针
                    if(nums[i]+nums[l]+nums[r]==0){
                            vector<int> temp;
                            temp.push_back(nums[i]);
                            temp.push_back(nums[l]);
                            temp.push_back(nums[r]);
                            sort(temp.begin(),temp.end());
                            flag=1;
                           for(vector<vector<int>>::iterator it=res.begin();it<res.end();it++){
                                if(*it==temp){
                                    flag=0;
                                    break;
                                }
                            }//避免重复
                            if(flag){
                                res.push_back(temp);
                            }
                            l++;
                            r--;//避免死循环
                        }
                    else if(nums[i]+nums[l]+nums[r]>0){
                        r=r-1;
                    }//和偏大左移右指针
                    else{l=l+1;}//和偏小右移左指针
                }


        }
        }
        return res;
    }
    
};
// @lc code=end

