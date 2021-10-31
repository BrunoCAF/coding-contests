/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        bool l = root->left ? isValidBST(root->left) : true, 
             r = root->right ? isValidBST(root->right) : true;
        int lmax, rmin;
        
        if(l && r){
            if(root->left){
                lmax = root->left->val;
                for(TreeNode* p = root->left; p->right; p = p->right)
                    lmax = max(lmax, p->right->val);
                
                l = (lmax < root->val);
                if(!l) return l;
            }
            if(root->right){
                rmin = root->right->val;
                for(TreeNode* p = root->right; p->left; p = p->left)
                    rmin = min(rmin, p->left->val);
                
                r = (rmin > root->val);
            }
        }
        
        return l && r;
    }
};