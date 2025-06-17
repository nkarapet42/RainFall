#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *auth = NULL;
char *service = NULL;

int main(void) {
    char local_90[5];
    char local_8b[2];
    char acStack_89[125];

    while (1) {
        printf("%p, %p \n", auth, service);

        if (fgets(local_90, 0x80, stdin) == NULL)
            return 0;

        if (!strncmp(local_90, "auth ", 5)) {
            auth = (char *)malloc(4);
            memset(auth, 0, 4);

            if (strlen(local_8b) < 31) {
                strcpy(auth, local_8b);
            }
        }

        else if (!strncmp(local_90, "reset", 5)) {
            free(auth);
        }

        else if (!strncmp(local_90, "service", 6)) {
            service = strdup(acStack_89);
        }

        else if (!strncmp(local_90, "login", 5)) {
            if (auth != NULL && *(int *)(auth + 32) != 0) {
                system("/bin/sh");
            } else {
                fwrite("Password:\n", 1, 10, stdout);
            }
        }
    }
    return 0;
}
