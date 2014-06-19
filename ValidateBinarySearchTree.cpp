// https://oj.leetcode.com/problems/validate-binary-search-tree/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (NULL == root) {
            return true;
        }
        TreeNode *pleft = root->left;
        TreeNode *pright = root->right;
        return isValidBstSub(pleft, INT_MIN, root->val) && isValidBstSub(pright, root->val, INT_MAX);
    }   

    bool isValidBstSub(TreeNode *root, int min_val, int max_val) {
        if (NULL == root) {
            return true;
        }   
        TreeNode *pleft = root->left;
        TreeNode *pright = root->right;
        if (root->val >= max_val || root->val <= min_val) {
            return false;
        }   
        return isValidBstSub(pleft, min_val, root->val) && isValidBstSub(pright, root->val, max_val);
    }   
}; 
