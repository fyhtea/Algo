/*************************************************************************
	> File Name: problem3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月09日 星期一 22时00分17秒
************************************************************************/
#include <bits/stdc++.h>
using namespace std;
long long dp[100005][10][10];
int d[10][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int main() {
    int k, X, Y, tx, ty;
    scanf("%d%d%d", &k, &X, &Y);
    dp[0][0][0] = 1;
    for(int i = 0; i < k; i++) {
        for(int x = 0; x <= 8; x++) {
            for(int y = 0; y <= 8; y++) {
                for(int j = 0; j < 8; j++) {
                    tx = x + d[j][0];
                    ty = y + d[j][1];
                    if(0 <= tx && tx <= 8 && 0 <= ty && ty <= 8)
                        dp[i+1][tx][ty] = (dp[i + 1][tx][ty] + dp[i][x][y]) % 1000000007;
                }
            }
        }
    }
    printf("%lld\n", dp[k][X][Y]);
    return 0;
}
