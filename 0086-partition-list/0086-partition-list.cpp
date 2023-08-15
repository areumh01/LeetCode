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
    ListNode* partition(ListNode* head, int x) {
        ListNode* current = head;
        ListNode* less = new ListNode();
        ListNode* lessHead = less;
        ListNode* greater = new ListNode();
        ListNode* greaterHead = greater;
        while(current!=nullptr){
            ListNode* newNode = new ListNode(current->val);
            if(current->val < x){
                less->next = newNode;
                less = less->next;
            }
            else{
                greater->next = newNode;
                greater = greater->next;
            }
            current = current->next;
        }
        less->next = greaterHead->next;
        head = lessHead->next;
        return head;
    }
};