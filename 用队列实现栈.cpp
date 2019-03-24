//
// Created by marvinle on 2019/3/20 8:29 AM.
//

// leetcode 225

class MyStack {
public:
    // 两个队列实现栈，就是要永远在一个里push，然后pop的时候，向另外一个移动n-1个，然后pop出最后一      // 个, 永远只在q1 push， 每次pop完后就交换指针

    // 第二个思路就是只用一个队列，每次记录当前队列元素个数，然后pop n-1个，并且依次再push到队列末     // 尾即可
    /** Initialize your data structure here. */
    MyStack() {
        q1 = new queue<int>();
        q2 = new queue<int>();
    }

    /** Push element x onto stack. */
    void push(int x) {
        q1->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q1->size();
        for(int i = 0; i < size-1; i++){
            q2->push(q1->front());
            q1->pop();
        }
        int temp = q1->front();
        q1->pop();
        queue<int>* tq = q1;
        q1 = q2;
        q2 = tq;
        return temp;
    }

    /** Get the top element. */
    int top() {
        int size = q1->size();
        for(int i = 0; i < size-1; i++){
            q2->push(q1->front());
            q1->pop();
        }
        int temp = q1->front();
        q1->pop();
        q2->push(temp);
        queue<int> *tq = q1;
        q1 = q2;
        q2 = tq;
        return temp;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1->empty();
    }
private:
    queue<int> *q1;
    queue<int> *q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */