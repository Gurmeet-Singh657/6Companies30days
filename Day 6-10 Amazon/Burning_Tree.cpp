class Solution
{
public:
    int mintime(unordered_map<Node *, Node *> map, Node *king)
    {
        int time = 0;
        unordered_map<Node *, bool> visited;
        queue<Node *> q;
        q.push(king);
        visited[king] = true;
        while (!q.empty())
        {
            int qsize = q.size();
            int flag = 0;
            for (int i = 0; i < qsize; i++)
            {
                Node *curr = q.front();
                q.pop();
                // for left child
                if (curr->left && !visited[curr->left])
                {
                    flag = 1;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                // for right child
                if (curr->right && !visited[curr->right])
                {
                    flag = 1;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                // for upper parent
                if (map[curr] && !visited[map[curr]])
                {
                    flag = 1;
                    visited[map[curr]] = true;
                    q.push(map[curr]);
                }
            }
            if (flag == 1)
                time++;
        }
        return time;
    }
    Node *gettingparent(unordered_map<Node *, Node *> &map, Node *root, int target)
    {
        queue<Node *> q;
        q.push(root);
        Node *king;
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr->data == target)
            {
                king = curr;
            }
            if (curr->left)
            {
                map[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                map[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return king;
    }
    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> map;
        Node *king = gettingparent(map, root, target);
        return mintime(map, king);
    }
};