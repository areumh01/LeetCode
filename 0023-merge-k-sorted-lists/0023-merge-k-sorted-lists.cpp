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
    void linking(ListNode* current, int val){
        ListNode* newNode = new ListNode(val);
        newNode -> next = current -> next;
        current -> next = newNode;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return {};
        
        int start=0;
        ListNode* answerHead = nullptr;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]!=nullptr) {
                answerHead = lists[i];
                start=i+1;
                break;
            }
        }    
        if(answerHead==nullptr) return {};
        
        ListNode* dummy = new ListNode(-1000002);
        dummy->next = answerHead;
        
        for(int i=start; i<lists.size(); i++){
            ListNode* current = dummy;
            ListNode* comp = lists[i];
            while(current->next!=nullptr && comp!=nullptr){
                if(current->next->val > comp->val){
                    linking(current,comp->val);
                    comp = comp->next;
                }
                else current = current->next;
            }
            while(comp!=nullptr){
                    linking(current,comp->val);
                    comp = comp->next;
                    current = current->next;
            }
        }
        
        return dummy->next;
    }
};