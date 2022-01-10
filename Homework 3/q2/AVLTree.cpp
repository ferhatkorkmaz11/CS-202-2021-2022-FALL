/*
* Title : Heaps and AVL Trees
* Author : Ferhat Korkmaz
* ID : 21901940
* Section : 1
* Assignment : 3
* Description : AVLTree implementation.
*/
#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree()
{
    root = NULL;
    rotationCount = 0;
}

AVLTree::~AVLTree()
{
	destructorHelper(root);
}

void AVLTree::destructorHelper(Node *node)
{
	 if (node != NULL)
    {
        destructorHelper(node->leftChild);
        destructorHelper(node->rightChild);

        delete node;
        node = NULL;
    }
}

AVLTree::Node *AVLTree::rightRot(AVLTree::Node *parent)
{
    Node *temp;
    temp = parent->rightChild;
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;
    rotationCount++;
    //cout << "ONE RIGHT ROTATION" << endl;
    return temp;
}

AVLTree::Node *AVLTree::leftRot(AVLTree::Node *parent)
{
    Node *temp;
    temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;
    rotationCount++;
    //cout << "ONE LEFT ROTATION" << endl;
    return temp;
}

AVLTree::Node *AVLTree::leftrightRot(AVLTree::Node *parent)
{
    Node *temp;
    temp = parent->leftChild;
    parent->leftChild = rightRot(temp);
    return leftRot(parent);
}

AVLTree::Node *AVLTree::rightleftRot(AVLTree::Node *parent)
{
    Node *temp;
    temp = parent->rightChild;
    parent->rightChild = leftRot(temp);
    return rightRot(parent);
}

void AVLTree::insert(int value)
{
    root = insert(root, value);
}


AVLTree::Node *AVLTree::rebalance(AVLTree::Node *aTreeNode)
{
    int balanceFactor = heightDifference(aTreeNode);
    if (balanceFactor > 1)
    {
        if (heightDifference(aTreeNode->leftChild) > 0)
            aTreeNode = leftRot(aTreeNode);
        else
            aTreeNode = leftrightRot(aTreeNode);

    } else if (balanceFactor < -1)
    {
        if (heightDifference(aTreeNode->rightChild) > 0)
            aTreeNode = rightleftRot(aTreeNode);
        else
            aTreeNode = rightRot(aTreeNode);
    }
    return aTreeNode;
}

int AVLTree::heightDifference(Node *node)
{
    int leftHeight = height(node->leftChild);
    int rightHeight = height(node->rightChild);
    int balanceFactor = leftHeight - rightHeight;
    return balanceFactor;
}

int AVLTree::height(Node *node)
{
    int result = 0;
    if (node != NULL)
    {
        int leftHeight = height(node->leftChild);
        int rightHeight = height(node->rightChild);
        int maxOfHeights = max(leftHeight, rightHeight);
        result = maxOfHeights + 1;
    }
    return result;
}


int AVLTree::rotations()
{
    return rotationCount;
}

void AVLTree::inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->leftChild);
        cout << node->item << " ";
        inorder(node->rightChild);
    }
}

void AVLTree::inorder()
{
    inorder(root);
}

AVLTree::Node *AVLTree::insert(AVLTree::Node *r, int newItem)
{
    if (r == NULL)
    {
        r = new Node;
        r->item = newItem;
        r->leftChild = NULL;
        r->rightChild = NULL;
        //cout << newItem << " Added null case" << endl;
        return r;
    } else if (newItem < r->item)
    {
        //cout << newItem << " added " << "right subtree case " << endl;
        r->leftChild = insert(r->leftChild, newItem);
        r = rebalance(r);
    } else if (newItem >= r->item)
    {
        //cout << newItem << " added " << "left subtree case" << endl;
        r->rightChild = insert(r->rightChild, newItem);
        r = rebalance(r);
    }
    return r;
}
