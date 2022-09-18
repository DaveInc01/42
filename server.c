#include <stdio.h>
#include <unistd.h>
#include <signal.h>

char c = 0x00; 

void handler(int sig)
{
    //printf("%d\n", sig);
    if(sig == SIGUSR1)
        printf("1\n");
    else
        printf("0\n");
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