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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* newHead = head->next;
        
        ListNode* first = head;
        ListNode* prev = nullptr;
        while(first!=nullptr&&first->next!=nullptr){
            ListNode* tmp = first->next;
            
            first->next=tmp->next;
            tmp->next=first;
            if(prev!=nullptr)
                prev->next= tmp;
            
            prev = first;
            first=first->next;
        }
        return newHead;
    }
};