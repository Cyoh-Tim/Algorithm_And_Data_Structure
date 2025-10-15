/*********************************
File name: tree_traversing_example.cpp
Author: seuteut879@gmail.com
Description: Binary tree traversing recursive function example
Others:
          Tree example (Binary Tree)
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
**********************************/

#include <iostream>

typedef struct _TREE_ITEM {
    int value;
    struct _TREE_ITEM* left;
    struct _TREE_ITEM* right;
} TREE_ITEM, *P_TREE_ITEM;

TREE_ITEM node1 = { 1, NULL, NULL };
TREE_ITEM node2 = { 2, NULL, NULL };
TREE_ITEM node3 = { 3, NULL, NULL };
TREE_ITEM node4 = { 4, NULL, NULL };
TREE_ITEM node5 = { 5, NULL, NULL };
TREE_ITEM node6 = { 6, NULL, NULL };
TREE_ITEM node7 = { 7, NULL, NULL };

void recursivePre(P_TREE_ITEM node);
void recursiveInorder(P_TREE_ITEM node);
void recursivePost(P_TREE_ITEM node);

int main() {
    // 트리 연결 (Binary Tree 구조)
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;

    std::cout << "Preorder Traversal: ";
    recursivePre(&node1);
    std::cout << std::endl;

    std::cout << "Inorder Traversal: ";
    recursiveInorder(&node1);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    recursivePost(&node1);
    std::cout << std::endl;

    return 0; // main 함수에서 0을 반환하는 것이 일반적
}

// 전위 순회 (Preorder: Root -> Left -> Right)
void recursivePre(P_TREE_ITEM node)
{
    if (node == NULL)
        return;
    std::cout << node->value << " "; // 출력 형식 : 공백으로 구분
    recursivePre(node->left);
    recursivePre(node->right);
}

// 중위 순회 (Inorder: Left -> Root -> Right)
void recursiveInorder(P_TREE_ITEM node)
{
    if (node == NULL)
        return;
    recursiveInorder(node->left);
    std::cout << node->value << " "; // 출력 형식 : 공백으로 구분
    recursiveInorder(node->right);
}

// 후위 순회 (Postorder: Left -> Right -> Root)
void recursivePost(P_TREE_ITEM node)
{
    if (node == NULL)
        return;
    recursivePost(node->left);
    recursivePost(node->right);
    std::cout << node->value << " "; // 출력 형식 : 공백으로 구분
}