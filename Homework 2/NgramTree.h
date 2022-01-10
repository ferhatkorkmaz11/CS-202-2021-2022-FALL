/**
* Title: Trees
* Author: Ferhat Korkmaz
* ID: 21901940
* Assignment: 2
* Description: Header file for NgramTree, which is Binary Search Tree.
*/

#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

class NgramTree
{
public:
    NgramTree();    //std header included method

    ~NgramTree();   //std header included method

    NgramTree(const NgramTree &aTree);      //copy constructor for << overriding

    void addNgram(string ngram);    //std header included method

    int getTotalNgramCount();   //std header included method

    bool isComplete();  //std header included method

    bool isFull();  //std header included method

    void generateTree(string fileName, int n);

private:
    struct NgramNode
    {
        string item;
        NgramNode *leftChild;
        NgramNode *rightChild;
        int occurrence;
        bool visited;
    };
    //int number;
    NgramNode *root;

    void copyTree(NgramNode *treePtr, NgramNode *&newTreePtr);  //for copy constructor retrieved from slides

    friend ostream &operator<<(ostream &out, NgramTree tree);   //std header included method

    void NgramCountHelper(NgramNode *node, int &count);     //helper in order to count the nodes

    static void destroyTree(NgramNode *&treeRoot);  // ~destructor

    void cleanVisited(NgramNode *node); // helper for counting the nodes

    bool isFull(NgramNode *root);   //helper for isFull

    bool isComplete(int index, NgramNode *root);    //helper for isComplete

    static void leftShiftOperatorHelper(NgramNode *root, string &result);   //helper for << override


};