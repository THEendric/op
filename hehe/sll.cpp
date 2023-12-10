#include <iostream> 
  
class Node { 
public: 
    int data; 
    Node* next; 
  
    Node(int value) : data(value), next(nullptr) {} 
}; 
  
class SinglyLinkedList { 
private: 
    Node* head; 
  
public: 
    SinglyLinkedList() : head(nullptr) {} 
  
    void insertAtBeginning(int x) { 
        Node* newNode = new Node(x); 
        newNode->next = head; 
        head = newNode; 
    } 
  
    void insertAtPosition(int x, int position) { 
        if (position == 0 || !head) { 
            insertAtBeginning(x); 
            return; 
        } 
  
        Node* newNode = new Node(x); 
        Node* current = head; 
  
        for (int i = 0; i < position - 1 && current->next; ++i) { 
            current = current->next; 
        } 
  
        newNode->next = current->next; 
        current->next = newNode; 
    } 
  
    void removeFromBeginning() { 
        if (!head) { 
            std::cout << "List is empty. Cannot remove from beginning." << std::endl; 
            return; 
        } 
  
        Node* temp = head; 
        head = head->next; 
        delete temp; 
    } 
  
    void removeFromPosition(int position) { 
        if (!head) { 
            std::cout << "List is empty. Cannot remove from position." << std::endl; 
            return; 
        } 
  
        if (position == 0) { 
            removeFromBeginning(); 
            return; 
        } 
  
        Node* current = head; 
  
        for (int i = 0; i < position - 1 && current->next; ++i) { 
            current = current->next; 
        } 
  
        if (!current->next) { 
            std::cout << "Invalid position" << std::endl; 
            return; 
        } 
  
        Node* temp = current->next; 
        current->next = current->next->next; 
        delete temp; 
    } 
  
    Node* searchElement(int x) { 
        Node* current = head; 
  
        while (current && current->data != x) { 
            current = current->next; 
        } 
  
        return current; 
    } 
  
    void display() { 
        Node* current = head; 
        while (current) { 
            std::cout << current->data << " -> "; 
            current = current->next; 
        } 
        std::cout << "nullptr" << std::endl; 
    } 
}; 
  
int main() { 
    SinglyLinkedList linkedList; 
  
    linkedList.insertAtBeginning(3); 
    linkedList.insertAtBeginning(2); 
    linkedList.insertAtBeginning(1); 
    linkedList.display();   
  
    linkedList.insertAtPosition(4, 1); 
    linkedList.display();   
  
    linkedList.removeFromBeginning(); 
    linkedList.display();   
  
    linkedList.removeFromPosition(1); 
    linkedList.display();   
  
    Node* result = linkedList.searchElement(3); 
    if (result) { 
        std::cout << "Element found at position: " << result->data << std::endl; 
    } else { 
        std::cout << "Element not found" << std::endl; 
    } 
  
    return 0; 
} 
 
 
