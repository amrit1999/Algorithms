struct LinkedListNode {
public:
    int key, val;
    LinkedListNode* next, *prev;
    LinkedListNode(int k, int v) {
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};


class LRUCache {
public:

    void deleteNode(LinkedListNode* node){
        LinkedListNode* pre = node->prev;
        LinkedListNode* nxt = node->next;
        pre->next = nxt;
        nxt->prev = pre;
    }

    void setAfterHead(LinkedListNode* node, LinkedListNode* head){
        LinkedListNode* nxt = head->next;
        head->next = node;
        nxt->prev = node;
        node->next = nxt;
        node->prev = head;
    }

    LinkedListNode* head, *tail;
    int totalSize;
    unordered_map<int, LinkedListNode*> location;
    LRUCache(int capacity) {
        head = new LinkedListNode(-1,-1);
        tail = new LinkedListNode(-2,-2);
        head->next = tail;
        tail->prev = head;
        totalSize = capacity;
    }
    
    int get(int key) {
        if (location.find(key) != location.end()) {
            LinkedListNode* oldNode = location[key];
            deleteNode(oldNode);
            setAfterHead(oldNode, head);
            return oldNode->val;
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (location.find(key) != location.end()) {
            LinkedListNode* oldNode = location[key];
            oldNode->val = value; 
            deleteNode(oldNode);
            setAfterHead(oldNode, head);
        } else {
            LinkedListNode* newNode = new LinkedListNode(key, value);
            location[key] = newNode;
            setAfterHead(newNode, head);
        }

        if (location.size() > totalSize) {
            LinkedListNode* lastNode = tail->prev;
            deleteNode(lastNode);
            location.erase(lastNode->key); 
            delete lastNode; 
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
