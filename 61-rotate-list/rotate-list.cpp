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
    int calculat_n(ListNode* head, int k) {
        int count = 1;
        ListNode* temp = head;
        while (temp->next != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode* temp = head;
        int count = 1;
        int n = calculat_n(head, k);
        k = k % n;
        for (int i = 1; i < n - k; i++) {
            temp = temp->next;
        }
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        tail->next = head;
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};