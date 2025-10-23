#include <iostream>
using namespace std;
class Node {
public:
    int rollNo;
    Node* next;

    Node(int value) 
    {
        rollNo = value;
        next = nullptr;
    }
};
class LinkedList {
public:
    Node* head;
    LinkedList()
    {
        head = nullptr;
    }
    void insertAtstart(int rollNo)
    {
        Node* newNode = new Node(rollNo);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << rollNo << " at start \n";
    }
    void insertAtEnd(int rollNo)
    {
        Node* newNode = new Node(rollNo);
        if (head == nullptr) 
        {
            head = newNode;
        }
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << rollNo << " at the end.\n";
    }
    void insertAfter(int key, int rollNo)
    {
        Node* temp = head;
        while (temp != nullptr && temp->rollNo != key)
            temp = temp->next;
        if (temp == nullptr) 
        {
            cout << "Roll number " << key << " not found!\n";
            return;
        }
        Node* newNode = new Node(rollNo);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << rollNo << " after roll number " << key << ".\n";
    }

    void display() 
    {
        if (head == nullptr) 
        {
            cout << "List is empty-\n";
            return;
        }
        cout << "Student roll-umbers: ";
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->rollNo << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() 
{
    LinkedList list;
    int choice, rollNo, key;
    while (true)
    {
        cout << "\n------------Student rollo managemnt-----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Roll Number\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter roll number: ";
            cin >> rollNo;
            list.insertAtstart(rollNo);
            break;
        case 2:
            cout << "Enter roll number: ";
            cin >> rollNo;
            list.insertAtEnd(rollNo);
            break;
        case 3:
            cout << "Enter prsent  roll number ";
            cin >> key;
            cout << "Enter new roll number to add ";
            cin >> rollNo;
            list.insertAfter(key, rollNo);
            break;
        case 4:
            list.display();
            break;
        case 5:
            cout << "Exiting program...\n";
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    system("pause");
    return 0;
}
