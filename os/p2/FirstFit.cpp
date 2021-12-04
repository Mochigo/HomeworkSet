#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct BlockNode {
    int start;
    int size;
    BlockNode *next, *prev;
    BlockNode()
        : start(0), size(0), next(nullptr), prev(nullptr) {}
    BlockNode(int _start, int _size)
        : start(_start), size(_size), next(nullptr), prev(nullptr) {}
};

class FirstFit {
   private:
    BlockNode* head;
    BlockNode* tail;

   public:
    FirstFit() {
        head = new BlockNode();
        tail = new BlockNode();
        head->next = tail;
        tail->prev = head;
    }

    void AddNewBlock(int start, int size) {
        BlockNode* node = new BlockNode(start, size);
        BlockNode* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;

        cout << "新增分区!" << endl;
        printf("分区起始地址为 %p ", (void*)start);
        printf("分区大小为 %d\n", size);
    }

    BlockNode* getBlock(int need) {
        for (BlockNode* node = head->next; node != tail; node = node->next) {
            if (node->size >= need) {
                return node;
            }
        }

        return nullptr;
    }

    void allocate(int need) {
        BlockNode* node = this->getBlock(need);
        if (node == nullptr) {
            cout << "空间不足，无法分配" << endl;
            return;
        }
        node->size -= need;
        printf("分配空间起始地址为%p, 结束地址为%p\n", (void*)node->start, (void*)(node->start + need));
        node->start += need;
        printf("剩余空间大小为%d, 该分区的剩余空间的起始地址为%p\n", node->size, (void*)node->start);
    }

    void show() {
        BlockNode* cur = head->next;
        while (cur != this->tail) {
            printf("%p %p\n", (void*)cur->start, (void*)(cur->start + cur->size));
            cur = cur->next;
        }
    }

    void Free() {
        BlockNode* cur = head->next;
        BlockNode* next;
        while (cur != tail) {
            next = cur->next;
            delete cur;
            cur = next;
        }

        delete cur;
        delete head;
    }
};

int main() {
    int blockNum;
    cout << "请输入分区的数量: ";
    cin >> blockNum;

    FirstFit ff;
    int size, start;

    for (int i = 1; i <= blockNum; i++) {
        cout << "请输入分区的起始地址和大小:" << endl;
        cin >> start >> size;

        ff.AddNewBlock(start, size);
    }

    // ff.show();

    int need;
    while (true) {
        cout << "请输入预申请的内存大小: ";
        if (scanf("%d", &need) == 0) {
            cout << "Invalid input" << endl;
            return 0;
        }

        ff.allocate(need);
    }

    ff.Free();
}