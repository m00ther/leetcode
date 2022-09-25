/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *headhead=new ListNode(0,head);
        ListNode *cursor=head;
        int sum=0;
        while(cursor){
            sum++;
            cursor=cursor->next;
        }
        int target=sum-n;
        if(target==0){
            head=head->next;
        }
        cursor=headhead;
        while(target){
            target--;
            cursor=cursor->next;
        }
        cursor->next=cursor->next->next;
        return head;
    }
};
// @lc code=end

