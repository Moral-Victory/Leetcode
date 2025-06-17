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
};