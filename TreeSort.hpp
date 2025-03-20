//
// Source from https://www.geeksforgeeks.org/tree-sort/
//
using namespace std; 
  
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new BST Node 
struct Node *newNode(int item) 
{ 
    struct Node *temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = nullptr; 
    return temp; 
} 
  
// Stores inorder traversal of the BST 
// in arr[] 
void storeSorted(Node *root, std::vector<int>& arr, int &i) 
{ 
    if (root != nullptr) 
    { 
        storeSorted(root->left, arr, i); 
        arr[i++] = root->key; 
        storeSorted(root->right, arr, i); 
    } 
} 
  
/* A utility function to insert a new 
   Node with given key in BST */
Node* insert(Node* node, int key) 
{ 
    /* If the tree is empty, return a new Node */
    if (node == nullptr) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) Node pointer */
    return node; 
} 
  
// This function sorts arr[0..n-1] using Tree Sort 
void treeSort(std::vector<int>& arr) 
{ 
    int n = (int)arr.size();
    struct Node *root = nullptr; 
  
    // Construct the BST 
    root = insert(root, arr[0]); 
    for (int i=1; i<n; i++) 
        root = insert(root, arr[i]); 
  
    // Store inorder traversal of the BST 
    // in arr[] 
    int i = 0; 
    storeSorted(root, arr, i); 
} 