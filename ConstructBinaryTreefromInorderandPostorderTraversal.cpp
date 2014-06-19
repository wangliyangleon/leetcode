// https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (0 == inorder.size()) {
            return NULL;
        }
        index_map_inorder.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            index_map_inorder.insert(pair<int, int>(inorder.at(i), i));
        }

        return buildSubTree(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode *buildSubTree(vector<int> &inorder, vector<int> &postorder, int postindex_root, int inindex_begin, int inindex_end) {
        if (inindex_begin > inindex_end) {
            return NULL;
        } else if (inindex_begin == inindex_end) {
            return new TreeNode(inorder.at(inindex_begin));
        }

        int valroot = postorder.at(postindex_root);
        unordered_map<int, int>::iterator iter = index_map_inorder.find(valroot);
        if (iter == index_map_inorder.end()) {
            // impossible
            return NULL;
        }
        int inindex_root = iter->second;
        int left_len = inindex_root - inindex_begin;
        int right_len = inindex_end - inindex_root;
        TreeNode * root = new TreeNode(valroot);

        if (0 == left_len) {
            root->left = NULL;
        } else {
            root->left = buildSubTree(inorder, postorder, postindex_root - 1 - right_len, inindex_begin, inindex_root - 1);
        }

        if (0 == right_len) {
            root->right = NULL;
        } else {
            root->right = buildSubTree(inorder, postorder, postindex_root - 1, inindex_root + 1, inindex_end);
        }
        return root;
    }

    unordered_map<int, int> index_map_inorder;
};
