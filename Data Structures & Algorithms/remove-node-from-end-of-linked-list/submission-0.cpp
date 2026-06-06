/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode* output = head;
        ListNode* forward = head;
        while(i<n){
            forward = forward->next;
            i++;
        }
        ListNode* back = head;
        ListNode* prev = head;
        while(forward!=NULL){
            prev = back;
            back = back->next;
            forward = forward->next;
        }
        return removeNode(output, back, prev);
    }
private:
    ListNode* removeNode(ListNode* head, ListNode* node, ListNode* prev){
        if(node==head){
            return head!=NULL? head->next : NULL;
        }
        prev->next = node->next;
        return head;
    }
};
