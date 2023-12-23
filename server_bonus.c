#include "minitalk.h"

void handle_message(int pid, siginfo_t *info, void *ucontent)
{
     static int bit_handle = -1;
     static unsigned char   mssg;

     (void) ucontent;
     if (bit_handle < 0) 
        bit_handle = 7;

    if(pid == SIGUSR1)
        mssg |= (1 << bit_handle);
    bit_handle--;
    if (bit_handle < 0)
    {
        write(STDOUT_FILENO, &mssg, 1);
        mssg = 0;
        bit_handle = -1;
        if(kill(info->si_pid, SIGUSR2) == -1)
            ft_putstr("Error SIGUSR1");
    }
     
}

void ft_signhandle(void)
{
    struct sigaction sa;
    
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = &handle_message;
    sa.sa_flags = SA_SIGINFO;
    if(sigaction(SIGUSR1, &sa, NULL) == -1)
        ft_putstr("Error with the SIGUSR1");
    if(sigaction (SIGUSR2, &sa, NULL) == -1)
        ft_putstr("Error with the SIGUSR2");
}
int main(void)
{
    write(STDOUT_FILENO, ANSI_BOLD ANSI_COLOR_MAGENTA, sizeof(ANSI_BOLD ANSI_COLOR_MAGENTA) - 1); 
    ft_putstr("\t_______This is my minitalk server______\n\n");
    write(STDOUT_FILENO, ANSI_BOLD ANSI_COLOR_CYAN, sizeof(ANSI_BOLD ANSI_COLOR_CYAN) - 1);
    ft_putstr("This is the PID Number : \n");
    ft_putnbr(getpid());
    write(1, "\n", 1);
    while(1)
        ft_signhandle();
    return(EXIT_SUCCESS);
}