#include <stdio.h>
#include <stdlib.h>

void run(void)
{
    fwrite("Good... Wait what?\n", 1, 0x13, stdout);
    system("/bin/sh");
    return;
}

int main(void)
{
    char local_50[76];
    
    gets(local_50);
    return 0;
}
