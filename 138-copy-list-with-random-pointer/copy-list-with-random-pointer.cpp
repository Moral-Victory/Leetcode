/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void Insert_between_node(Node* head){

        Node* temp = head;
        while(temp!=nullptr){
        
        Node* copy_node = new Node(temp->val);
        copy_node->next = temp->next;
        temp->next = copy_node;
        temp = temp->next->next;    
        }  
    }
    void connect_random_ptrs(Node* head){
        Node* temp = head;
        while(temp!=nullptr){
        
        Node* copy = temp->next;
        if(temp->random){
            copy->random = temp->random->next;
        }
        else{
            copy->random = nullptr;
        }
        temp = copy->next;
        }
    }

    Node* connect_next_ptrs(Node* head){
        Node* dummy_node = new Node(-1);
        Node* copy = dummy_node;
        Node* temp = head;

        while(temp!=nullptr){
        copy->next = temp->next;
        temp->next = temp->next->next;
        copy = copy->next;
        temp = temp->next;
        }
        return dummy_node->next;
    }

    Node* copyRandomList(Node* head) {
        Insert_between_node(head);
        connect_random_ptrs(head);
        return connect_next_ptrs(head);
        
    }
};