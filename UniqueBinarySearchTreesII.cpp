// https://oj.leetcode.com/problems/unique-binary-search-trees-ii/
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
    vector<TreeNode *> generateTrees(int n) {
        return _generateSubTrees(1, n);
    }

private:
    vector<TreeNode *> _generateSubTrees(int idx_begin, int idx_end) {
        vector<TreeNode *> result;
        if (idx_begin > idx_end) {
            result.push_back(NULL);
        } else {
            for (int i = idx_begin; i <= idx_end; ++i) {
                vector<TreeNode *> plefts = _generateSubTrees(idx_begin, i - 1);
                vector<TreeNode *> prights = _generateSubTrees(i + 1, idx_end);
                for (int j = 0; j < plefts.size(); ++j) {
                    for (int k = 0; k < prights.size(); ++k) {
                        TreeNode * pnode = new TreeNode(i);
                        pnode->left = plefts.at(j);
                        pnode->right = prights.at(k);
                        result.push_back(pnode);
                    }
                }
            }
        }
        return result;
    }
};
