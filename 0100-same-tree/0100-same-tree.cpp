class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are the same
        if (!p && !q) return true;
        
        // If one is null and the other isn't, they are not the same
        if (!p || !q) return false;
        
        // Check if the current nodes have the same value,
        // and recursively check left and right subtrees
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
