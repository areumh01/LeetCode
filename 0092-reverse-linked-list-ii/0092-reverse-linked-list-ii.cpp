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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> s;
        queue<int> q;
        ListNode* current = head;
        int index = 1;
        while(current != nullptr){
            if(index >= left && index <= right) s.push(current->val);
            else q.push(current->val);
            current = current->next;
            index++;
        }
        int size = index;
        ListNode* dummy = new ListNode();
        current = dummy;
        index=1;
        //cout << s.size() << " " << q.size();
        while(index<size){
            ListNode* newNode;
            if(index >= left && index <= right) {
                newNode = new ListNode(s.top());
                s.pop();
            }
            else{
                newNode = new ListNode(q.front());
                q.pop();
            }
            current -> next = newNode;
            current = current->next;
            index++;
        }
        return dummy->next;
    }
};