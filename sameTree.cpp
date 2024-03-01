// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  public:
    TreeNode() {
      val = 0;
      left = nullptr;
      right = nullptr;
    }

    TreeNode(int x) {
      val = x;
      left = nullptr;
      right = nullptr;
    }
    TreeNode(int x, TreeNode* leftNode, TreeNode* rightNode) {
      val = x;
      left = leftNode;
      right = rightNode;
    }
};

bool isSameTree(TreeNode* p, TreeNode* q) {
  if(p == nullptr && q == nullptr) {
    return true;
  }
  else if(p == nullptr && q != nullptr) {
    return false;
  }
  else if(p != nullptr && q == nullptr) {
    return false;
  }
  // If current nodes are equivalent, return recursive check for their children
  else if(p->val == q->val) {
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
  else {
    return false;
  }
}

int main() {
  cout << "    TEST CASES:    " << endl;

  // TEST CASE 1

  // Tree 1
  TreeNode* p = new TreeNode(1);
  p-> left = new TreeNode(2);
  p->right = new TreeNode(3);
  // Tree 2
  TreeNode* q = new TreeNode(1);
  q-> left = new TreeNode(2);
  q->right = new TreeNode(3);

  if(isSameTree(p,q) == true) {
    cout << "Test Case 1: Correct" << endl;
  }
  else if(isSameTree(p,q) != true) {
    cout << "Test Case 1: Incorrect" << endl;
  }


  // TEST CASE 2

  // Tree 1
  TreeNode* a = new TreeNode(1);
  a-> left = new TreeNode(2);
  // Tree 2
  TreeNode* b = new TreeNode(1);
  b-> right = new TreeNode(2);

  if(isSameTree(a,b) == false) {
    cout << "Test Case 2: Correct" << endl;
  }
  else if(isSameTree(a,b) != true) {
    cout << "Test Case 2: Incorrect" << endl;
  }


  // TEST CASE 3

  // Tree 1
  TreeNode* x = new TreeNode(1);
  x-> left = new TreeNode(2);
  x->right = new TreeNode(1);
  // Tree 2
  TreeNode* y = new TreeNode(1);
  y-> left = new TreeNode(1);
  y->right = new TreeNode(2);

  if(isSameTree(x,y) == false) {
    cout << "Test Case 3: Correct" << endl;
  }
  else if(isSameTree(x,y) != true) {
    cout << "Test Case 3: Incorrect" << endl;
  }

}