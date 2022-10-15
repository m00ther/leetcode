/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include<string>
int minn(int a,int b){
    return a<b?a:b;
}
int min(int a,int b,int c){
   int min=a;
   if(min>b){
    min=b;
   }
   if(min>c){
    min=c;
   }
   return min;
}


class Solution {
public:
    int minDistance(string word1, string word2) {        
        string s1,s2;   //确保s1长度小于s2
        if(word1.length()<word2.length()){
            s1=word1;
            s2=word2;
        }else{
            s1=word2;
            s2=word1;
        }
        if(s1.length()==0){
            return s2.length();
        }
        int dp[s1.length()][s2.length()];

        for(int i=0;i<s1.length();i++){
            for(int j=i;j<s2.length();j++){
                if(j<s1.length()){
                    //计算第一行第一列
                    if(i==0){
                        if(j==0){
                        dp[i][j]=(s1[i]==s2[j])?j:j+1;
                        dp[j][i]=(s2[i]==s1[j])?j:j+1;
                        }
                        else{
                        dp[i][j]=(s1[i]==s2[j])?j:dp[i][j-1]+1;
                        dp[j][i]=(s2[i]==s1[j])?j:dp[j-1][i]+1; 
                        }
                    }else{
                        if(s1[i]==s2[j]){
                            dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]+1,dp[i][j-1]+1);
                        }else{
                            dp[i][j]=min(dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1);
                        }
                        if(s1[j]==s2[i]){
                            dp[j][i]=min(dp[j-1][i-1],dp[j-1][i]+1,dp[j][i-1]+1);
                        }else{
                            dp[j][i]=min(dp[j-1][i-1]+1,dp[j-1][i]+1,dp[j][i-1]+1);
                        }
                    }
                }
                else{
                    if(i==0){
                        dp[i][j]=(s1[i]==s2[j])?j:dp[i][j-1]+1;
                    }else{
                        if(s1[i]==s2[j]){
                            dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]+1,dp[i][j-1]+1);
                        }else{
                            dp[i][j]=min(dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1);
                        }
                    }
                }
            }
        }
        return dp[s1.length()-1][s2.length()-1];
    }
};
// @lc code=end

