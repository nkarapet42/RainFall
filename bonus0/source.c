#include <stdio.h>
#include <string.h>
#include <unistd.h>

void p(char *param_1, char *param_2) {
    char local_100c[4104];

    puts(param_2);
    read(0, local_100c, 0x1000);
    char *newline = strchr(local_100c, '\n');
    if (newline) *newline = '\0';
    strncpy(param_1, local_100c, 0x14);
}

void pp(char *param_1) {
    char local_34[20];
    char local_20[20];

    p(local_34, " - ");
    p(local_20, " - ");

    strcpy(param_1, local_34);

    unsigned int len = 0;
    while (param_1[len] != '\0') {
        len++;
    }
    param_1[len] = ' ';
    param_1[len + 1] = '\0';

    strcat(param_1, local_20);
}

int main(void) {
    char local_3a[54];

    pp(local_3a);
    puts(local_3a);
    return 0;
}
