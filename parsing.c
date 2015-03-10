/*
** parsing.c for parsing in /home/zanard_a/rendu/Projets_TEK1/elcrypt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb 28 09:00:26 2015 Antoine Zanardi
** Last update Sun Mar  1 16:27:22 2015 Antoine Zanardi
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"elcrypt.h"

void		correct_file(char *file)
{
  int		fd;

  if (file == NULL)
    my_putstr_error(4);
  if ((fd = open(file, O_RDWR | O_CREAT | O_APPEND, S_IRUSR |
                 S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    {
      my_putstr(file);
      my_putstr(" Couldn't be found or red\n");
      exit(1);
    }
  close(fd);
}

void		correct_file_rd(char *file)
{
  int		fd;

  if (file == NULL)
    my_putstr_error(4);
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      my_putstr(file);
      my_putstr(" Couldn't be found or red\n");
      exit(1);
    }
  close(fd);
}

void		check_files(char **argv)
{
  int		compt_argv;

  compt_argv = 0;
  while (argv[compt_argv] != '\0')
    {
      if (my_strcmp_exact("-f", argv[compt_argv], 0) == 0)
	correct_file_rd(argv[compt_argv + 1]);
      else if (my_strcmp_exact("-o", argv[compt_argv], 0) == 0)
	correct_file(argv[compt_argv + 1]);
      compt_argv++;
    }
}

void		correct_key(char **argv)
{
  int		compt_argv;

  compt_argv = 0;
  while (argv[compt_argv] != '\0')
    {
      if (my_strcmp_exact("-k", argv[compt_argv], 0) == 0)
	if (argv[compt_argv + 1] == '\0')
	  my_putstr_error(5);
      compt_argv++;
    }
}

void		parsing(char **argv)
{
  int		compt_argv;
  int		compt_input;
  int		compt_output;

  check_files(argv);
  correct_key(argv);
  compt_argv = 0;
  while (argv[compt_argv] != '\0')
    {
      if (my_strcmp_exact("-f", argv[compt_argv], 0) == 0)
	compt_input = compt_argv + 1;
      else if (my_strcmp_exact("-o", argv[compt_argv], 0) == 0)
	compt_output = compt_argv + 1;
      compt_argv++;
    }
  if (my_strcmp_exact(argv[compt_input], argv[compt_output], 0) == 0)
    my_putstr_error2(1);
}
