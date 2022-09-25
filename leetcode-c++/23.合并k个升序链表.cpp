/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int position,mini;
        ListNode* head;
        ListNode* p;
        if(lists.size()==0){return nullptr;}
        int sum=lists.size();
        for(int i=0;i<sum;){
            if(lists[i]==nullptr){
                lists.erase(lists.begin()+i);
                sum--;\
            }else{
                i++;
            }
        }
        if(lists.size()==0){return nullptr;}
        for(int i=0;i<lists.size();i++){
            if(i==0){
                mini=lists[i]->val;
                position=i;
            }
            else{
                if(lists[i]->val<mini){
                    mini=lists[i]->val;
                    position=i;
                }
            }
        }
        head=lists[position];
        if(lists[position]->next==nullptr){
            lists.erase(lists.begin()+position);
        }
        else{
            lists[position]=lists[position]->next;
        }
        p=head;
        while(!lists.empty()){
            for(int i=0;i<lists.size();i++){
                if(i==0){
                    mini=lists[i]->val;
                    position=i;
                }
                else{
                    if(lists[i]->val<mini){
                        mini=lists[i]->val;
                        position=i;
                    }
                }
            }
            p->next=lists[position];
            if(lists[position]->next==nullptr){
                lists.erase(lists.begin()+position);
            }
            else{
                lists[position]=lists[position]->next;
            }
            p=p->next;

        }


        return head;
    }
};
// @lc code=end

