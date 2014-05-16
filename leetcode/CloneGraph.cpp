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
        if (!node) return node;
        unordered_map<int, UndirectedGraphNode*> clone;
        set<int> searched;
        return cloneNode(node, clone, searched);
    }
    
    UndirectedGraphNode *cloneNode(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &clone, set<int> &searched) {
        UndirectedGraphNode *n = getClone(node->label, clone);
        if (searched.count(n->label) > 0) return n;
        searched.insert(n->label);
        for (auto neighbor : node -> neighbors) {
            n->neighbors.push_back(cloneNode(neighbor, clone, searched));
        }
        return n;
    }
    
    UndirectedGraphNode *getClone(int l, unordered_map<int, UndirectedGraphNode*> &c) {
        if (c.count(l) == 0) {
            UndirectedGraphNode* n = new UndirectedGraphNode(l);
            c[l] = n;
        }
        return c[l];
    }
};
