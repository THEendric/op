#include <iostream> 
  
class Node { 
public: 
    int data; 
    Node* next; 
  
    Node(int value) : data(value), next(nullptr) {} 
}; 
  
class CircularLinkedList { 
private: 
    Node* head; 
  
public: 
    CircularLinkedList() : head(nullptr) {} 
  
    void insertElement(int x) { 
        Node* newNode = new Node(x); 
  
        if (!head) { 
            head = newNode; 
            head->next = head; // Point to itself to form a circular link 
        } else { 
            Node* temp = head; 
            while (temp->next != head) { 
                temp = temp->next; 
            } 
  
            temp->next = newNode; 
            newNode->next = head; 
        } 
    } 
  
    void removeElement(int x) { 
        if (!head) { 
            std::cout << "List is empty. Cannot remove element." << std::endl; 
            return; 
        } 
  
        Node* current = head; 
        Node* prev = nullptr; 
  
        // Find the node to remove 
        do { 
            if (current->data == x) { 
                break; 
            } 
            prev = current; 
            current = current->next; 
        } while (current != head); 
  
        // If the node is found 
        if (current == head) { 
            // If there is only one node 
            if (current->next == head) { 
                delete current; 
                head = nullptr; 
            } else { 
                // Remove the head and update the last node's next pointer 
                prev->next = head->next; 
                if (current == head) { 
                    head = head->next; 
                } 
                delete current; 
            } 
        } else { 
            // If the node is in the middle of the list 
            prev->next = current->next; 
            delete current; 
        } 
    } 
  
    Node* searchElement(int x) { 
        if (!head) { 
            std::cout << "List is empty. Cannot search for element." << std::endl; 
            return nullptr; 
        } 
  
        Node* current = head; 
  
        do { 
            if (current->data == x) { 
                return current; 
            } 
            current = current->next; 
        } while (current != head); 
  
        std::cout << "Element not found in the list." << std::endl; 
        return nullptr; 
    } 
  
    void display() { 
        if (!head) { 
            std::cout << "List is empty." << std::endl; 
            return; 
        } 
  
        Node* current = head; 
        do { 
            std::cout << current->data << " -> "; 
            current = current->next; 
        } while (current != head); 
  
        std::cout << "Head" << std::endl; 
    } 
}; 
  
int main() { 
    CircularLinkedList circularList; 
  
    circularList.insertElement(1); 
    circularList.insertElement(2); 
    circularList.insertElement(3); 
    circularList.display();  
  
    circularList.removeElement(2); 
    circularList.display();   
  
    Node* result = circularList.searchElement(3); 
    if (result) { 
        std::cout << "Element found in the list: " << result->data << std::endl; 
    } 
  
    return 0; 
} 
