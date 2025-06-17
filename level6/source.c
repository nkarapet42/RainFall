#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void m(void *param_1, int param_2, char *param_3, int param_4, int param_5) {
    puts("Nope");
}

void n(void) {
    system("/bin/cat /home/user/level7/.pass");
}

int main(int argc, char **argv) {
    char *buffer;
    void (**func_ptr)(void *param_1, int param_2, char *param_3, int param_4, int param_5);

    buffer = (char *)malloc(0x40);
    func_ptr = (void (**)(void *, int, char *, int, int))malloc(sizeof(void *));
    
    *func_ptr = m;

    strcpy(buffer, argv[1]);

    (*func_ptr)(NULL, 0, NULL, 0, 0);

    return 0;
}
