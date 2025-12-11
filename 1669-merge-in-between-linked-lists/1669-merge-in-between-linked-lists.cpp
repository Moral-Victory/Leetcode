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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev_a = list1;
        for(int i = 0; i < a - 1; i++)
            prev_a = prev_a->next;

        ListNode* after_b = prev_a;
        for(int i = 0; i < b - a + 2; i++)
            after_b = after_b->next;

        ListNode* tail2 = list2;
        while(tail2->next != nullptr)
            tail2 = tail2->next;

        prev_a->next = list2;
        tail2->next = after_b;

        return list1;
    }
};