/*************************************************************************
	> File Name: problem2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月09日 星期一 21时51分11秒
 ************************************************************************/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50 + 5;
LL dp[maxn][maxn];
char s[maxn];

int main() {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    memset (dp, 0, sizeof(dp));
    for(int i = 1; i <= len; i++) {
        for(int l = 1; l + i - 1 <= len; l++) {
            int r = l + i - 1;
            dp[l][r] += dp[l + 1][r];
            dp[l][r] += dp[l][r - 1];
            if (s[l] == s[r]) dp[l][r] += 1;
            else dp[l][r] -= dp[l + 1][r - 1];
        }
    }
    printf ("%lld\n", dp[1][len]);
    return 0;
}
