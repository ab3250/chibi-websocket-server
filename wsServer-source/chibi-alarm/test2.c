#include <signal.h>
#include <errno.h>

void signal_responder(int signum, siginfo_t *info, void *data)
{
    const long index = (long)data;
    if (index >= 0L && index < MONITORED_VALUES) {
        union sigval response;
        response.sival_ptr = (void *)__sync_or_and_fetch(&monitored_value[index], 0L);
        sigqueue(info->si_pid, signum, response);
    }
}

/* Signal handler installer */
int install_signal_responder(const int rtsignum)
{
    struct sigaction  act;

    sigemptyset(&act.sa_mask);
    act.sa_sigaction = signal_responder;
    act.sa_flags = SA_RESTART | SA_SIGINFO;
    if (sigaction(SIGRTMIN + rtsignum, &act, NULL) == -1)
        return errno;

    return 0;
}
