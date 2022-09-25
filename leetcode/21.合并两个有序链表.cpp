/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *a=list1;
        ListNode *b=list2;
        ListNode *l3=new ListNode(-1,nullptr);
        ListNode *cursor=l3;
        while(a!=NULL||b!=NULL){
            int num_a=  a!=nullptr?a->val:200;
            int num_b=  b!=nullptr?b->val:200;
            if(num_a<num_b){
                ListNode *temp=new ListNode(num_a,nullptr);
                cursor->next=temp;
                cursor=cursor->next;
                a=a->next;
            }
            else{
                ListNode *temp=new ListNode(num_b,nullptr);
                cursor->next=temp;
                cursor=cursor->next;
                b=b->next;
            }
        }
        return l3->next;
    }
};
// @lc code=end

