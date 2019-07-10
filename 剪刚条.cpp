
#include <limits.h>
#include <math.h>
#include <algorithm>

// https://blog.csdn.net/u013309870/article/details/75193592

// ---- 1 递归版本 ---

int cut(int p[], int n) {
    if (n == 0)
        return 0;
    int q = INT_MIN;
    for (int i = 1; i <= n; i++) {
        q = std::max(q, p[i - 1] + cut(p, n - i));     
    }
    return q;
}

// ---- 2 备忘录版本 ---

int cut2(int p[], int n, int r[]) {
    if (n == 0)
        return 0;
    if (r[n] >0) 
        return r[n];
    int q= INT_MAX;
    for (int i = 1; i <= n; i++) {
        q = std::max(q, p[i - 1] + cut2(p, n - i, r));
    }
    return q;
}

// --- 3 迭代版本 ---

int cut3(int p[], int n){
    int *r = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        int q = -1;
        for (int j = 1; j <= i; j++) {
            q = std::max(q, p[j-1] + r[i-j]);
        }
        r[i] = q;
    }
    return r[n];
}