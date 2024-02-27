// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return 
// the subtree rooted with that node. If such a node does not exist, return null.



// Given definition of BST
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
  // Return Null if the root is a nullptr
  if(root == nullptr) {
    return root;
  }

  // Return the root if the value is found
  if(root->val == val) {
    return root;
  } 

  // Recursively search left subtree when root val < val
  if(root->val > val) {
    return searchBST(root->left, val);
  }

  // Recursively search right subtree when the root val > val
  if(root->val < val) {
    return searchBST(root->right, val);
  }

  return nullptr;
}

