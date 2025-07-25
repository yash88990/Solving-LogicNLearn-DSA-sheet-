
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
void solve(TreeNode* root , vector<int>&ans){
        if(!root)return;
        // n l r 
           ans.push_back(root->val); // node 
        solve(root->left , ans);  // left 
        solve(root->right , ans); // right
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root ,ans);
        return ans;
    }
};



//method 2 

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            //store krna h 
            TreeNode* curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            //left jana h 
            if(curr->right)s.push(curr->right);
            if(curr->left)s.push(curr->left);
        }
        return ans;
    }
};
