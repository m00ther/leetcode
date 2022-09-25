// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem25.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){return head;}
        int count=1,flag=1;    //计数器
        ListNode *l3=new ListNode(-1,nullptr);
        l3->next=head;
        ListNode* p=head;   //当前节点
        ListNode* pprev=head;   //前一个k个节点的第一个节点
        ListNode* pnow=head;   //这一个k个节点的第一个节点
        ListNode* pnext=head;   //下一个k个节点的第一个节点
        ListNode* local1=head;
        ListNode* local2=head;
        ListNode* temp=head;
        while(p!=nullptr&&p->next!=nullptr){
            if(count==0){
                pprev=pnow;
                pnow=local2;               
            }
            p=p->next;//一定不为NULL
            count++;
            if(count==k){
                count=0;
                pnext=p->next;
                local1=pnow;
                local2=pnow->next;
                pnow->next=pnext;

                while(local2!=nullptr&&local2!=pnext){
                    temp=local2->next;
                    local2->next=local1;
                    local1=local2;
                    local2=temp;

                };


                if(flag==1){
                    l3->next=local1;
                    flag++;
                }
                else{
                    pprev->next=local1;
                }
                p=pnow;
            }
        }
        return l3->next;
    }
};
// @lc code=end

