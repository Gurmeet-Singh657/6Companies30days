#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    for (int i = 0; i < 10; i++)
    {
        int element;
        cin >> element;
        pq.push(element);
    }
    for (int i = 10; i < (long long)1e7; i++)
    {
        int element;
        cin >> element;
        if (element > pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    cout << "Largest 10 entries are :";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}