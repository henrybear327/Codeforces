#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

typedef long long int ll;
inline long long int dis(ll a, ll b, ll c, ll d)
{
    return (a - c) * (a - c) + (b - d) * (b - d);
}

int main()
{
    int n;
    long long int x1, y1, x2, y2;
    scanf("%d %lld %lld %lld %lld", &n, &x1, &y1, &x2, &y2);

    vector< pair<ll, ll> > d1;
    vector< pair<ll, ll> > d2;
    for (int i = 0; i < n; i++) {
        long long int a, b;
        scanf("%lld %lld", &a, &b);

        d1.push_back(make_pair(dis(a, b, x1, y1), i));
        d2.push_back(make_pair(dis(a, b, x2, y2), i));
    }

    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());

    long long int ans = LLONG_MAX;
    for (int i = 0; i < n; i++) { //pick one in d1
        long long int mx = d1[i].first, mxx = 0;
        int masked[n];
        memset(masked, n, sizeof(masked));
        for(int j = i; j >= 0; j--) {
            masked[d1[j].second] = 1;
        }

        for(int j = n - 1; j >= 0; j--) { //pick the largest uncovered dist.
            if(masked[j] == 0) {
                mx = d2[j].first;
                break;
            }
        }

        ans = min(ans, mx + mxx);
    }

    printf("%lld\n", ans);

    return 0;
}
