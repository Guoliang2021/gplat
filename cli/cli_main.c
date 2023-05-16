#include <stdio.h>
#include "inc/cli_add.h"

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 5;
    int c = 0;
    c = cliAdd(a, b);
    printf("cli main a+b = %d\r\n",c);
    return 0;
}
