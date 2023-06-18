#include <stdio.h>

void do_shell()
{
    system("/bin/sh\0");
}

int main()
{
    char buffer[20];
    gets(buffer);
    // do_shell();

    return 0;
}
