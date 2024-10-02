/**
 *    author:  compounding
 *    created: 2024-10-02
 **/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
#define f first
#define s second
#define endl "\n"
int t;
int n;
int length_union(const vector<pair<int, int>> &a)
{
    int n = a.size();
    vector<pair<int, bool>> x(n * 2);
    for (int i = 0; i < n; i++)
    {
        x[i * 2] = {a[i].first, false};
        x[i * 2 + 1] = {a[i].second, true};
    }

    sort(x.begin(), x.end());

    int result = 0;
    int c = 0;
    for (int i = 0; i < n * 2; i++)
    {
        if (i > 0 && x[i].first > x[i - 1].first && c > 0)
        {
            result += x[i].first - x[i - 1].first;
        }
        if (x[i].second)
        {
            c--;
        }
        else
        {
            c++;
        }
    }
    return result;
}
signed main()
{
    NeedForSpeed;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(all(a));
        vpi events;
        for (int i = 0; i < n - 1; i++)
        {
            int start = a[i + 1] - a[i] + 1;
            int end = a[i + 1] + a[i];
            events.push_back({start, end});
        }
        sort(all(events));
        int distinct = length_union(events);
        cout << distinct << endl;
    }
    return 0;
}
