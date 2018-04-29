#include <bits/stdc++.h>

using namespace std;

// implementing stacks using vectors

template<class T>
class Stack {
private:
  vector<T> stack;
public:
  bool stack_empty() {
    return stack.empty();
  }

  void push(T el) {
    stack.push_back(el);
  }

  T pop() {
    try {
      int data = stack.back();
      stack.pop_back();
      return data;
    } catch(const exception& e) {
      cout << e.what() << endl;
    }
  }

  vector<T> get_stack() {
    return stack;
  }

  friend ostream& operator<<(ostream& output, Stack<T> stk) {
    vector<T> s = stk.get_stack();
    for (auto el : s) {
      output << el << " ";
    }
    return output;
  }

};

int main() {
  Stack<int> int_stack;

  int_stack.push(1);
  int_stack.push(2);
  int_stack.push(4);

  cout << int_stack << endl;

  int_stack.pop();
  int_stack.pop();
  int_stack.pop();

  return 0;
}
