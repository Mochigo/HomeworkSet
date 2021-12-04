#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode()
        : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value)
        : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
   private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
    int missPage;

   public:
    LRUCache(int _capacity)
        : capacity(_capacity), size(0), missPage(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            this->missPage++;

            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();

                cout << removed->key << " ";

                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            } else {
                cout << "  ";
            }
        } else {
            cout << "  ";

            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

    void putDataAndRun(vector<int>& data) {
        cout << "LRU" << endl;
        for (auto& it : data) {
            cout << it << " ";
        }
        cout << endl;
        for (auto& it : data) {
            this->put(it, 1);
        }
        cout << endl;
        cout << "缺页次数: " << this->missPage << endl;
        cout << "缺页终端率: " << this->missPage * 1.0 / data.size() << endl;
    }
};

class FIFOCache {
   private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
    int missPage;

   public:
    FIFOCache(int _capacity)
        : capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    bool get(int key) {
        if (!cache.count(key)) {
            return false;
        }
        return true;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            this->missPage++;
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();

                cout << removed->key << " ";

                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            } else {
                cout << "  ";
            }
        } else {
            cout << "  ";
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

    void putDataAndRun(vector<int>& data) {
        cout << "FIFO " << endl;
        for (auto& it : data) {
            cout << it << " ";
        }
        cout << endl;
        for (auto& it : data) {
            this->put(it, 1);
        }
        cout << endl;
        cout << "缺页次数: " << this->missPage << endl;
        cout << "缺页终端率: " << this->missPage * 1.0 / data.size() << endl;
    }
};

int main() {
    vector<int> data;
    ifstream read;
    read.open("data.txt");
    if (!read.is_open()) {
        cout << "open file error" << endl;
        return 0;
    }
    int c;
    while (true) {
        read >> c;
        if (read.eof()) {
            break;
        }
        data.push_back(c);
    }
    read.close();

    LRUCache lru(3);
    lru.putDataAndRun(data);

    cout << endl;

    FIFOCache fifo(3);
    fifo.putDataAndRun(data);

    return 0;
}