#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int ac, char ** argv)
{
    int pid = atoi(argv[1]);
    char * str = argv[2];
    int i = 0;

    while (str[i] != '\0')
    {
        for (int j = 7; j >= 0; j--)
        {
            usleep(100);
            if ((str[i] & (1 << j)))
                kill(pid, SIGUSR1);
            else 
                kill(pid, SIGUSR2);
        }
        i++;
    }
}