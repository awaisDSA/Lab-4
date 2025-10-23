#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;
    int count;

    LinkedList() {
        head = nullptr;
        count = 0;
    }

    void insertAtEnd(int val)
    {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) 
        {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        count++;
        cout << "Inserted " << val << " at end " << endl;
        cout << "Total nodes-- " << count << endl << endl;
    }

    void display()
    {
        Node* temp = head;

        cout << "Linked List -- ";
        while (temp != nullptr)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    int countNodes() 
    {
        return count;
    }
};

int main()
{
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.display();

    cout << "Final total nodes: " << list.countNodes() << endl;

    system("pause");
    return 0;
}
