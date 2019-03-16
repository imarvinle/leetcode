//
// Created by marvinle on 2019/3/16 12:29 AM.
//

// leetcode 232

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s2.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = peek();
        s1.pop();
        return temp;
    }

    /** Get the front element. */
    int peek() {
        if(!s1.empty())
            return s1.top();
        else if(!s2.empty()) {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            return s1.top();
        }
        return -1;
    }

    /** Returns whether the queue is empty. */
    // 同时为空才是真的空
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
