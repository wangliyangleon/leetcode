// https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root) {
            return;
        }
        vector<TreeLinkNode*> cur_level(1, root);
        vector<TreeLinkNode*> next_level;
        while (!cur_level.empty()) {
            next_level.clear();
            for (vector<TreeLinkNode*>::iterator iter = cur_level.begin();
                    iter != cur_level.end(); ++iter) {
                vector<TreeLinkNode*>::iterator iter_next = iter + 1;
                if (iter_next != cur_level.end()) {
                    (*iter)->next = *iter_next;
                } else {
                    (*iter)->next = NULL;
                }

                if (NULL != (*iter)->left) {
                    next_level.push_back((*iter)->left);
                }
                if (NULL != (*iter)->right) {
                    next_level.push_back((*iter)->right);
                }
            }
            cur_level.swap(next_level);
        }
    }
};
