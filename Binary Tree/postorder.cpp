// 1.solution :- reccursive way 
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
    void postorder(TreeNode* root , vector<int>&ans){
        if(!root)return;
        //left 
        postorder(root->left, ans);
        //right
        postorder(root->right , ans);
        //ans-> node store
        ans.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        postorder(root , ans);
        return ans;    
    }
};



//2. iterative way
//method 1 :- using 2 stacks
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();
            s2.push(curr);
            if(curr->left)s1.push(curr->left);
            if(curr->right)s1.push(curr->right);
        }
        while(!s2.empty()){
            TreeNode* curr = s2.top();
            s2.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};


//method 2:- using 1 stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*> s1;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();
            ans.push_back(curr->val);
            if(curr->left)s1.push(curr->left);
            if(curr->right)s1.push(curr->right);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};



// method 3 :- using 1 stack (again)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*> s;
        TreeNode* curr = root , *lastvisited = NULL;
        while(curr || !s.empty()){
            if(curr){
                s.push(curr);
                curr = curr->left;
            }else{
                TreeNode* node = s.top();
                if(node->right && node->right != lastvisited){
                    curr = node->right;
                }else{
                    ans.push_back(node->val);
                    lastvisited = node;
                    s.pop();
                }
            }
        }
        return ans;
    }
};
