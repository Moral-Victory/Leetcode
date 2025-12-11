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
        stack<int> st;
        ListNode* temp = head;
        while(temp!=nullptr){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        int carry = 0;;
        while(temp!=nullptr){
            temp->val = (st.top()*2 + carry)%10;
            
            carry = (st.top()*2 + carry)/10;
            st.pop();
            temp = temp->next;
        }
        temp = head;
        ListNode* prev = nullptr;
        while(temp!=nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        head = prev;

        if(carry>0){
        ListNode* node = new ListNode(carry);
        node->next = head;
        head = node;
        }
        
        return head;

    }
};