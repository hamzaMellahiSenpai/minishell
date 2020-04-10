#include "headers/minishell.h"


/**
  @brief Launch a program and wait for it to terminate.
  @param args Null terminated list of arguments (including program).
  @return Always returns 1, to continue execution.
 */
t_string    shell_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1)
      handle_error(INDEFINED_CMD, FAIL);
  } else if (pid < 0) {
    // Error forking
    perror("shell");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return "1";
}

/**
   Loop getting input and executing it.
 */
void shell_loop(void)
{
  t_string  line;
  char **args;
  t_string  status;
  t_string  *cmds;
  t_string *x;
  t_string *y;

  status = ft_strdup("");
  while (status)
  {
    ft_putstr(shell.curr_dir);
    read_line(STDIN, &line);
    if (!*line)
      return (event_handler(CTRL_D));    
    cmds = split(line, ';');
    while(*cmds)
    {
      shell.output = ft_strdup("");
      x = split(*cmds ,'>');
      args = split(x[0], ' ');
      status = execute(args);
      if (x[1])
      {
        y = split(x[1] ,' ');
        if (!y[0] == '>')
        {
        
        }
        int fd = open(y[0],  O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
        int len = ft_strlen(shell.output);
        write(fd, shell.output, len);
        shell.max_output_len = len > shell.max_output_len ? len : shell.max_output_len ;
      }
      else if (ft_strchr(*cmds, '>'))
        ft_putstr("error: syntax error");
      else
        ft_putstr(shell.output);
      cmds++;
    }
    //free_all();
  }
}