#include <iostream> 
#include <stack> 
#include <sstream> 
  
int evaluateExpression(const std::string& expression) { 
    std::stack<int> stack; 
    std::istringstream iss(expression); 
  
    while (!iss.eof()) { 
        std::string token; 
        iss >> token; 
  
        if (token[0] >= '0' && token[0] <= '9') { 
            stack.push(std::stoi(token)); 
        } else { 
            int operand2 = stack.top(); 
            stack.pop(); 
            int operand1 = stack.top(); 
            stack.pop(); 
  
            switch (token[0]) { 
                case '+': 
                    stack.push(operand1 + operand2); 
                    break; 
                case '-': 
                    stack.push(operand1 - operand2); 
                    break; 
                case '*': 
                    stack.push(operand1 * operand2); 
                    break; 
                case '/': 
                    stack.push(operand1 / operand2); 
                    break; 
                default: 
                    std::cerr << "Invalid operator: " << token << std::endl; 
                    return -1;  // Return a sentinel value indicating an error 
            } 
        } 
    } 
  
    return stack.top(); 
} 
  
int main() { 
    std::string prefixExpression = "+ 5 * 3 4"; 
    std::string postfixExpression = "5 3 4 * +"; 
  
    std::cout << "Prefix Expression Result: " << evaluateExpression(prefixExpression) << std::endl; 
    std::cout << "Postfix Expression Result: " << evaluateExpression(postfixExpression) << std::endl; 
  
    return 0; 
} 
 
