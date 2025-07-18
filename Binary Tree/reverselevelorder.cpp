/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<algorithm>
vector<int> reverseLevelOrder(TreeNode<int> *root){
    // Write your code here.
    vector<int>ans;
    if(!root)return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0 ; i< size ; i++){
            TreeNode<int>* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
    }
    reverse(ans.begin() , ans.end());
    return ans;
}



//method 2 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<algorithm>
#include<stack>
#include<queue>
vector<int> reverseLevelOrder(TreeNode<int> *root){
    // Write your code here.
    vector<int>ans;
    if(!root)return ans;
    queue<TreeNode<int>*> q;
    stack<int>s;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0 ; i< size ; i++){
            TreeNode<int>* curr = q.front();
            q.pop();
            s.push(curr->val);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
