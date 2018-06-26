#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int                 m_nValue;
    BinaryTreeNode*     m_pLeft;
    BinaryTreeNode*     m_pRight;
};



BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root -> m_nValue = rootValue;
    root -> m_pLeft = root -> m_pRight = NULL;
    
    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            cout << "invalid input." << endl;
    }
    
    int* rootInoreder = startInorder;
    while (rootInoreder <= endInorder && *rootInoreder != rootValue)
        ++ rootInoreder;
    
    if (rootInoreder == endInorder && *rootInoreder != rootValue)
        cout << "invalid input." << endl;
    
    int leftLength = rootInoreder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;

    if (leftLength > 0)
    {
        root -> m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInoreder - 1);
    }
    if (leftLength < endPreorder - startPreorder)
    {
        root -> m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInoreder + 1, endInorder);
    }

    return root;
    
}

BinaryTreeNode* Construct(int* preorder, int* inorder, const int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0)
        return NULL;
    
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}


void LaterOrderPrint(BinaryTreeNode* tree)
{
    if (tree == NULL)
        return;

    LaterOrderPrint(tree->m_pLeft);
    LaterOrderPrint(tree->m_pRight);
    cout << tree -> m_nValue << endl;
}


int main()
{
    int preOrder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inOrder[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    int length = 8;

    BinaryTreeNode* binaryTree = NULL;
    binaryTree = Construct(preOrder, inOrder, length);
    LaterOrderPrint(binaryTree);
    
    return 0;
}