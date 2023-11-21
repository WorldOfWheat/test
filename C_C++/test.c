#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int ad = n + 1911;
    if (ad % 4 != 0) printf("平年\n");
    else if (ad % 100 != 0) printf("閏年\n");
    else if (ad % 400 != 0) printf("平年\n");
    else printf("閏年\n");

    return 0;
}