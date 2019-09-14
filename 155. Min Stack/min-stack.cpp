class MinStack {
public:
    
    stack<int> value;
    stack<int> support;
    
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        value.push(x);
        if(support.empty()){
            support.push(x);
        }
        else{
            support.push(min(support.top(), x));
        }
        
    }
    
    void pop() {
        value.pop();
        support.pop();
    }
    
    int top() {
        return value.top();
    }
    
    int getMin() {
        return support.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */