/*
* Title : Heaps and AVL Trees
* Author : Ferhat Korkmaz
* ID : 21901940
* Section : 1
* Assignment : 3
* Description : AVLTree Header.
*/
#include <iostream>
#include <cstddef>
#include <cstdlib>
class AVLTree
{
public:
    struct Node
    {
        int item;
        struct Node *leftChild;
        struct Node  *rightChild;
    };
    AVLTree();
    ~AVLTree();
	void destructorHelper(Node *node);	//avoiding memory leak
    int rotations();	//returns number of rotations 
    int height(Node* node);	//helper for finding height for each node
    int heightDifference(Node* node);	//checks left and right height differences
    Node* rightRot(Node* parent);		//single right rot.
    Node* leftRot(Node* parent);		//single left rot.
    Node* leftrightRot(Node* parent);	//double left right rot.
    Node* rightleftRot(Node* parent);	//double right left rot.
    Node* rebalance(Node* aTreeNode);	//rebalances the tree by rebalancing it where the unbalance occurrs using above helper functions (height, heightdifference, and rotations)
    Node* insert(Node* r, int newItem);	//insert(int value) helper.
    void insert(int value);				//inserts the value into the avl tree
    void inorder(Node* node);			//printing purposes
    void inorder();						//inorder helper
private:
	
    int rotationCount;
    Node* root;
    //int max(int height, int height1);  //built in max does not work? Ok it does work.
};


