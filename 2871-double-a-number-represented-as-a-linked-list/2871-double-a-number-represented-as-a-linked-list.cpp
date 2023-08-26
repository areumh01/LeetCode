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
    ListNode* doubleIt(ListNode* head) {
        ListNode* current = head;
        int c=0,r=0;
        int n = current -> val;
        ListNode* dummy = new ListNode(0);
        ListNode* making = dummy;
        
        while(current != nullptr){
            int n = current -> val;
            c = (n*2)/10;
            r += c;
            ListNode* newNode = new ListNode(r);
            r = (n*2)%10;
            making->next = newNode;
            making = making->next;
            current = current->next;
        }
        ListNode* newNode = new ListNode(r);
        making->next = newNode;
        if(dummy->next->val == 0) return dummy->next->next;
        return dummy->next;
    }
};