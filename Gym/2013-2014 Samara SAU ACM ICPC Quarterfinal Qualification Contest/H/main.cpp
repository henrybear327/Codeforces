#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF) {
        N+=2;
        char a[N];
        char b[N];

        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
        fgets(a,N,stdin);
        fgets(a,N,stdin);
        fgets(b,N,stdin);

        N-=2;

        int cnt=0;
        int flag = 0;
        for(int i=0; i<N; i++) {
            if(a[i]==b[i]) {
                if(flag) {
                    flag = 0;
                }
            } else if(a[i]!=b[i] && !flag) {
                flag = 1;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
