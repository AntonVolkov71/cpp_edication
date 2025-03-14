#include <cassert>
#include <stack>

using namespace std;

// моделируем очередь с помощью двух стеков
template <class T>
class QueueFromStack {
public:
    void Push(const T& e) {
        stack1_.push(e);
    }

    T Pop() {
        if (stack2_.empty()) {
            while (!stack1_.empty()) {
                stack2_.push(stack1_.top());
                stack1_.pop();
            }
        }

        assert(!stack2_.empty());

        T top = stack2_.top();
        stack2_.pop();
        return top;
    }

private:
    stack<T> stack1_;
    stack<T> stack2_;
};

int main() {
    QueueFromStack<int> q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    assert(q.Pop() == 1);
    assert(q.Pop() == 2);
    assert(q.Pop() == 3);
    assert(q.Pop() == 4);
}