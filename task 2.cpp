#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
public:
    Node* head;
    int count;

    LinkedList() 
    {
        head = nullptr;
        count = 0;
    }
    void insertinEnd(int val) 
    {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        count++;
        cout << "Inserted " << val << " at end" << endl;
        cout << "Total nodes-- " << count << endl << endl;
    }
    void insertAfterValue(int value, int newValue)
    {
        Node* temp = head;

        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == nullptr) 
        {
            cout << "Value not found!" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data = newValue;
        newNode->next = temp->next;
        temp->next = newNode;

        count++;
        cout << "Inserted " << newValue << " after " << value << "." << endl;
        cout << "Total nodes: " << count << endl << endl;
    }
//display
    void display() 
    {
        Node* temp = head;

        cout << "Linked List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
 {
    LinkedList list;

    list.insertinEnd(10);
    list.insertinEnd(20);
    list.insertinEnd(30);

    list.display();
    list.insertAfterValue(20, 25);
    list.display();

    list.insertAfterValue(50, 60);

    system("pause");
    return 0;
}
