#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    FILE *file;
    char password[65];
    char message[66];
    int index;

    file = fopen("/home/user/end/.pass", "r");

    memset(password, 0, sizeof(password));

    if (file == NULL || argc != 2) {
        return -1;
    }

    fread(password, 1, 0x42, file);

    index = atoi(argv[1]);
    password[index] = '\0';

    fread(message, 1, 0x41, file);
    fclose(file);

    if (strcmp(password, argv[1]) == 0) {
        execl("/bin/sh", "sh", NULL);
    } else {
        puts(message);
    }

    return 0;
}
