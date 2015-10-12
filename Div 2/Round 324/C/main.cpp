#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);

    int same = n - t, diff = n - 2 * same;
    if (diff < 0) {
        printf("-1\n");
        return 0;
    }

    int cnt1[26] = {0}, cnt2[26] = {0};

    char input[100010];
    scanf("%s", input);
    for (int i = 0; i < n; i++) {
        cnt1[input[i] - 'a']++;
    }

    scanf("%s", input);
    for (int i = 0; i < n; i++) {
        cnt2[input[i] - 'a']++;
    }

    vector<char> ans;

    int used[26] = {0};
    int counter = 0;
    bool error = false;

    for (int i = 0; counter != same && i < 26; i++) {
        if (cnt1[i] != 0 && cnt2[i] == 0) {
            while (counter < same && cnt1[i]) { // don't do counter++ here!!
                // Acdentically increment counter by
                // one for the last checking loop
                counter++;
                cnt1[i]--;
                ans.push_back(i + 'a');
                used[i] = 1;
            }
        }
    }

    if (counter != same) {
        error = true;
    }

    counter = 0;
    for (int i = 0; counter != same && i < 26; i++) {
        if (cnt1[i] == 0 && cnt2[i] != 0) {
            while (counter < same && cnt2[i]) {
                counter++;
                cnt2[i]--;
                ans.push_back(i + 'a');
                used[i] = 1;
            }
        }
    }

    if (counter != same)
        error = true;

    for (int i = 0; diff && i < 26; i++) {
        while (diff && used[i] == 0 && cnt1[i] == 0 && cnt2[i] == 0) {
            ans.push_back(i + 'a');
            diff--;
        }
    }

    if (diff != 0)
        error = true;

    if (error)
        printf("-1\n");
    else {
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }

    return 0;
}
