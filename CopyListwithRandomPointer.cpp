// https://oj.leetcode.com/problems/copy-list-with-random-pointer/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (NULL == head) {
            return NULL;
        }
        unordered_map<void*, void*> node_map;
        RandomListNode *pnode_src = head;
        RandomListNode *pnode_new = NULL, *pnode_new_head = NULL, *pnode_new_tail = NULL;
        while (pnode_src != NULL) {
            pnode_new = new RandomListNode(pnode_src->label);
            if (NULL == pnode_new_head) {
                pnode_new_head = pnode_new_tail = pnode_new;
            } else {
                pnode_new_tail->next = pnode_new;
                pnode_new_tail = pnode_new;
            }
            node_map.insert(pair<void*, void*>((void*)pnode_src, (void*)pnode_new));
            pnode_src = pnode_src->next;
        }   

        pnode_src = head;
        pnode_new = pnode_new_head;
        while (pnode_src != NULL) {
            if (pnode_src->random != NULL) {
                unordered_map<void*, void*>::iterator iter = node_map.find((void*)pnode_src->random);
                if (iter != node_map.end()) {
                    pnode_new->random = (RandomListNode *)iter->second;
                }   
            }
            pnode_src = pnode_src->next;
            pnode_new = pnode_new->next;
        }
        return pnode_new_head;
    }
};
