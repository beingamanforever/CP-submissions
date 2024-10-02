/**
 *    author:  compounding
 *    created: 2024-10-02 20:29:14
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
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpi;
#define f first
#define s second
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int t;
int n, k;
int x;
signed main()
{
    NeedForSpeed;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vi a(n);
        int start = -1;
        int end = a.size();
        bool allequaltok = true;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a[i] = x;
            if (!(x == k))
            {
                allequaltok = false;
            }
            if (x != k)
            {
                end = i;
                if (start == -1)
                {
                    start = i;
                }
            }
        }
        // no operation needed
        if (allequaltok)
        {
            cout << 0;
            cout << endl;
            continue;
        }
        else
        {
            // only one operation needed
            if (start == end)
            {
                cout << 1;
                cout << endl;
            }
            else
            {
                bool xorsame = true;
                int xorfirst = k ^ a[start];
                bool gcdsame = true;
                for (int i = start; i <= end; i++)
                {
                    if (!((a[i] % k) == 0))
                    {
                        gcdsame = false;
                    }
                    if (!((a[i] ^ k) == xorfirst))
                    {
                        xorsame = false;
                    }
                }
                if (!(xorsame || gcdsame))
                {
                    cout << 2 << endl;
                }
                else
                {
                    cout << 1 << endl;
                }
            }
        }
    }
    return 0;
}
