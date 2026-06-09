/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old_to_new;
        Node* new_head = NULL;
        Node* old_head = head;
        Node* new_prev = NULL;
        int i=0;
        while(head!=NULL){
            Node* new_node = new Node(head->val);
            if(i==0){
                new_head = new_node;
            }
            if(new_prev != NULL){
                new_prev->next = new_node;
            }
            i++;
            new_prev = new_node;
            old_to_new[head] = new_node;
            head = head->next;
        }
        // while(new_head!=NULL){
        //     cout << new_head->val << "\t";
        //     new_head = new_head->next;
        // }
        Node* old_it = old_head;
        Node* new_it = new_head;
        while(old_it!=NULL){
            Node* old_rand = old_it->random;
            Node* new_rand = old_to_new[old_rand];
            new_it->random = new_rand;
            old_it = old_it->next;
            new_it = new_it->next;
        }
        return new_head;
    }
};
