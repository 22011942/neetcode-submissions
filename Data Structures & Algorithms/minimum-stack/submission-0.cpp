class MinStack {
private:

std::vector<int> minStack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        minStack.push_back(val);
    }
    
    void pop() {
        minStack.pop_back();
    }
    
    int top() {
        return minStack.back();
    }
    
    int getMin() {
        return *std::min_element(minStack.begin(), minStack.end());
    }

};
