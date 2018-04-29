#include <bits/stdc++.h>

using namespace std;

template <class T>
class Queue {
private:
  vector<T> queue;
public:
  void enqueue(T el) {
    queue.push_back(el);
  }

  T dequeue() {
    // remove from front of the list
    T data = queue.front();
    queue.erase(queue.begin());
    return data;
  }

  vector<T> get_queue() { return queue; }

  friend ostream& operator<<(ostream& output, Queue<T> q) {
    vector<T> q_vec = q.get_queue();
    for (auto el : q_vec) { 
      output << el << " ";
    }
    return output;
  }

};

int main() {
  Queue<int> nums;
  nums.enqueue(1);
  nums.enqueue(2);

  cout << nums << endl;

  cout << nums.dequeue() << endl;

  cout << nums << endl;
  return 0;
}
  
