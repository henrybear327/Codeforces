#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

bool is_two_power(int inp)
{
    // inp shouldn't be 0
    if (inp < 0)
        return false;
    else if (inp == 1)
        return false; // self / self == 1

    while (inp != 1) {
        if (inp % 2 == 0)
            inp /= 2;
        else
            return false;
    }

    return true;
}

int count(int num)
{
    int cnt = 0;
    if (num == 1)
        return 0;

    while (num != 1) {
        num /= 2;
        cnt++;
    }

    return cnt;
}

int main()
{
    int cases;
    scanf("%d", &cases);

    int inp[cases];
    for (int i = 0; i < cases; i++)
        scanf("%d", &inp[i]);

    int ans = INT_MAX;
    for (int i = 0; i < cases; i++) {
        bool flag = false;
        int cnt = 0;
        for (int j = 0; j < cases; j++) {
            if (i == j)
                continue;

            int times;
            bool check = true;
            if (inp[i] > inp[j] && (check = (is_two_power(times = inp[i] / inp[j]) ||
                                             inp[i] - inp[j] == 1)))
                cnt += count(times);
            else if (inp[i] < inp[j] &&
                     (check = (is_two_power(times = inp[j] / inp[i]) ||
                               inp[j] - inp[i] == 1)))
                cnt += count(times);
            else if (inp[i] == inp[j]) {
                cnt += 0;
                check = true;
            } else {
                flag = true;
                break;
            }

            if (!check) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            ans = min(ans, cnt);
        }
    }

    int cnt = 0;
    for (int i = 0; i < cases; i++) {
        cnt += count(inp[i]);
    }

    ans = min(ans, cnt);

    printf("%d\n", ans);

    return 0;
}
