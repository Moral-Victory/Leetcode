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

    ListNode* find_middle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* merge_list(ListNode* list1,ListNode* list2){
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* dummynode=new ListNode(-1);
        ListNode* temp = dummynode;
        while(t1!=nullptr && t2!=nullptr){
            if(t1->val<t2->val){
                temp->next=t1;
                temp=temp->next;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                temp=temp->next;
                t2=t2->next;
            }
        }
        if(t1){
            temp->next=t1;
        }
        else{
            temp->next=t2;
        }
        return dummynode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* left = head;
        ListNode* middle = find_middle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        //to make sure both are seperated for the sort fxn to work
        ListNode* left_head = sortList(left);
        ListNode* right_head = sortList(right);
        return merge_list(left_head,right_head);
        
    }
};