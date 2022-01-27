class MinStack {
public:
    
    stack<int>minstack;
    stack<int>stk;
    
    void push(int val)
    {
        stk.push(val);
        if(minstack.size() == 0 || val <= minstack.top())     
            minstack.push(val);
    }
    
    void pop()
    {
        if(minstack.top() == stk.top() && minstack.empty() == false)
            minstack.pop();
        
        if(stk.empty() == false)
            stk.pop();
    }
    
    int top()
    {
        return stk.top();
    }
    
    int getMin()
    {
        return minstack.top();    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */