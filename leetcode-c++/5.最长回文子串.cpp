/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include<string>

class Solution {
public:
    string longestPalindrome(string s) {
        int orlen=s.length();
        int begin=0,maxlen=1;

        int dp[orlen][orlen];
        for(int i=0;i<orlen;i++){
            for(int j=0;j<orlen;j++){
                dp[i][j]=0;
            }
        }
        for(int i=0;i<=orlen-1;i++){
            dp[i][i]=1;
        }
        for(int i=2;i<=orlen;i++){
            for(int j=0;j<s.length();j++){
                int r=i+j-1;
                if(r>orlen-1){
                    continue;
                }
                if(i==2){
                    if(s[j]==s[r]){
                        dp[j][r]=1;
                    }
                }//连续两位相同
                else if(s[j]==s[r]){
                    dp[j][r]=dp[j+1][r-1];
                }
                if(dp[j][r]==1){
                    if(i>maxlen){
                        maxlen=i;
                        begin=j;
                    }
                }
            }
        }
        return s.substr(begin,maxlen);
    }
};
// @lc code=end

