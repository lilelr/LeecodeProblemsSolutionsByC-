//
// Created by YuXiao on 5/10/18.
//
#include <cstdio>

int panel[50], tot = 0, n = 8, nc = 0;

void search(int cur) {
    int i, j;
    nc++;
    if (cur == n) {
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (panel[i] == panel[j] || i - panel[i] == j - panel[j] || i + panel[i] == j + panel[j]) {
                    return;
                }
            }
        }
        tot++;
    } else {
        for (i = 0; i < n; i++) {
            panel[cur] = i;
            search(cur + 1);
        }
    }

}

void search2(int cur) {
    int i, j;
    nc++;
    if (cur == n) {
        tot++;
    } else
        for (i = 0; i < n; i++) {
            int ok = 1;
            panel[cur] = i;
            for (j = 0; j < cur; j++) {
                if (panel[cur] == panel[j] || i - panel[cur] == j - panel[j] || i + panel[cur] == j + panel[j]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) search(cur + 1);
        }
}

int main() {
    search(0);

    printf("%d\n", tot);
    printf("%d\n", nc);
    tot = 0;
    nc = 0;
    search2(0);
    printf("%d\n", tot);
    printf("%d\n", nc);

    return 0;
}
