/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

class Queue {
private:
    stack<int> stk1, stk2;
public:
    // Push element x to the back of queue.
    /*
    用两个栈实现队列
    规定：
        stk1为输入栈，这只是个临时栈，顺序与最终期望的顺序恰好相反
        stk2为输出栈，里面的元素以最终所期望的顺序输出
    */
    void push(int x) {
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        stk1.push(x);
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stk2.pop();
    }

    // Get the front element.
    int peek(void) {
        return stk2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk2.empty() ? true : false;
    }
};