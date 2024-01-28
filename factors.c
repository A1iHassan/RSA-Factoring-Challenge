#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    char *line = NULL;
    size_t n = 0;
    ssize_t nchr = 0;
    int num, i;
    FILE *file = fopen(argv[1], "r");

    while ((nchr = getline(&line, &n, file)) != -1)
    {
        num = atoi(line);
        
        for (i = 2; i < 6; i++)
        {
            if (num % i == 0)
            {
                printf("%d=%d*%d\n", num, num / i, i);
                break;
            }
        }
    }

    free(line);
    return (0);
}