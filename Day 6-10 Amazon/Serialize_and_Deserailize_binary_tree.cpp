class Solution
{
public:
    void dupserialize(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        dupserialize(root->left, ans);
        dupserialize(root->right, ans);
    }
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        // Your code here
        vector<int> ans;
        dupserialize(root, ans);
        return ans;
    }
    // Function to deserialize a list and construct the tree.
    Node *dupdeSerialize(vector<int> &A, int &index)
    {
        // Your code here
        if (index == A.size())
            return NULL;
        if (A[index] == -1)
        {
            index++;
            return NULL;
        }
        int val = A[index];
        index++;
        Node *curr = new Node(val);
        curr->left = dupdeSerialize(A, index);
        curr->right = dupdeSerialize(A, index);
        return curr;
    }
    Node *deSerialize(vector<int> &A)
    {
        int index = 0;
        return dupdeSerialize(A, index);
    }
};