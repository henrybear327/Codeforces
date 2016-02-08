#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    ll sa = 0LL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sa += a[i];
    }

    int m;
    scanf("%d", &m);
    int b[m];
    ll sb = 0LL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        sb += b[i];
    }

    // no need to swap
    if(sa == sb) {
        printf("0\n0\n");
        return 0;
    }

    // one swap
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if((sa - a[i] + b[j]) - (sb - b[j] + a[i]) == 0) {
                printf("0\n1\n%d %d\n", i, j);
            }


    // two swaps
    map<ll, pair<int, int> > ma;
    map<ll, pair<int, int> > mb;

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            ma.insert(make_pair(a[i] + a[j], make_pair(i, j)));

    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++)
            mb.insert(make_pair(b[i] + b[j], make_pair(i, j)));

    ll mn = LLONG_MAX;
    pair<int, int> ansa, ansb;
    for(auto ib : mb) {
        ll diff = sa - sb + 2 * (ib.first);
        map<ll, pair<int, int> >::iterator ia = ma.lower_bound(diff);
        printf("diff %lld ia %lld %d %d\n", diff, ia->first, ia->second.first, ia->second.second);

        if(diff - 2 * ia->first < mn) {
            for(map<ll, pair<int, int> >::iterator ii = ma.begin(); ii != ma.end(); ii++)
                printf("ia %lld %d %d\n", ii->first, ii->second.first, ii->second.second);
	    
            mn = diff - 2 * ia->first;
            ansa = make_pair(ia->second.first + 1, ia->second.second + 1);
            printf("%d %d\n", ia->second.first, ia->second.second);
            ansb = make_pair(ib.second.first + 1, ib.second.second + 1);
            printf("%d %d\n", ib.second.first, ib.second.second);
        }
    }

    printf("%lld\n2\n%d %d\n%d %d\n", mn, ansa.first, ansb.first, ansa.second, ansb.second);

    return 0;
}
