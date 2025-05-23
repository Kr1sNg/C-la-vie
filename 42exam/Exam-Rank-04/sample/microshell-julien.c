#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
void        ft_print_error(char *str)
{
        int        i;
        i = 0;
        while (str[i])
                i++;
        write(2, str, i);
}
void        ft_cd(char *path, int i)
{
        if (i != 2)
                ft_print_error("error: cd: bad arguments\n");
        else if (chdir(path) == -1)
        {
                ft_print_error("error: cd: cannot change directory to ");
                ft_print_error(path);
                ft_print_error("\n");
        }
}
void        ft_exec(char **argv, int i, char **env)
{
        argv[i] = NULL;
        execve(argv[0], argv, env);
        ft_print_error("error: cannot execute ");
        ft_print_error(argv[0]);
        ft_print_error("\n");
}
void        ft_pipe(char **argv, int i, int fd[2], char **env)
{
        pid_t        pid;
        if (pipe(fd) == -1)
        {
                ft_print_error("error: fatal\n");
                exit(1);
        }
        pid = fork();
        if (pid == -1)
        {
                ft_print_error("error: fatal\n");
                exit(1);
        }
        if (pid == 0)
        {
                dup2(fd[1], 1);
                close(fd[0]);
                close(fd[1]);
                ft_exec(argv, i, env);
        }
        else
        {
                dup2(fd[0], 0);
                close(fd[0]);
                close(fd[1]);
        }
}
int        main(int argc, char **argv, char **env)
{
        int                i;
        int                fd[2];
        pid_t        pid;
        (void)argc;
        i = 0;
        while (argv[i] && argv[i + 1])
        {
                argv = &argv[i + 1];
                i = 0;
                while (argv[i]
                        && strcmp(argv[i], ";") != 0 && strcmp(argv[i], "|") != 0)
                        i++;
                if (strcmp(argv[0], "cd") == 0)
                        ft_cd(argv[1], i);
                else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
                {
                        pid = fork();
                        if (pid == -1)
                        {
                                ft_print_error("error: fatal\n");
                                exit(1);
                        }
                        if (pid == 0)
                                ft_exec(argv, i, env);
                        else
                        {
                                while (waitpid(-1, NULL, WUNTRACED) != -1)
                                        ;
                        }
                }
                else if (i != 0 && strcmp(argv[i], "|") == 0)
                        ft_pipe(argv, i, fd, env);
        }
        close(fd[0]);
        close(fd[1]);
}
