#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void foo()
{
    printf("foo\n");
}
void foo2()
{
    printf("foo2\n");
}
void foo3()
{
    printf("foo3\n");
}

int main()
{
    void (*func[3]) () = {foo, foo2, foo3};
    for (int i = 0; i <= 2; i++)
    {
        func[i]();
    }

    return 0;
}