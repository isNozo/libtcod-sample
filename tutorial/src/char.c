#include <stdio.h>

void dump(void *str, int len)
{
    int i;
    int *p = (int *) str;

    printf("===\n");

    for(i=0; i<len; i++) {
        printf("[%p] = %08x\n", p, *p);
        p++;
    }
}

int main()
{
    dump("あいう", 3);
    dump(L"あいう", 3);
    dump(u"あいう", 3);
    dump(U"あいう", 3);

    return 0;
}