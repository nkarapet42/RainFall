#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int ret;
    char buffer[40];
    int local_14;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <number> <data>\n", argv[0]);
        return 1;
    }

    local_14 = atoi(argv[1]);
    if (local_14 < 10) {
        memcpy(buffer, argv[2], local_14 * 4);
        if (local_14 == 0x574f4c46) {
            execl("/bin/sh", "sh", NULL);
        }
        ret = 0;
    } else {
        ret = 1;
    }
    return ret;
}
