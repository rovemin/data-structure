/* 반복적인 순회 */

#define SIZE 100
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

int top = -1;
TreeNode* stack[SIZE];  //포인터 배열

void push(TreeNode* p)
{
    if (top < SIZE - 1)
        stack[++top] = p;
}

TreeNode* pop() {
    TreeNode* p = NULL;
    if (top >= 0)
        p = stack[top--];
        return p;
}

void inorder_iter(TreeNode* root) {
    while(1) {
        for (; root; root = root->left)
            push(root);
        root = pop();
        if (!root) break;
        printf("[%d] ", root->data);
        root = root->right;
    }
}

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode* root = &n6;

int main(void) {
    printf("중위 순회=");
    inorder_iter(root);
    printf("\n");
    return 0;
}