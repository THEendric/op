#include <iostream> 
#include <queue> 
  
class Queue { 
private: 
    std::queue<int> items; 
  
public: 
    void enqueue(int value) { 
        items.push(value); 
    } 
  
    void dequeue() { 
        if (!items.empty()) { 
            items.pop(); 
        } else { 
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl; 
        } 
    } 
  
    int front() const { 
        if (!items.empty()) { 
            return items.front(); 
        } else { 
            std::cerr << "Queue is empty. Cannot get front." << std::endl; 
            return -1;  // Return a sentinel value indicating an error 
        } 
    } 
  
    bool isEmpty() const { 
        return items.empty(); 
    } 
  
    size_t size() const { 
        return items.size(); 
    } 
}; 
  
int main() { 
    Queue myQueue; 
  
    myQueue.enqueue(1); 
    myQueue.enqueue(2); 
    myQueue.enqueue(3); 
  
    std::cout << "Front of the queue: " << myQueue.front() << std::endl; 
    std::cout << "Queue size: " << myQueue.size() << std::endl; 
  
    myQueue.dequeue(); 
    std::cout << "Front of the queue after dequeue: " << myQueue.front() << std::endl; 
  
    myQueue.dequeue(); 
    myQueue.dequeue(); 
  
    if (myQueue.isEmpty()) { 
        std::cout << "The queue is empty." << std::endl; 
    } 
  
    return 0; 
} 
