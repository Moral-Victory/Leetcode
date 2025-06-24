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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummy_node = new ListNode(-1);
        int carry=0;
        int sum = 0;
        ListNode* curr = dummy_node;
        while(t1!=nullptr || t2!=nullptr){
            sum=carry;

            if(t1){
                sum+=t1->val;
            }
            if(t2){
                sum+=t2->val;
            }
            carry=sum/10;
            
            ListNode* new_node = new ListNode(sum%10);
            curr->next=new_node;
            curr=curr->next;
            if(t1){
                t1=t1->next;
            }
            if(t2){
                t2=t2->next;
            }


        }
        if(carry){
            ListNode* new_node = new ListNode(carry);
            curr->next=new_node;
        }
        return dummy_node->next;
    }
};