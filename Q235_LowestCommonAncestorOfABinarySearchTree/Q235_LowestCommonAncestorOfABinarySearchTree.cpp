#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
        return NULL;
    }

    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}

int main()
{
    TreeNode n3(3);
    TreeNode n5(5);

    TreeNode n0(0);
    TreeNode n4(4);
    n4.left = &n3;
    n4.right = &n5;
    TreeNode n7(7);
    TreeNode n9(9);

    TreeNode n2(2);
    n2.left = &n0;
    n2.right = &n4;

    TreeNode n8(8);
    n8.left = &n7;
    n8.right = &n9;

    TreeNode n6(6);
    n6.left = &n2;
    n6.right = &n8;

    cout << lowestCommonAncestor(&n6, &n2, &n8)->val << endl;

    return 0;
}