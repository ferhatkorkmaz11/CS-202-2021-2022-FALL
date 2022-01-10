/**
* Title: Trees
* Author: Ferhat Korkmaz
* ID: 21901940
* Assignment: 2
* Description: Cpp file for NgramTree, which is Binary Search Tree.
*/
#include "NgramTree.h"
#include <iostream>

using namespace std;

NgramTree::NgramTree()
{
    root = NULL;
}

//destructor
NgramTree::~NgramTree()
{
    destroyTree(root);
}

//actual copy constructor
NgramTree::NgramTree(const NgramTree &aTree)
{
    copyTree(aTree.root, root);
}

//copy constructor helper (retrieved from lecture slides)
void NgramTree::copyTree(NgramNode *treePtr, NgramNode *&newTreePtr) 
{
    if (treePtr != NULL)
    {
        newTreePtr = new NgramNode();
        newTreePtr->item = treePtr->item;
        newTreePtr->occurrence = treePtr->occurrence;
        newTreePtr->visited = false;
        copyTree(treePtr->leftChild, newTreePtr->leftChild);
        copyTree(treePtr->rightChild, newTreePtr->rightChild);
    } else
        newTreePtr = NULL;
}

//This method inserts a new node in to the NgramTree while traversing every element.
void NgramTree::addNgram(string ngram)
{
    NgramNode *current = root;
    NgramNode **currentsParent = NULL;
    bool alreadyExist = false;

    //cout << "Currently Adding: " << ngram << endl;
    if (current == NULL)
    {
        root = new NgramNode();
        (root)->item = ngram;
        root->visited = false;
        root->occurrence = 1;
    } else
    {
        while (current != NULL)
        {
            if (ngram.compare(current->item) > 0) // if it is alphabetically greater than the current node's string
            {
                currentsParent = &(current->rightChild);
                current = current->rightChild;
            } else if (ngram.compare(current->item) <
                       0)  // if it is alphabetically smaller than the current node's string
            {
                currentsParent = &(current->leftChild);
                current = current->leftChild;
            } else // if it already exists
            {
                (current->occurrence)++;
                alreadyExist = true;
                break;
            }
        }
        if (!alreadyExist)
        {
            *currentsParent = new NgramNode();
            (*currentsParent)->item = ngram;
            (*currentsParent)->occurrence = 1;

        }
    }
}

int NgramTree::getTotalNgramCount()
{
    int result = 0;
    NgramCountHelper(root, result);
    cleanVisited(root);
    return result;
}

//this function recursively calls it self in order to count the elements in the NGramBST.
//here simply, I mark every I visit as visited to prevent them count twice or more if they appear more than once.
void NgramTree::NgramCountHelper(NgramNode *node, int &count)
{
    if (node != NULL)
    {
        if (!(node->visited))
            count++;
        //cout << "CURRENT VISITED NODE: " << node->item << endl;
        node->visited = true;
        NgramCountHelper(node->leftChild, count);
        NgramCountHelper(node->rightChild, count);
    }
}

//unmark as visited (to count)
void NgramTree::cleanVisited(NgramNode *node)
{
    if (node != NULL)
    {
        node->visited = false;
        cleanVisited(node->leftChild);
        cleanVisited(node->rightChild);
    }
}

bool NgramTree::isComplete()
{
    return isComplete(0, root);
}

//if a node is inserted before the left child of that subtree, then, it is not complete tree. this is a helper method for recursion.
bool NgramTree::isComplete(int index, NgramNode *root)
{
    if (root == NULL)
        return true;
    if (index >= getTotalNgramCount())
        return false;
    return (isComplete(2 * index + 1, root->leftChild) && isComplete(2 * index + 2, root->rightChild));
}

bool NgramTree::isFull()
{
    return isFull(root);
}

//if the every node on last level - 1th level has two or zero children, then, the tree is full.
bool NgramTree::isFull(NgramNode *root)
{
    if (root == NULL)
        return true;
    if (root->leftChild == NULL && root->rightChild == NULL)
        return true;
    if ((root->leftChild) && (root->rightChild))
        return (isFull(root->leftChild) && isFull(root->rightChild));
    return false;
}

//this method reads a input file in txt format and seperates its words by n adds into the tree. 
void NgramTree::generateTree(string fileName, int n)
{
    ifstream file;
    file.open(fileName.c_str());
    string word;
    while (file >> word)
    {
        //cout << "current word: " << word << endl; debug purpose
        if (word.length() >= n)
        {
            for (int i = 0; word.length() - n >= i; i++)
            {
                //cout << "CURRENT NGRAM TO BE GENERATED: " << word.substr(i, n) << endl;
                addNgram(word.substr(i, n));
            }
        }
    }
}


void NgramTree::destroyTree(NgramNode *&treeRoot)   //helper for destructor
{
    if (treeRoot != NULL)
    {
        destroyTree(treeRoot->leftChild);
        destroyTree(treeRoot->rightChild);

        delete treeRoot;
        treeRoot == NULL;
    }
}

void NgramTree::leftShiftOperatorHelper(NgramNode *root, string &result)    //Recursive call happens here. With inorder traversal
{
    if (root != NULL)
    {
        leftShiftOperatorHelper(root->leftChild, result);
        result.append("\"");
        result.append(root->item);
        result.append("\" appears ");
        stringstream temp;
        string tempStr;
        temp << root->occurrence;
        temp >> tempStr;
        result.append(tempStr);
        result.append(" time(s)");
        result.append("\n");
        leftShiftOperatorHelper(root->rightChild, result);
    }
}

ostream &operator<<(ostream &out, NgramTree tree)
{
    string result = "";
    NgramTree *temp = new NgramTree(tree);
    tree.leftShiftOperatorHelper(temp->root, result);
    out << result;
    //NgramTree::destroyTree(temp->root); double free(), just delete temp; is enough since I have a destructor.
    delete temp;
    return out;
}




