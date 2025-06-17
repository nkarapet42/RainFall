#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void p(void) {
    unsigned int unaff_retaddr;
    char local_50[76];

    fflush(stdout);
    gets(local_50);
    __asm__("movl 4(%%ebp), %0" : "=r"(unaff_retaddr));

    if ((unaff_retaddr & 0xb0000000) == 0xb0000000) {
        printf("(%p)\n", (void*)unaff_retaddr);
        _exit(1);
    }
    puts(local_50);
    strdup(local_50);
}

int main(void) {
    p();
    return 0;
}
