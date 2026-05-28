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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head != NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            if(fast->next == NULL)
                break;
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    void reorderList(ListNode* l1) {
        ListNode* mid = findMid(l1);
        ListNode* l2 = mid->next;
        mid->next = NULL;
        l2 = reverseList(l2);
        
        ListNode* rll = l1;
        ListNode* l1_next;
        ListNode* l2_next;
        
        while(l1 != NULL && l2!=NULL){
            l1_next = l1->next;
            l1->next = l2;
            l2_next = l2->next;
            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }
};
