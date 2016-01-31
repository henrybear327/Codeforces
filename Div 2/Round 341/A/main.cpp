#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    long long int ans = 0;
    long long int odd[n], idx = 0;
    for(int i = 0; i < n; i++) {
	long long int tmp;
	scanf("%lld", &tmp);

	if(tmp % 2 == 0)
	    ans += tmp;
	else {
	    odd[idx++] = tmp;
	}
    }

    sort(odd, odd + idx);
    if(idx % 2 == 0) {
	for(int i = 0; i < idx; i++) {
	    ans += odd[i];
	}
    } else {
	for(int i = 1; i < idx; i++) {
	    ans += odd[i];
	}
    }

    printf("%lld\n", ans);

    return 0;
}
