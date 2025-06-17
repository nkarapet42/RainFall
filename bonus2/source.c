#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int language = 0;

void greetuser(void) {
    char local_4c[4];
    char local_48[4];
    char local_44[64];

    if (language == 1) {
        local_4c[0] = 'H';
        local_4c[1] = 'y';
        local_4c[2] = 'v';
        local_4c[3] = (char)(-0x3d);
        local_48[0] = (char)(-0x5c);
        local_48[1] = (char)(-0x3d);
        local_48[2] = (char)(-0x5c);
        local_48[3] = ' ';
        strncpy(local_44, "päivää ", 11);
    }
    else if (language == 2) {
        strncpy(local_4c, "Goed", 4);
        local_48[0] = 'e';
        local_48[1] = 'm';
        local_48[2] = 'i';
        local_48[3] = 'd';
        strncpy(local_44, "dag!", 4);
        local_44[4] = ' ';
        local_44[5] = '\0';
    }
    else {
        strncpy(local_4c, "Hell", 4);
    }
    local_4c[4] = '\0';
    char greeting[128];
    snprintf(greeting, sizeof(greeting), "%s%s%s", local_4c, local_48, local_44);

    puts(greeting);
}

int main(int argc, char **argv) {
    char local_60[40];
    char acStack_38[36];
    char *lang_env;
    int i;

    if (argc == 3) {
        memset(local_60, 0, sizeof(local_60));
        strncpy(local_60, argv[1], sizeof(local_60) - 1);
        strncpy(acStack_38, argv[2], sizeof(acStack_38) - 1);

        lang_env = getenv("LANG");
        if (lang_env != NULL) {
            if (strncmp(lang_env, "fi", 2) == 0) {
                language = 1;
            }
            else if (strncmp(lang_env, "nl", 2) == 0) {
                language = 2;
            }
            else {
                language = 0;
            }
        }
        else {
            language = 0;
        }
        greetuser();

        return 0;
    }
    else {
        return 1;
    }
}
