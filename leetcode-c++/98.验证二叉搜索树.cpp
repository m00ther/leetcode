/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // bool dfs(TreeNode* root,int a,int flag){
    //     if(root->left==nullptr&&root->right==nullptr){
    //         return true;
    //     }
    //     else if(root->left==nullptr&&root->right!=nullptr){
    //         if(root->val<root->right->val&&((root->right->val>a&&flag==1)||(root->right->val<a&&flag==0)||flag==2)){
    //             return dfs(root->right,root->val,1);
    //         }else{
    //             return false;
    //         }
    //     }
    //     else if(root->left!=nullptr&&root->right==nullptr){
    //         if(root->val>root->left->val&&((root->left->val>a&&flag==1)||(root->left->val<a&&flag==0)||flag==2)){
    //             return dfs(root->left,root->val,0);
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     else{
    //         if(root->val>root->left->val&&root->val<root->right->val&&((root->right->val>a&&flag==1)||(root->right->val<a&&flag==0)||flag==2)&&((root->left->val>a&&flag==1)||(root->left->val<a&&flag==0)||flag==2)){
    //             return dfs(root->right,root->val,1)&&dfs(root->left,root->val,0);
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    // }
    long pre=-1000000000000000;
    bool isValidBST(TreeNode* root) {
       if(root==nullptr){
            return true;
       }
       if(!isValidBST(root->left)){
        return false;
       }
       if(pre>=root->val){
        return false;
       }
       pre=root->val;
       return isValidBST(root->right);
    }
};
// @lc code=end

