#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    long long int inp;
    scanf("%lld", &inp);

    long long int tmp = 1LL << 31;

    int ans = 0;
    while (inp) {
        if (inp - tmp >= 0) {
            ans++;
            inp -= tmp;
        }
        tmp >>= 1;
    }

    printf("%d\n", ans);

    return 0;
}
