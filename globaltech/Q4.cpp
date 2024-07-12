// Design an algorithm to serialize and deserialize a binary tree. Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment. Implement the serialize and deserialize methods.
#include <bits/stdc++.h>
using namespace std;

#define MARKER -1

// A binary tree Node has key, 
// pointer to left and right children
struct Node {
	int key;
	struct Node *left, *right;
};


struct Node* newNode(int key)
{
	struct Node* temp = new Node();
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

void serialize(Node* root, FILE* fp)
{
	
	if (root == NULL) {
		fprintf(fp, "%d ", MARKER);
		return;
	}
	fprintf(fp, "%d ", root->key);
	serialize(root->left, fp);
	serialize(root->right, fp);
}


void deSerialize(Node*& root, FILE* fp)
{
	int val;
	if (!fscanf(fp, "%d ", &val) || val == MARKER)
		return;
	root = newNode(val);
	deSerialize(root->left, fp);
	deSerialize(root->right, fp);
}

void inorder(Node* root)
{
	if (root) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

// Driver code
int main()
{
	// Construct a tree shown in the above figure
	struct Node* root = newNode(40);
	root->left = newNode(18);
	root->right = newNode(22);
	root->left->left = newNode(34);
	root->left->right = newNode(42);
	root->left->right->left = newNode(50);
	root->left->right->right = newNode(64);

	// Open a file and serialize the tree into the file
	FILE* fp = fopen("tree.txt", "w");
	if (fp == NULL) {
		puts("Could not open file");
		return 0;
	}
	serialize(root, fp);
	fclose(fp);

	// Deserialize the stored tree into root1
	Node* root1 = NULL;
	fp = fopen("tree.txt", "r");
	deSerialize(root1, fp);

	printf("Inorder Traversal of the tree constructed from "
		"file:\n");
	inorder(root1);

	return 0;
    }