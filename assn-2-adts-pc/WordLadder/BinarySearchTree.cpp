#include "BinarySearchTree.h"
#include "genlib.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
#include <iostream>

struct node
{
	int data;
	struct node* left; 
	struct node* right;
};

static node* CreateNode(int data)
{
	struct node* node = new (struct node);
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return node;
}

static node* InsertNode(struct node* node, int data)
{
	if(node == NULL)
		return CreateNode(data);
	if(data == node->data)
		return node;
	else
	{
		if(data <= node->data)
		{
			node->left = InsertNode(node->left, data);
		}
		else 
			node->right = InsertNode(node->right, data);
		return node;
	}
}

static node* CreateBinaryTree(node* node, int low, int high)
{
	
}

struct node * CreateBinaryTree(int leftIndex, int rightIndex) {
	if (rightIndex < leftIndex) {
		return NULL;
	}
	int current = (leftIndex + rightIndex)/2;
	node* tree = (node*)malloc(sizeof(struct node));
	tree->data = current;
	tree->left = CreateBinaryTree(leftIndex, current - 1);
	tree->right = CreateBinaryTree(current + 1, rightIndex);
	return tree;
}

//Create a plain Binary Tree of specified size eg of size 10. Create a binary tree from 1 to 10 values	
static node* CreateBinaryTree(int size)
{
	return CreateBinaryTree(0, size -1);
}

static int lookup(struct node* node, int target)
{
	if(node == NULL)
		return 0;
	else
	{
		if(target == node->data)
			return true;
		if(target < node->data)
			return lookup(node->left, target);
		else 
			return lookup(node->right, target);
	}
}

// Given a binary tree count the number of nodes (Recursive)
static int size(node* node)
{
	if(node == NULL)
		return 0;
	return 1 + size(node->left) + size(node->right);
}

//Given a binary tree, compute its "maxDepth" -- the number of nodes along the longest path from the root node down to the farthest leaf node
int maxDepth(node* node)
{
	if(node == NULL)
		return 0;
	else
	{
		int ldepth = maxDepth(node->left);
		int rdepth = maxDepth(node->right);
		if(ldepth > rdepth)
			return ldepth + 1;
		else
		{
			return rdepth + 1;
		}
	}
}

// Assuming -9999 doesnt exist in the node as a value and if node is null we return that value
int minValue(node * node)
{
	struct node* current = node;
	if(node == NULL)
		return -9999;
	else
	{
		while(current->left != NULL)
		{
			current = current->left;
		}
		return current->data;
	}
}

// Given a binary tree count the number of nodes (Recursive)
static int sizeItr(node* node)
{
	int count = 0; 
	if(node == NULL)
		return 0;
	while(node != NULL)
	{
		count = count + 1;
		if(node->left != NULL)
			count += 1;
		if(node->right != NULL)
			count += 1;
	}
}


void printTree(struct node* node)
{
	if(node == NULL)
		return;
	else
	{
		printTree(node->left);
		cout << node->data;
		printTree(node->right);
	}
}

void printPostOrderTree(struct node* node)
{
	if(node == NULL)
		return;
	else
	{
		printTree(node->left);
		printTree(node->right);
		cout << node->data;
	}
}


static bool hasPathSum(struct node* node, int sum)
{
	if(node == NULL)
		return false;
	if(node->data == sum)
		return true;
	else
	{
		int subSum = sum - node->data;
		return hasPathSum(node->left, subSum) || hasPathSum(node->right, subSum);
	}
}

int main()
{
	struct node* node = CreateBinaryTree(5);
	InsertNode(node,5);
	cout << size(node);
	cout << "Max Depth " << endl;
	cout << maxDepth(node) << endl;
	cout << "Min Value " << endl;
	cout << minValue(node) << endl;
	return 0;
}