// https://oj.leetcode.com/problems/path-sum-ii/
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        _result.clear();
        if (NULL == root) {
            return _result;
        }
        vector<int> path;
        _tryPath(root, path, sum);
        return _result;
    }

private:
    void _tryPath(TreeNode *root, vector<int> path, int sum) {
        path.push_back(root->val);
        if (NULL == root->left && NULL == root->right) {
            if (sum == root->val) {
                _result.push_back(path);
            }
        } else if (NULL == root->left) {
            _tryPath(root->right, path, sum - root->val);
        } else if (NULL == root->right) {
            _tryPath(root->left, path, sum - root->val);
        } else {
            _tryPath(root->left, path, sum - root->val);
            _tryPath(root->right, path, sum - root->val);
        }
    }
    vector<vector<int> > _result;
};
