#include <bits/stdc++.h>

using namespace std;

int main()
{
    pair<int, int> inp[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &inp[i].first, &inp[i].second);
    }

    sort(inp, inp + 3);

    // special case one line
    bool ok = false;
    for (int i = 0; i < 1; i++) {
        if ((inp[i].first == inp[i + 1].first) &&
            (inp[i + 1].first == inp[i + 2].first))
            ok = true;
        if ((inp[i].second == inp[i + 1].second) &&
            (inp[i + 1].second == inp[i + 2].second))
            ok = true;
    }

    if (ok == true) {
        printf("1\n");
        return 0;
    }

    // first
    int dx = inp[1].first - inp[0].first;
    int dy = inp[1].second - inp[0].second;

    int cnt = 0;
    if (dx)
        cnt++;
    if (dy)
        cnt++;

    dy = inp[2].second - inp[1].second;
    if (dy)
        cnt++;

    printf("%d\n", cnt);

    return 0;
}
