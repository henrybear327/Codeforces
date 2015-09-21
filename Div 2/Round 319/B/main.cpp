#include <cstdio>
#include <cstring>

int main()
{
    int total, target;
    scanf("%d %d", &total, &target);

    bool flag = false, exist[target];
    memset(exist, false, sizeof(exist));

    for(int i = 0; i < total; i++) {
        int curr;
        scanf("%d", &curr);

        curr %= target;

        if(!curr) {
            flag= true;
            break;
        }

        bool exist_tmp[target];
        for(int j = 0; j < target; j++) {
            exist_tmp[j] = exist[j];
        }

        for(int j = 1; j < target; j++) {
            if(exist[j]) {
                exist_tmp[(j + curr) % target] = true;
            }
        }

        if(exist_tmp[0]) {
            flag = true;
            break;
        }

        exist_tmp[curr] = true;
        for(int j = 0; j < target; j++) {
            exist[j] = exist_tmp[j];
        }
    }

    printf("%s\n", flag ? "YES" : "NO");

    return 0;
}
