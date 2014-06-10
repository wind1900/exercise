struct DListNode {
    DListNode *previous, *next;
    int key, value;
    DListNode(int k, int v) : key(k), value(v), next(NULL), previous(NULL) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        c = capacity;
        head = new DListNode(0, 0);
        last = new DListNode(0, 0);
        head->next = last;
        last->previous = head;
    }
    
    int get(int key) {
        if (m.count(key) == 0) return -1;
        front(m[key]);
        return m[key]->value;
    }
    
    void set(int key, int value) {
        if (m.count(key) > 0) {
            DListNode *n = m[key];
            n->value = value;
            front(n);
        }
        else if (m.size() < c) {
            DListNode *n = new DListNode(key, value);
            front(n);
            m[key] = n;
        } else {
            DListNode *p = last->previous;
            front(p);
            p->value = value;
            m.erase(p->key);
            p->key = key;
            m[key] = p;
        }
    }
    
private:
    int c;
    unordered_map<int, DListNode*> m;
    DListNode *head, *last;
    
    void front(DListNode *n) {
        if (n->previous)
            n->previous->next = n->next;
        if (n->next)
            n->next->previous = n->previous;
        n->next = head->next;
        n->previous = head;
        n->next->previous = n;
        head->next = n;
    }
};
