#include <bits/stdc++.h>

using namespace std;

template <class T>
class TreeNode {
public:
  T val;
  shared_ptr<TreeNode<T>> left;
  shared_ptr<TreeNode<T>> right;
  shared_ptr<TreeNode<T>> parent;
  TreeNode<T>(T val): val(val), left(NULL), right(NULL), parent(NULL) {}
};

template <class T>
void generateTree(shared_ptr<TreeNode<T>> &head, T val) {
  if (head == NULL) {
    shared_ptr<TreeNode<T>> ptr(new TreeNode<T>(val));
    head.swap(ptr);
  } else {
    if (val < head->val) {
      generateTree(head->left, val);
      head->left->parent = head;
    } else {
      generateTree(head->right, val);
      head->right->parent = head;
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
  while (head->left != NULL) {
    head = head->left;
  }
  return head;
}

template <class T>
shared_ptr<TreeNode<T>> treeMinRec(shared_ptr<TreeNode<T>> head) {
  if (head->left == NULL) {
    return head;
  }
  return treeMinRec(head->left);
}

template <class T>
shared_ptr<TreeNode<T>> treeMaximum(shared_ptr<TreeNode<T>> head) {
  while (head->right != NULL) {
    head = head->right;
  }
  return head;
}

template <class T>
shared_ptr<TreeNode<T>> treeMaxRec(shared_ptr<TreeNode<T>> head) {
  if (head->right == NULL) {
    return head;
  }
  return treeMaxRec(head->right);
}

template <class T>
shared_ptr<TreeNode<T>> treeSuccessor(shared_ptr<TreeNode<T>> head) {
  if (head->right != NULL) {
    // minimum on the right subtree will be the successor
    // if it exists
    return treeMinimum(head->right);
  }
  shared_ptr<TreeNode<T>> y = head->parent;
  while (y != NULL && head->val == y->right->val) {
    head = y;
    y = y->parent;
  }

  return y;

}

template <class T>
shared_ptr<TreeNode<T>> treePredecessor(shared_ptr<TreeNode<T>> head) {
  if (head->left != NULL) {
    // max on the left subtree is predecessor
    return treeMaximum(head->left);
  }
  shared_ptr<TreeNode<T>> y = head->parent;
  while (y != NULL && head->val == y->left->val) {
    head = y;
    y = y->parent;
  }

  return y;
}

int main() {

  shared_ptr<TreeNode<int>> head(new TreeNode<int>(5));
  generateTree(head, 6);
  generateTree(head, 1);
  generateTree(head, -3);
  generateTree(head, 4);

  //inOrderWalk(head);
  //preOrderWalk(head);
  //levelOrderWalk(head);

  cout << treeMinRec(head)->val << endl;
  //cout << treeSuccessor(head->left->right)->val << endl;
  //cout << treePredecessor(head->left->right)->val << endl;


  return 0;
}