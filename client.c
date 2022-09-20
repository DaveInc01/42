#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(int ac, char ** argv)
{
    int     pid = atoi(argv[1]);
    char    *str;
    int     j;

    str = argv[2];
    int i = 0;

    while (str[i] != '\0')
    {
        j = 7;
        while (j >= 0)
        {
            if ((str[i] >> j & 1))
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(100);
            j--;
        }
        i++;
    }
    return (0);
}
