/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int a[100];
        bool flag=true;
        int sum=0;
        stack<int > s;
        if(x<0){return false;}
        else if(x==0){return true;}
        else {
           int temp=x;
           while(temp){
                a[sum]=temp%10;
                s.push(temp%10);
                temp=temp/10;
                sum++;
           } 
           int k=0;
            while(!s.empty()){
                if(s.top()!=a[k]){
                    flag=false;
                }
                s.pop();
                k++;
            }
            return flag;
        }
    }
};
// @lc code=end

