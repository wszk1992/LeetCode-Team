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
        if(node == NULL) {
            return NULL;
        }
        unordered_map<int, UndirectedGraphNode*> label_list;
        return cloneGraphHelper(node, label_list);
    }
    
    UndirectedGraphNode *cloneGraphHelper(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*>& label_list) {
        UndirectedGraphNode *res = new UndirectedGraphNode(node->label);
        label_list[node->label] = res;
        if(!node->neighbors.empty()) {
            res->neighbors = vector<UndirectedGraphNode*>(node->neighbors.size(), NULL);
        }
        for(int i = 0; i < node->neighbors.size(); i++) {
            if(label_list.count(node->neighbors[i]->label)) {
                res->neighbors[i] = label_list[node->neighbors[i]->label];
            }else {
                res->neighbors[i] = cloneGraphHelper(node->neighbors[i], label_list);
            }
        }
        return res;
    }
};