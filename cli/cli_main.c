#include <stdio.h>
#include "inc/cli_add.h"
#include "inc/cli_minus.h"

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 5;
    int c = 0;
	int d = 0;
    c = cliAdd(a, b);
	d = cliMinus(a,b);
    printf("cli main a+b = %d\r\n",c);
	printf("cli main a-b = %d\r\n",d);
    return 0;
}
