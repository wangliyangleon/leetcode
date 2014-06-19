// https://oj.leetcode.com/problems/clone-graph/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node) {
            return NULL;
        }
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> node_map;
        stack<UndirectedGraphNode*> node_stack;
        stack<UndirectedGraphNode*> new_node_stack;
        UndirectedGraphNode* new_graph = new UndirectedGraphNode(node->label);
        node_map.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(node, new_graph));
        node_stack.push(node);
        new_node_stack.push(new_graph);

        while (!node_stack.empty()) {
            UndirectedGraphNode * cur_node = node_stack.top(); 
            UndirectedGraphNode * cur_new_node = new_node_stack.top();
            node_stack.pop();
            new_node_stack.pop();
            for (vector<UndirectedGraphNode*>::iterator iter = cur_node->neighbors.begin();
                    iter != cur_node->neighbors.end(); ++iter) {
                unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator node_iter =
                    node_map.find(*iter);
                if (node_iter != node_map.end()) {
                    cur_new_node->neighbors.push_back(node_iter->second);
                } else {
                    UndirectedGraphNode* new_node = new UndirectedGraphNode((*iter)->label);
                    cur_new_node->neighbors.push_back(new_node);
                    node_stack.push(*iter);
                    new_node_stack.push(new_node);
                    node_map.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(*iter, new_node));
                }
            }
        }
        return new_graph;
    }
};
