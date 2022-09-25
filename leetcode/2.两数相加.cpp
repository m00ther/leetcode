
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=1,remain=0,num1,num2,flag=0;
        ListNode *l3=new ListNode(-1,nullptr);     
        ListNode *t=l3;
        while(l1||l2||remain){
            if(!l1){
                num1=0;
            }
            else{num1=l1->val;}
            if(!l2){
                num2=0;
            }
            else{num2=l2->val;}
            int temp=num1+num2+remain;
            if(temp>=10){ 
                temp-=10;
                flag=1;
            }
            else{flag=0;}
                    ListNode *tempp=new ListNode(temp,nullptr);
                    t->next=tempp;
                    t=tempp;
            if(flag){
                remain=1;
            }
            else{remain=0;}
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
        }
        
    
        

        return l3->next;
    }
};
// @lc code=end

