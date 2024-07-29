class MyStack {
public:
    queue<int> qe;
    MyStack() {
        
    }
    
    void push(int x) {
        qe.push(x);
        int si = qe.size()-1;
        for(int i=0;i<si;i++)
        {
            qe.push(qe.front());
            qe.pop();
        }
    }
    
    int pop() {
        int temp = qe.front();
        qe.pop();
        return temp;
    }
    
    int top() {
        return qe.front();
    }
    
    bool empty() {
        return (qe.empty()) ? true : false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
