#include <stdio.h>
int fat(int sub, int min)
{
    if (sub > min)
    {
        sub = sub - min;
        return fat(sub, min);
    }

    return sub;
}

int main()
{
    int sub = 11;
    int min = 3;
    printf("O resto da div eh: %d\n", fat(sub, min));
    return 0;
}
