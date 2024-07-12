//Given a non-empty binary tree, find the maximum path sum. A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.The function should return an integer representing the maximum path sum.
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
   
    int findMaxPathSum(Node* root, int &maxi) {
        
        if (root == nullptr) {
            return 0;
        }
        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));
        maxi = max(maxi, leftMaxPath + rightMaxPath + root->data);
        return max(leftMaxPath, rightMaxPath) + root->data;
    }

    
    int maxPathSum(Node* root) {
        int maxi = INT_MIN; 
        findMaxPathSum(root, maxi);
        return maxi; 
    }
};


int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->left->right->right = new Node(9);
    root->left->right->right->right = new Node(34);

    // Creating an instance of the Solution class
    Solution solution;

    // Finding and printing the maximum path sum
    int maxPathSum = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << maxPathSum << endl;


    return 0;
}