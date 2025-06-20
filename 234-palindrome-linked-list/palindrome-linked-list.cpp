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
    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* after = nullptr;
        ListNode* back = nullptr;
        while(temp!=nullptr){
            after = temp->next;
            temp->next=back;
            back =temp;
            temp=after;
        }
        return back;
    }

    bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return true;
        }
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* newhead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newhead;
        while(second!=nullptr){
            if(first->val!=second->val){
                reverseLL(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLL(newhead);
        return true;
    }
};

