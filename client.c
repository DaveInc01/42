#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(int ac, char ** argv)
{
    int pid = atoi(argv[1]);
    char * str = argv[2];
    int i = 0;
    int j;

    while (str[i] != '\0')
    {
        for (j = 7; j >= 0; j--)
        {
            if ((str[i] >> j & 1))
                kill(pid, SIGUSR1);
            else 
                kill(pid, SIGUSR2);
            usleep(100);
        }
        i++;
    }
    return (0);
}