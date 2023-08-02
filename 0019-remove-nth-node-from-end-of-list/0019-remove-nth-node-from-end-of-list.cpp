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
        int size = 0;
        
        if(head->next == nullptr) return nullptr;
        
        ListNode* forsize = head;
        while(forsize->next!=nullptr){
            forsize = forsize->next;
            size++;
        }
        n = size-n;
        //cout << n << '\n';
        if(n==-1) return head->next;
        
        ListNode* forErase = head;
        while(n!=0){
            forErase = forErase->next;
            n--;
        }
        ListNode* linked = forErase->next->next;
        forErase->next = linked;
        return head;
    }
};