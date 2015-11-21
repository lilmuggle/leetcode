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
    unordered_map<int, UndirectedGraphNode*> m;
    UndirectedGraphNode* dfs(UndirectedGraphNode *p) {
        UndirectedGraphNode *c = new UndirectedGraphNode(p->label);
        m[p->label] = c;
        for(UndirectedGraphNode* n : p->neighbors) {
            if(m.find(n->label) == m.end())
                c->neighbors.push_back(dfs(n));
            else
                c->neighbors.push_back(m[n->label]);
        }
        return c;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        return dfs(node);
    }
};

class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
       if (!node) return node;
       if(hash.find(node) == hash.end()) {
           hash[node] = new UndirectedGraphNode(node -> label);
           for (auto x : node -> neighbors) {
                (hash[node] -> neighbors).push_back( cloneGraph(x) );
           }
       }
       return hash[node];
    }
};
