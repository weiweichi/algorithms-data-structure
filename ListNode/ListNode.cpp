#include <unordered_map>
using namespace std;
struct ListNode {
    int key;
    int value;
    ListNode *next, *prev;

    ListNode() : key(0), value(0), next(nullptr), prev(nullptr) {}
    ListNode(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
    ListNode(int key, int value, ListNode* next, ListNode* prev) : key(key), value(value), next(next), prev(prev) {}
    ~ListNode() {delete next, prev;}
};

class LRUCache {
public:

    LRUCache(int capacity) {
        size = capacity;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail, tail->prev = head;
    }
    ~LRUCache() {
        while (head != tail) {
            head = head->next;
            delete head->prev;
        }
        delete head;
    }
    
    int get(int key) {
        if (memo.count(key)){
            _remove(memo[key]);
            _insert(memo[key]);
            return memo[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        ListNode *node;
        if (memo.count(key) || size == 0) {
            node = memo.count(key) ? memo[key] : tail->prev;
            memo.erase(node->key);
            _remove(node);
            node->key = key;
            node->value = value;
        } else {
            node = new ListNode(key, value);
            size--;
        }
        memo[key] = node;
        _insert(node);
    }
    
    void _remove(ListNode *node) {
        ListNode *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void _insert(ListNode *node) {
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }
private:
    int size=0;
    ListNode *head, *tail;
    unordered_map<int, ListNode*> memo;
};
