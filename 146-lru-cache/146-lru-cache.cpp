class LRUCache {
public:
    
    struct Node{
        int k;
        int v;
        Node* prev;
        Node* next;
        Node(int key, int val){
            k = key;
            v = val;
        }
    };
    
    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);
    
    
    int cap;
    unordered_map<int, Node*> m;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        Node * tmp = head->next;
        newNode->next = tmp;
        newNode->prev= head;
        head->next = newNode;
        tmp->prev= newNode;
    }

    
    void deleteNode(Node *delNode){
        Node* delprev = delNode->prev;
        Node* delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    

    int get(int key) {
        if(m.find(key) != m.end()){
            Node *resNode = m[key];
            int res = resNode->v;
            deleteNode(resNode);
            m.erase(key);
            addNode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
        
    }

    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node * eNode = m[key];
            m.erase(key);
            deleteNode(eNode);
        }
        if(m.size() == cap){
            m.erase(tail->prev->k);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
// 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */