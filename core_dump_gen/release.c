
#include <stdio.h>
#define __USE_GNU 
#include <ucontext.h> 
#include <stdlib.h>
#include<signal.h>
#include<unistd.h>
#include <execinfo.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <execinfo.h>


void print_bt(int sig, siginfo_t *info, void *secret) 
{

    void *trace[16];
    char **messages = (char **)NULL;
    int i, trace_size = 0;
    ucontext_t *uc = (ucontext_t *)secret;

    /* Do something useful with siginfo_t */
    if (sig == SIGSEGV)
        printf("Got signal %d, faulty address is %p, "
               "from %p\n", sig, info->si_addr,
               uc->uc_mcontext.gregs[REG_RIP]);
    else
        printf("Got signal %d#92;n", sig);

    trace_size = backtrace(trace, 16);
    /* overwrite sigaction with caller's address */
    trace[1] = (void *) uc->uc_mcontext.gregs[REG_RIP];

    messages = backtrace_symbols(trace, trace_size);
    /* skip first stack frame (points here) */
    printf("[bt] Execution path:\n");
    for (i=1; i<trace_size; ++i)
        printf("[bt] %s\n", messages[i]);
    
    if(sig !=SIGUSR1)
        exit(0);
}


//from stack overflow
void sig_handler(int signo, siginfo_t *info, void *secret)
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");

    //BT print
    print_bt(signo, info, secret);
    // Enable Core
    // Try to enable core dumps
    struct rlimit core_limit;
    core_limit.rlim_cur = RLIM_INFINITY;
    core_limit.rlim_max = RLIM_INFINITY;

    if(setrlimit(RLIMIT_CORE, &core_limit) < 0)
        fprintf(stderr, "\nWarning: core dumps may be truncated or non-existant\n");


    if(fork() == 0)
        abort();
}

int division(int a, int b);

int m;

int main(void)
{
    int i;
    int j;
    int *k =0;
  

 /* Install our signal handler */
  struct sigaction sa;

  sa.sa_sigaction = (void *)sig_handler;
  sigemptyset (&sa.sa_mask);
  sa.sa_flags = SA_RESTART | SA_SIGINFO;

  sigaction(SIGSEGV, &sa, NULL);
  sigaction(SIGUSR1, &sa, NULL);
  /* ... add any other signal here */  

    printf("value i\n");
    i = 10;

    printf("value j\n");
    j = 1;


    printf ("i = %d, j = %d\n", i, j);
    m = division(i, j);

    printf("m = %d / %d = %d\n", i, j, m);

    printf("\nI am waiting ......\r\n");
    while(1)
    {
        printf("..");
        sleep(2);
    }
    return 0;
}

int division(int a, int b)
{
    return a / b;
}
