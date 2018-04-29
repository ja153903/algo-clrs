#include <bits/stdc++.h>

using namespace std;

template <class T>
class TreeNode {
public:
  T val;
  shared_ptr<TreeNode<T>> left;
  shared_ptr<TreeNode<T>> right;
  TreeNode<T>(T val): val(val), left(NULL), right(NULL) {}
};

template <class T>
void generateTree(shared_ptr<TreeNode<T>> &head, T val) {
  if (head == NULL) {
    shared_ptr<TreeNode<T>> ptr(new TreeNode<T>(val));
    head.swap(ptr);
  } else {
    if (val < head->val) {
      generateTree(head->left, val);
    } else {
      generateTree(head->right, val);
    }
  }
}

template <class T>
void inOrderWalk(shared_ptr<TreeNode<T>> head) {
  if (head != NULL) {
    inOrderWalk(head->left);
    cout << head->val << endl;
    inOrderWalk(head->right);
  }
}

template <class T>
void preOrderWalk(shared_ptr<TreeNode<T>> head) {
  if (head != NULL) {
    cout << head->val << endl;
    preOrderWalk(head->left);
    preOrderWalk(head->right);
  }
}

template <class T>
void postOrderWalk(shared_ptr<TreeNode<T>> head) {
  if (head != NULL) {
    postOrderWalk(head->left);
    postOrderWalk(head->right);
    cout << head->val << endl;
  }
}

template <class T>
void levelOrderWalk(shared_ptr<TreeNode<T>> head) {
  if (head == NULL) { return; }
  queue<shared_ptr<TreeNode<T>>> q;
  q.push(head);
  while (!q.empty()) {
    shared_ptr<TreeNode<T>> front = q.front();
    q.pop();

    cout << front->val << endl;
    
    if (front->left) q.push(front->left);
    if (front->right) q.push(front->right);
  }
}

template <class T>
shared_ptr<TreeNode<T>> search(shared_ptr<TreeNode<T>> head, T target) {
  if (head == NULL || head->val == target) {
    return head;
  }
  if (target < head->val) {
    return search(head->left, target);
  }

  return search(head->right, target);
}

template <class T>
shared_ptr<TreeNode<T>> treeMinimum(shared_ptr<TreeNode<T>> head) {
  while (head != NULL) {
    head = head->left;
  }
  return head;
}

template <class T>
shared_ptr<TreeNode<T>> treeMaximum(shared_ptr<TreeNode<T>> head) {
  while (head != NULL) {
    head = head->right;
  }
  return head;
}

int main() {

  shared_ptr<TreeNode<int>> head(new TreeNode<int>(5));
  generateTree(head, 6);
  generateTree(head, 1);
  generateTree(head, -3);
  generateTree(head, 4);

  //inOrderWalk(head);
  //preOrderWalk(head);
  levelOrderWalk(head);


  return 0;
}