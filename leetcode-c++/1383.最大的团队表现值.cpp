/*
 * @lc app=leetcode.cn id=1383 lang=cpp
 *
 * [1383] 最大的团队表现值
 */

// @lc code=start
#include<algorithm>
#include<queue>
class Solution {
public:
    long maxx(long a,long b){
        if(a>b){
            return a;
        }
        else{
            return b;
        }
    }

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
            vector<vector<int>> v;  //依次存放每个人的效率和速度
            for(int i=0;i<=n-1;i++){
                v.push_back({efficiency[i],speed[i]});
            }
            sort(v.rbegin(),v.rend());  //按效率值从大到小排序贪心
            long nowsum=0;
            long maxk=0;
            priority_queue<int,vector<int>,greater<int>> q2; //小根堆，选择出每次最小的speed
            nowsum=(long)v[0][1]*v[0][0];
            maxk=(long)v[0][1];       //前面任选k-1个元素的和的最小值
            q2.push(v[0][1]);
            for(int i=1;i<=n-1;i++){
                if(k==1){
                        nowsum=maxx(nowsum,(long)v[i][1]*v[i][0]);
                }
                else{                
                    nowsum=maxx(nowsum,(long)v[i][0]*(maxk+v[i][1]));
                }
                if(i<k-1){
                    maxk+=v[i][1];
                    q2.push(v[i][1]);
                }
                else{
                    if(v[i][1]>q2.top()){   //更新前k-1个最大的speed的值
                        maxk=maxk-q2.top()+v[i][1];
                        q2.pop();
                        q2.push(v[i][1]);
                               
                    }
                }
            }
            return nowsum%(1000000000+7);

    }
};
// @lc code=end

