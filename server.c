#include <stdio.h>
#include <unistd.h>
#include <signal.h>

char c = 0x00; 

void handler(int sig)
{
    //printf("%d\n", sig);
    static int c;
    static int i;

    c = 0;
    if(sig == SIGUSR1)
    {
        printf("1");
        c = ((c << i) | 1);
    }
    else
    {
        printf("0");
        c = ((c << i) | 0);
    }   
    if (++i == 8)
    {
        printf("8 bits\n");
        printf("%d", c);
        write(1, &c, 1);
        c = 0;
        i = 0;
    }
}

int main()
{
    struct sigaction sig_flags;

    sig_flags.sa_handler = handler;
    sig_flags.sa_flags = SA_RESTART;

    printf("%d\n", getpid());
    sigaction(SIGUSR1, &sig_flags, 0);
    sigaction(SIGUSR2, &sig_flags, 0);
    while (1);
}