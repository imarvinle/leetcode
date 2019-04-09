//
// Created by marvinle on 2019/4/9 9:38 PM.
//
#include <stack>
#include <iostream>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (data.empty()){
           helper.push(x);
        } else {
            helper.push(x < helper.top() ? x : helper.top());
        }
        data.push(x);
    }

    void pop() {
        data.pop();
        helper.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return helper.top();
    }

private:
    stack<int> data;
    stack<int> helper;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */