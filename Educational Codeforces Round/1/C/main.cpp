#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

#define PI 3.14159265359

using namespace std;

typedef struct data {
    int x, y;
    double s; // slope
    int orig_idx;
} Data;

#define INF 1e9

double atan2_angle(int x, int y)
{
    double ans = atan2(y, x) * 180 / PI;

    ans = ans > 0 ? ans : 180.0 + (180.0 - ans * -1);
    if (ans == 360.0)
        ans = 0;
    return ans;
}

inline int quadrant(int x, int y)
{
    if (x > 0 && y >= 0)
        return 1;
    else if (x <= 0 && y > 0)
        return 2;
    else if (x < 0 && y <= 0)
        return 3;
    else // x >= 0 && y > 0
        return 4;
}

bool cmp(Data a, Data b)
{
    // check quadrant
    if (quadrant(a.x, a.y) == quadrant(b.x, b.y))
        return a.s < b.s;
    else
        return quadrant(a.x, a.y) < quadrant(b.x, b.y);
}

bool last_for_debug = false;
double angle(Data a, Data b)
{
    double actual_angle = atan2_angle(b.x, b.y) - atan2_angle(a.x, a.y);
    if (last_for_debug == true)
        actual_angle += 360.0;

    return actual_angle;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        Data inp[n];
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &inp[i].x, &inp[i].y);
            inp[i].s = inp[i].x == 0 ? -1 * INF : (double)inp[i].y / (double)inp[i].x;
            inp[i].orig_idx = i + 1;
        }

        if (n == 2) {
            printf("1 2\n");
            continue;
        }

        // sort by slope
        sort(inp, inp + n, cmp);

        /*
        for (int i = 0; i < n; i++)
            printf("%d %d %f %d\n", inp[i].x, inp[i].y, inp[i].s, inp[i].orig_idx);
        */

        last_for_debug = false;

        double ans = 1000;
        int ans_idx1 = 0, ans_idx2 = 0;
        for (int i = 1; i < n; i++) {
            double tmp = angle(inp[i - 1], inp[i]);

            if (ans > tmp) {
                ans = min(ans, tmp);
                ans_idx1 = inp[i - 1].orig_idx;
                ans_idx2 = inp[i].orig_idx;
            }
        }

        last_for_debug = true;

        double tmp = angle(inp[n - 1], inp[0]);
        if (ans > tmp) {
            printf("%d %d\n", inp[n - 1].orig_idx, inp[0].orig_idx);
        } else {
            printf("%d %d\n", ans_idx1, ans_idx2);
        }
    }
    return 0;
}
