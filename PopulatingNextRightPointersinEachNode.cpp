// https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == root) {
            return;
        }
        vector<TreeLinkNode*> node_vec_a, node_vec_b;
        node_vec_a.push_back(root);
        bool flag = true;
        vector<TreeLinkNode*> *pvec_cur = NULL, *pvec_next = NULL;
        for (;;) {
            if (flag) {
                pvec_cur = &node_vec_a;
                pvec_next = &node_vec_b;
            } else {
                pvec_cur = &node_vec_b;
                pvec_next = &node_vec_a;
            }
            pvec_next->clear();
            for (int i = 0; i < pvec_cur->size(); ++i) {
                if (NULL != pvec_cur->at(i)->left) {
                    pvec_next->push_back(pvec_cur->at(i)->left);
                }
                if (NULL != pvec_cur->at(i)->right) {
                    pvec_next->push_back(pvec_cur->at(i)->right);
                }
                pvec_cur->at(i)->next = (i == pvec_cur->size() - 1 ? NULL : pvec_cur->at(i + 1));
            }
            if (0 == pvec_next->size()) {
                break;
            }
            flag = !flag;
        }
    }
};
