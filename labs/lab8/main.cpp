#include <iostream>

template<typename T>
class Stack {
private:
    unsigned int m_ElementsCountMax;
    unsigned int m_ElementsCount = 0;
    T* container;
public:
    Stack(unsigned int size) {
        m_ElementsCountMax = size;
        container = new T[size];
    }

    ~Stack() {
        delete[] container;
    }

    int size() {
        return m_ElementsCount;
    }

    bool empty() {
        return m_ElementsCount == 0;
    }

    bool push(T element) {
        if (m_ElementsCount < m_ElementsCountMax) {
            container[m_ElementsCount] = element;
            m_ElementsCount++;
        }
        else
            throw std::overflow_error("Stack is full!");
    }

    T pop() {
        if (m_ElementsCount == 0) {
            throw std::out_of_range("Stack is empty!");
        }
        else {
            T element = container[0];
            for (int i = 0; i < m_ElementsCountMax - 1; i++) {
                container[i] = container[i + 1];
            }
            m_ElementsCount--;

            return element;
        }
    }

    void top() {
        if (m_ElementsCount == 0) {
            throw std::logic_error("Stack is empty!");
        }
        else
            std::cout << container[m_ElementsCount - 1] << std::endl;
    }
};


int main() {
    unsigned int size;
    std::cin >> size;
    try {
        Stack<int> stack(size);

        std::cout << "Size: " << stack.size() << std::endl;
        std::cout << "Is empty: " << (stack.empty() ? "Yes" : "No") << std::endl;

        for (int i = 1; i <= 3; i++)
            stack.push(i);
        std::cout << "Size after push: " << stack.size() << std::endl;
        std::cout << "Top number: "; stack.top();
        std::cout << "Is empty: " << (stack.empty() ? "Yes" : "No") << std::endl;

        stack.pop();
        std::cout << "Size after pop(): " << stack.size() << std::endl;
        std::cout << "Top number: "; stack.top();
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Too big number!\n" << e.what() << std::endl;
    }
    catch (const std::overflow_error& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << e.what() << std::endl;
    }
}