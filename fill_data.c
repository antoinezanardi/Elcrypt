/*
** fill_data.c for elcrypt in /home/zanard_a/rendu/Projets_TEK1/elcrypt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb 28 10:30:31 2015 Antoine Zanardi
** Last update Sun Mar  1 16:27:11 2015 Antoine Zanardi
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<limits.h>
#include	<stdint.h>
#include	"elcrypt.h"

void		fill_fd(t_data *data, char **argv)
{
  int		compt_argv;

  compt_argv = 1;
  while (argv[compt_argv] != '\0')
    {
      if (my_strcmp_exact("-f", argv[compt_argv], 0) == 0)
	data->fd_input = open(argv[compt_argv + 1], O_RDONLY);
      else if (my_strcmp_exact("-o", argv[compt_argv], 0) == 0)
	data->fd_output = open(argv[compt_argv + 1], O_RDWR);
      compt_argv++;
    }
}

void		fill_key(t_data *data, char **argv)
{
  char		*endptr;
  int		compt_argv;


  compt_argv = 0;
  while (argv[compt_argv] != '\0')
    {
      if (my_strcmp_exact("-k", argv[compt_argv], 0) == 0)
	{
	  if (argv[compt_argv + 1] != '\0' && argv[compt_argv + 1][0] == '\0')
	    my_putstr_error(7);
	  if ((data->key = strtoul(argv[compt_argv + 1],
				   &endptr, 0)) == ULONG_MAX)
	    my_putstr_error(6);
	  if (*endptr != '\0')
	    my_putstr_error(7);
	}
      compt_argv++;
    }
}

void		fill_data(t_data *data, char **argv)
{
  fill_fd(data, argv);
  fill_key(data, argv);
}
