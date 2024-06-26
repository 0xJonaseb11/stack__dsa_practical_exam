#include <iostream>
#include <string>

class Stack {

private:

    static const int MAX = 1000;
    char arr[MAX];
    int top;
public:
    Stack() : top(-1) {}
    bool push(char c) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow" << std::endl;
            return false;
        } else {
            arr[++top] = c;
            return true;
        }
    }
    char pop() {
        if (top < 0) {
            std::cout << "Stack Underflow" << std::endl;
            return '\0';
        } else {
            return arr[top--];
        }
    }
    bool isEmpty() {
        return (top < 0);
    }
};

int main() {

    Stack stack;
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    std::cout << "Original string: " << str << std::endl;

    // Push all characters of the string into the stack
    for (char c : str) {
        stack.push(c);
    }

    // Pop all characters from the stack and store them back in the string
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = stack.pop();
    }

    std::cout << "Reversed string: " << str << std::endl;
    return 0;
}