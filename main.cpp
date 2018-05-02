#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int time_start;
    int fulltime = 100;//总时间
    int runtime = 50;//运行时间
    while (1) {
        time_start = clock();
        while ((clock() - time_start) < runtime) {}
        usleep(fulltime - runtime);
    }
}
