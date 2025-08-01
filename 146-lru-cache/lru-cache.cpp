class LRUCache {
public:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;

    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }


    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }
        Node* node = mpp[key];
        deleteNode(node);              // remove from current position
        insertAfterHead(node);         // move to front (most recently used)
        return node->value;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (mpp.size() == cap) {
                // remove LRU node (node before tail)
                Node* lru = tail->prev;
                deleteNode(lru);
                mpp.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mpp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */