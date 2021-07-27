#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");
    while (n--)
    {
        string s = q.front();
        q.pop();
        cout << s << "\n";
        string s2 = s;
        q.push(s.append("0"));
        q.push(s2.append("1"));
    }
}