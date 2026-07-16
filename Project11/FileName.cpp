#include <iostream>
using namespace std;

class Node {
public:
    int data; // 修改：建议将 date 改为 data
    Node* next;

    // 构造函数：val 默认为 0，next 默认为空
    Node(int val = 0) {
        data = val;
        next = nullptr; // 建议使用 nullptr 代替 0，更现代、更安全
    }
};

class linked_list {
private:
    Node* head;

public:
    linked_list() {
        head = nullptr;
    }

    // 析构函数：写得很好！负责释放所有内存，防止泄漏
    ~linked_list() {
        Node* current = head;
        while (current != nullptr) {
            Node* next_Node = current->next;
            delete current;
            current = next_Node;
        }
    }

    void append(int val) {
        Node* newNode = new Node(val);

        // 【修改点 1】如果是空链表，新节点就是头节点
        // 原代码是 if (head = 0)，这是赋值，必须改成 == 或者 !head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // 如果不是空链表，遍历到最后一个节点
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // 【修改点 2】关键步骤：把尾节点的 next 指向新节点
        // 原代码漏掉了这一行，导致新节点没连上去
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> "; // 修改：对应 data 变量名
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    linked_list myList;

    myList.append(10);
    myList.append(20);
    myList.append(30);

    // 预期输出：10 -> 20 -> 30 -> NULL
    myList.display();

    return 0;
}