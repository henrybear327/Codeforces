#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <climits>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    long long int array[n], max_num = INT_MIN, min_num = INT_MAX;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &array[i]);
        max_num = MAX(array[i], max_num);
        min_num = MIN(array[i], min_num);
    }

    int answer = 0;

    int used[200100] = {0}, used_index = 0;
    bool flag = true;
    if (k == 1) {
        for (int i = 0; i < n - 2; i++) {
            int target = array[i], target_count = 1;
            for (int k = 0; k < used_index; k++) {
                if (target == used[k]) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                used[used_index++] = target;
            for (int j = i + 1; j < n && flag; j++) {
                // printf("here, ");
                if (target == array[j])
                    target_count++;
            }
            // printf("target_count %d\n", target_count);
            if (target_count >= 2)
                answer += (target_count - 2); //WA here!!!
            flag = true;
            // printf("aa%d\n", answer);
        }
    } else {
        for (int i = 0; i < n - 2; i++) {
            // printf("i = %d\n", i);
            long long int num_double = array[i] * k;
            long long int num_triple = array[i] * k * k;

            if (num_double > max_num || num_double < min_num)
                continue;
            if (num_triple > max_num || num_triple < min_num)
                continue;

            int tmp_count = 0;
            for (int j = i + 1; j < n; j++) {
                if (num_double == array[j])
                    tmp_count++;
                if (num_triple == array[j])
                    answer += tmp_count;
            }
        }
    }
    printf("%d\n", answer);

    return 0;
}