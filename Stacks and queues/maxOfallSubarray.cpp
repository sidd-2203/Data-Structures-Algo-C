#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k, l, r, i;
    cin >> k;
    l = 0, r = k - 1;
    deque<int> q(k);
    // Sliding techinique...................
    for (i = 0; i < k; i++)
    {
        while (!(q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for (; i < 9; i++)
    {
        cout << arr[q.front()] << " ";
        while (!q.empty() && arr[q.front()] <= (i - k))
            q.pop_front();
        while (!(q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }

    cout << arr[q.front()] << endl;
}