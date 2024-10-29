#include "searchtree.h"
#include <iostream>
struct TreeNode
{
    ElementType Element;
    SearchTree left;
    SearchTree right;

} Node;
SearchTree MakeEmpty(SearchTree T)
{
    if (T == NULL)
        return NULL;
    MakeEmpty(T->left);
    MakeEmpty(T->right);
    free(T);
}
Position Find(ElementType X, SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (X < T->Element)
        return Find(X, T->left);
    else if (X > T->Element)
        return Find(X, T->right);
    else
        return T;
}
Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->left == NULL)
        return T;
    else
        return FindMin(T->left);
}
Position FindMax(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->right == NULL)
        return T;
    else
        return FindMax(T->right);
}
SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == NULL)
    {
        T = new TreeNode;
        T->Element = X;
        T->left = T->right = NULL;
    }

    else if (X < T->Element)
        T->left = Insert(X, T->left);
    else if (X > T->Element)
        T->right = Insert(X, T->right);
    return T;
}
SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if (T == NULL)
        return NULL;
    else if (X < T->Element)
        T->left = Delete(X, T->left);
    else if (X > T->Element)
        T->right = Delete(X, T->right);
    else
    {
        if (T->left && T->right)
        {
            TmpCell = FindMin(T->right);
            T->Element = TmpCell->Element;
            T->right = Delete(T->Element, T->right);
        }
        else
        {
            TmpCell = T;
            if (T->left != NULL)
                T = T->left;
            else if (T->right != NULL)
                T = T->right;
            free(TmpCell);
        }
    }
    return T; // 任何时候都返回T
}