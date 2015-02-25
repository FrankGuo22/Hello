/*
*  题目要求：求一组点中距离最远的一对的距离
*  解法：凸包+枚举
*/

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 50005;

struct point {
    int x;
    int y;
}p[N], stack[N];

int dis(point A, point B) {
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}

int crossProd(point A, point B, point C) {
    return (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x);
}

int cmp(const void *a, const void *b) {
    point *c = (point *)a;
    point *d = (point *)b;
    int k = crossProd(p[0], *c, *d);
    if (k<0 || (!k&&dis(p[0], *c)>dis(p[0], *d))) return 1;
    return -1;
}

int Graham(int n) {
    int x = p[0].x;
    int y = p[0].y;
    int mi = 0;
    for (int i=1; i<n; ++i) {
        if (p[i].y<y || (p[i].y==y&&p[i].x<x)) {
            x = p[i].x;
            y = p[i].y;
            mi = i;
        }
    }
    point tmp = p[mi];
    p[mi] = p[0];
    p[0] = tmp;
    qsort(p+1, n-1, sizeof(point), cmp);
    p[n] = p[0];
    for (int i=0; i<2; ++i) stack[i] = p[i];
    int top = 1;
    for (int i=2; i<n; ++i) {
        while (crossProd(stack[top-1], stack[top], p[i])<=0 && top>=1) --top;
        stack[++top] = p[i];
    }
    return top;
}

int solve(int n) {
    int top = Graham(n);
    int s, maxL = 0;
    for (int i=0; i<top; ++i) {
        for (int j=i+1; j<=top; ++j) {
            s = dis(stack[i], stack[j]);
            if (s > maxL) maxL = s;
        }
    }
    return maxL;
}

int  main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        cin >> p[i].x >> p[i].y;
    }
    int ans = solve(n);
    cout << ans <<"\n";
    return 0;
}
