#include <bits/stdc++.h>

#define N 100100

using namespace std;

int inp[N], max_so_far[N], min_so_far[N];

/*
10
1 2 2 2 2 2 2 2 2 1
ans:2
*/

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &inp[i]);

    max_so_far[0] = -1;
    for (int i = 1; i <= n; i++)
        max_so_far[i] = max(max_so_far[i - 1], inp[i]);

    min_so_far[n] = inp[n];
    for (int i = n - 1; i >= 1; i--)
        min_so_far[i] = min(min_so_far[i + 1], inp[i]);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (min_so_far[i] >= max_so_far[i - 1])
            cnt++;

    printf("%d\n", cnt);

    return 0;
}
