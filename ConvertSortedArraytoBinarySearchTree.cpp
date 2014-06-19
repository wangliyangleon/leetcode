// https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (0 == num.size()) {
            return NULL;
        }
        return produceSubTree(num, 0, num.size() - 1);
    }

private:
    TreeNode* produceSubTree(vector<int>& num, int start, int end) {
        if (start == end) {
            return (new (std::nothrow) TreeNode(num.at(start)));
        } else if (start + 1 == end) {
            TreeNode* node_right = new (std::nothrow) TreeNode(num.at(end));
            TreeNode* node_root = new (std::nothrow) TreeNode(num.at(start));
            node_root->right = node_right;
            return node_root;
        } else if (start + 2 == end) {
            TreeNode* node_left = new (std::nothrow) TreeNode(num.at(start));
            TreeNode* node_right = new (std::nothrow) TreeNode(num.at(end));
            TreeNode* node_root = new (std::nothrow) TreeNode(num.at(start + 1));
            node_root->left = node_left;
            node_root->right = node_right;
            return node_root;
        } else {
            int mid = start + (end - start) / 2;
            TreeNode* node_root = new (std::nothrow) TreeNode(num.at(mid));
            node_root->left = produceSubTree(num, start, mid - 1);
            node_root->right = produceSubTree(num, mid + 1, end);
            return node_root;
        }
    }
};
