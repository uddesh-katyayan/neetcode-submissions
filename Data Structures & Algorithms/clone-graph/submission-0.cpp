/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        unordered_map<Node*, Node*> mappings;
        return cloneHelper(node, mappings);
    }
private:
    Node* cloneHelper(Node* node, unordered_map<Node*, Node*>& mappings){
        if(mappings.find(node)!=mappings.end()){
            return mappings[node];
        }
        Node* copy = new Node(node->val);
        mappings[node] = copy;
        for(auto& nbr: node->neighbors){
            Node* copy_nbr = cloneHelper(nbr, mappings);
            copy->neighbors.push_back(copy_nbr);
        }
        return copy;
    }
};
