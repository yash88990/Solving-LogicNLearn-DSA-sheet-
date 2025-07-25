/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

Node* createTree(vector<int>&arr){
    // Write your code here.
    Node* root = new Node(arr[0]);
    queue<Node*>q;
    q.push(root);
    int i = 0;
    while(!q.empty() && i < 3){
        Node* curr = q.front();
        q.pop();
        Node* leftchild = new Node(arr[2 * i + 1]);
        curr->left = leftchild;
        Node* rightchild = new Node(arr[2 * i + 2]);
        curr->right = rightchild;
        q.push(leftchild);
        q.push(rightchild);
        i++;
    }
    return root;
}
