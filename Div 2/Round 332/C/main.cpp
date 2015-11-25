#include <bits/stdc++.h>

#define N 100100

using namespace std;

pair<int, int> orig[N], sorted[N];

/*
10
1 2 2 2 2 2 2 2 2 1
ans:2
*/

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &orig[i].first);
        orig[i].second = i;
        sorted[i] = orig[i];
    }

    sort(sorted, sorted + n);
    int max_element_idx = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        max_element_idx =
            max(max_element_idx,
                (int)(lower_bound(sorted, sorted + n, orig[i]) - sorted));
        if (max_element_idx == i)
            cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}
