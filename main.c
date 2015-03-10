/*
** main.c for elcrypt in /home/zanard_a/rendu/Projets_TEK1/elcrypt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb 27 20:21:45 2015 Antoine Zanardi
** Last update Sun Mar  1 15:38:31 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"elcrypt.h"
#include	"union.h"

int		mode(char **argv)
{
  int		compt_argv;

  compt_argv = 1;
  while (argv[compt_argv] != '\0')
    {
      if (my_strcmp_exact("-d", argv[compt_argv], 0) == 0)
	return (0);
      else if (my_strcmp_exact("-e", argv[compt_argv], 0) == 0)
	return (1);
      compt_argv++;
    }
  return (-1);
}

int		version(char **argv)
{
  int		compt_argv;

  compt_argv = 0;
  while (argv[compt_argv] != '\0')
    {
      if (my_strcmp_exact("-1", argv[compt_argv], 0) == 0)
	return (0);
      else if (my_strcmp_exact("-2", argv[compt_argv], 0) == 0)
	return (1);
      compt_argv++;
    }
  return (1);
}

void		first_version(char **argv, t_data *data)
{
  t_block	key;

  if (mode(argv) == 1)
    {
      get_key(data, &key);
      fill_union(data, &key, 1);
    }
  else if (mode(argv) == 0)
    {
      get_key(data, &key);
      fill_union(data, &key, 0);
    }
  else if (mode(argv) == -1)
    my_putstr_error(10);
}

void		sec_version(char **argv, t_data *data)
{
  t_block	key;

  if (mode(argv) == 1)
    {
      get_keyv2(data, &key);
      fill_unionv2(data, &key, 1);
    }
  else if (mode(argv) == 0)
    {
      get_keyv2(data, &key);
      fill_unionv2(data, &key, 0);
    }
  else if (mode(argv) == -1)
    my_putstr_error(10);
}

int		main(int argc, char **argv)
{
  t_data	data;

  if (argc == 1 || argc > 9)
    my_putstr_error(1);
  init_argv(argv);
  parsing(argv);
  fill_data(&data, argv);
  if (version(argv) == 0)
    first_version(argv, &data);
  else if (version(argv) == 1)
    sec_version(argv, &data);
  return (0);
}
