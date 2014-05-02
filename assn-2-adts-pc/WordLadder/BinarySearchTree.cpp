#include "BinarySearchTree.h"
#include "genlib.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
#include <iostream>
#include "stack.h"
#include "queue.h"

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

//Given a binary tree, print out all of its root-to-leaf paths as defined above

static void printLevelOrder(struct node* node)
{
	int counter = 0; 
	Queue<struct node *> queue;
	if(node == NULL)
		return;
	struct node* temp = node;
	while(temp != NULL)
	{
		/*if(temp->left == NULL && temp->right == NULL && queue.size() == 0)
			return;*/
		cout << temp->data << endl;
		if(temp->left != NULL)
			queue.enqueue(temp->left);
		if(temp->right != NULL)
			queue.enqueue(temp->right);
		if(queue.size() == 0)
			return;
		if(queue.size() > 0)
			temp = queue.dequeue();
	}
}

bool isEven(int number)
{
	if(number % 2 == 0)
		return true;
	else
		return false;
}

void PrintPathsRecur(struct node* node, int path[], int pathLength)
{
	
}

void printPaths(struct node* node)
{
	int path[100000];
	int pathLength;
	PrintPathsRecur(node, path, pathLength);
}


static void mirror(struct node* node)
{
	if(node == NULL)
		return;
	else
	{
		mirror(node->left);
		mirror(node->right);
		// swap pointers in this node
		struct node* temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

// This code is wrong
static void printSpiralOrder(struct node* node)
{
	int counter = 0; 
	Queue<struct node *> queue;
	if(node == NULL)
		return;
	struct node* temp = node;
	while(temp != NULL)
	{
		/*if(temp->left == NULL && temp->right == NULL && queue.size() == 0)
			return;*/
		cout << temp->data << endl;
		if(isEven(counter))
		{
			if(temp->left != NULL)
				queue.enqueue(temp->left);
			if(temp->right != NULL)
				queue.enqueue(temp->right);		
			counter++;
		}
		else if(!isEven(counter))
		{
			if(temp->right != NULL)
				queue.enqueue(temp->right);
			if(temp->left != NULL)
				queue.enqueue(temp->left);		
			counter++;
		}
		if(queue.size() == 0)
			return;
		if(queue.size() > 0)
			temp = queue.dequeue();
	}
}

static void AddToQueue(struct node* node, Queue<struct node* > queue)
{
	
}

/* 
 For each node in a binary search tree, 
 create a new duplicate node, and insert 
 the duplicate as the left child of the original node. 
 The resulting tree should still be a binary search tree.
 */
void doubleTree(struct node* node)
{
	struct node* oldLeft;
	if (node==NULL) return;

	  // do the subtrees 
	  doubleTree(node->left); 
	  doubleTree(node->right);

	  // duplicate this node to its left 
	  oldLeft = node->left; 
	  node->left = CreateNode(node->data); 
	  node->left->left = oldLeft; 
}

int main()
{
	// Creates a node from 0 to 4
	struct node* node = CreateBinaryTree(5);
	//		2
	//	/		\
	//	0		3
	//		\		\
	//		1		4
	//				\
	//					5

	InsertNode(node,5);
	cout << size(node);
	cout << "Max Depth " << endl;
	cout << maxDepth(node) << endl;
	cout << "Min Value " << endl;
	cout << minValue(node) << endl;
	cout << "Print Level Order " << endl;
	printLevelOrder(node);
	cout << "Print Spiral Order " << endl;
	//printSpiralOrder(node);
	doubleTree(node);
	//mirror	(node);
	return 0;
}