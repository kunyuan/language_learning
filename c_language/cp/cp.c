#include <stdio.h>
main()
{
    int c;
    /*while((c=getchar())!=EOF)*/
        /*putchar(c);*/

    c=getchar();
    /*printf("%d, %c\n", EOF, EOF);*/
    while(c!=EOF)
    {
        putchar(c);
        c=getchar();
        /*printf("\n%d, %c\n", c, c);*/
    }
}
