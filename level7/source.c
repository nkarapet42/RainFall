#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char c[0x44];

void m(void *param_1, int param_2, char *param_3, int param_4, int param_5) {
    time_t tVar1;
    tVar1 = time(NULL);
    printf("%s - %ld\n", c, tVar1);
}

int main(int argc, char **argv) {
    int *puVar1;
    void *pvVar2;
    int *puVar3;
    FILE *__stream;

    puVar1 = (int *)malloc(8);
    puVar1[0] = 1;
    pvVar2 = malloc(8);
    puVar1[1] = (int)pvVar2;

    puVar3 = (int *)malloc(8);
    puVar3[0] = 2;
    pvVar2 = malloc(8);
    puVar3[1] = (int)pvVar2;

    strcpy((char *)puVar1[1], argv[1]);
    strcpy((char *)puVar3[1], argv[2]);

    __stream = fopen("/home/user/level8/.pass", "r");
    if (__stream) {
        fgets(c, sizeof(c), __stream);
        fclose(__stream);
    }

    puts("~~");

    return 0;
}
