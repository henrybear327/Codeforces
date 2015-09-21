#include <cstdio>
#include <cstring>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main()
{
    int total;
    scanf("%d", &total);
    long long int data[total];

    long long int blocks_left = 0;
    for (int i = 0; i < total; i++) {
        scanf("%lld", &data[i]);
        blocks_left += data[i];
    }

    long long int count = 0;
    int max = 0, pos = 0;
    while (blocks_left && count == 0) {
        count++;

        long long int internal[total];
        memset(internal, 0, sizeof(internal));

        for (int i = 1; i < total - 1; i++) {
            if (data[i] >= 2) {
                if (MIN(data[i - 1], data[i + 1]) > data[i])
                    internal[i] = data[i] - 1;
                else if (MIN(data[i - 1], data[i + 1]) == data[i])
                    internal[i] = data[i] - 1;
                else
                    internal[i] = MIN(data[i - 1], data[i + 1]);
            }

            if (internal[i] > max) {
                max = internal[i];
                pos = i;
            }

            if (internal[i - 1] == 0) {
                blocks_left -= data[i - 1];
                data[i - 1] = 0;
            } else {
                blocks_left -= (data[i - 1] - internal[i - 1]);
                data[i - 1] = internal[i - 1];
            }
        }

        if (count == 1) {
            blocks_left -= data[0];
            data[0] = 0;
        }

        for (int i = total - 2; i < total; i++) {
            if (internal[i] == 0) {
                blocks_left -= data[i];
                data[i] = 0;
            } else {
                blocks_left -= (data[i] - internal[i]);
                data[i] = internal[i];
            }
        }
    }

    while (max) {
        count--;
        long long int internal[total];
        memset(internal, 0, sizeof(internal));
        for (int i = pos - 1; i <= pos + 1; i++) {
            if (data[i] >= 2) {
                if (MIN(data[i - 1], data[i + 1]) > data[i])
                    internal[i] = data[i] - 1;
                else if (MIN(data[i - 1], data[i + 1]) == data[i])
                    internal[i] = data[i] - 1;
                else
                    internal[i] = MIN(data[i - 1], data[i + 1]);
            }

            for (int i = pos - 1; i <= pos + 1; i++) {
                if (internal[i] == 0) {
                    blocks_left -= data[i];
                    data[i] = 0;
                } else {
                    blocks_left -= (data[i] - internal[i]);
                    data[i] = internal[i];
                }
            }
            max = data[pos] - internal[pos];
            count++;
        }
    }

    printf("%lld\n", count);

    return 0;
}
