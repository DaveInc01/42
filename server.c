#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void handler(int sig, siginfo_t *info, void *context)
{
    static char c;
    static int i = 0;

	(void)context;
	if (sig == SIGUSR1)
        c = c | 1;
    if (++i == 8)
    {
		write(1, &c, 1);
        c = 0;
        i = 0;
    }
	else
		c <<= 1;
}

int main()
{
    struct sigaction sig_flags;

    sig_flags.sa_sigaction = handler;
	sig_flags.sa_flags = SA_SIGINFO;
    sig_flags.sa_flags = SA_RESTART;

    printf("%d\n", getpid());
    sigaction(SIGUSR1, &sig_flags, 0);
    sigaction(SIGUSR2, &sig_flags, 0);
    while (1);
}
