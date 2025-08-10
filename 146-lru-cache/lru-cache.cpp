#include <unordered_map>
using namespace std;

class LRUCache {
    struct Node {
        int key, val; Node *prev, *next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    void remove(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    void insertFront(Node* n) {
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
    }

public:
    LRUCache(int capacity): cap(capacity) {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail; tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* n = mp[key];
        remove(n);
        insertFront(n);
        return n->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* n = mp[key];
            n->val = value;
            remove(n);
            insertFront(n);
        } else {
            if (mp.size() == cap) {
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* n = new Node(key, value);
            insertFront(n);
            mp[key] = n;
        }
    }

    ~LRUCache() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */