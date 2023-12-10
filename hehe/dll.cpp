#include <iostream> 
  
class Node { 
public: 
    int data; 
    Node* next; 
    Node* prev; 
  
    Node(int value) : data(value), next(nullptr), prev(nullptr) {} 
}; 
  
class DoublyLinkedList { 
private: 
    Node* head; 
    Node* tail; 
  
public: 
    DoublyLinkedList() : head(nullptr), tail(nullptr) {} 
  
    void insertAtBeginning(int x) { 
        Node* newNode = new Node(x); 
  
        if (!head) { 
            head = tail = newNode; 
        } else { 
            newNode->next = head; 
            head->prev = newNode; 
            head = newNode; 
        } 
    } 
  
    void insertAtEnd(int x) { 
        Node* newNode = new Node(x); 
  
        if (!tail) { 
            head = tail = newNode; 
        } else { 
            newNode->prev = tail; 
            tail->next = newNode; 
            tail = newNode; 
        } 
    } 
  
    void removeFromBeginning() { 
        if (!head) { 
            std::cout << "List is empty. Cannot remove from beginning." << std::endl; 
            return; 
        } 
  
        Node* temp = head; 
        head = head->next; 
  
        if (head) { 
            head->prev = nullptr; 
        } else { 
            tail = nullptr; // If the list becomes empty 
        } 
  
        delete temp; 
    } 
  
    void removeFromEnd() { 
        if (!tail) { 
            std::cout << "List is empty. Cannot remove from end." << std::endl; 
            return; 
        } 
  
        Node* temp = tail; 
        tail = tail->prev; 
  
        if (tail) { 
            tail->next = nullptr; 
        } else { 
            head = nullptr; // If the list becomes empty 
        } 
  
        delete temp; 
    } 
  
    void display() { 
        Node* current = head; 
        while (current) { 
            std::cout << current->data << " <-> "; 
            current = current->next; 
        } 
        std::cout << "nullptr" << std::endl; 
    } 
}; 
  
int main() { 
    DoublyLinkedList linkedList; 
  
    linkedList.insertAtBeginning(3); 
    linkedList.insertAtBeginning(2); 
    linkedList.insertAtBeginning(1); 
    linkedList.display();   
  
    linkedList.insertAtEnd(4); 
    linkedList.display();   
  
    linkedList.removeFromBeginning(); 
    linkedList.display();   
  
    linkedList.removeFromEnd(); 
    linkedList.display();   
  
    return 0; 
} 
