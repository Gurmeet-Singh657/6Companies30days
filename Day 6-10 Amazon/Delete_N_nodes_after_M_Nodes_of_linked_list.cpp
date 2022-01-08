class Solution
{
public:
    void linkdelete(struct Node *head, int M, int N)
    {
        // Add code here
        if (head == NULL)
            return;
        Node *curr = head;
        while (curr != NULL)
        {
            for (int i = 0; i < M - 1; i++)
            {
                if (curr->next)
                    curr = curr->next;
                else
                    return;
            }
            for (int i = 0; i < N; i++)
            {
                Node *deletnode = curr->next;
                if (curr->next)
                    curr->next = curr->next->next;
                else
                    return;
                delete (deletnode);
            }
            curr = curr->next;
        }
    }
};