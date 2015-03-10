/*
** init_parsing.c for init_parsing in /home/zanard_a/rendu/Projets_TEK1/elcrypt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb 27 21:34:33 2015 Antoine Zanardi
** Last update Sun Mar  1 14:47:48 2015 Antoine Zanardi
*/

#include	"elcrypt.h"

void		init_list(t_arg *list)
{
  list->d = 0;
  list->e = 0;
  list->f = 0;
  list->o = 0;
  list->k = 0;
  list->s = 0;
  list->c = 0;
}

void		check_list_arg(t_arg *list)
{
  if (list->d == 1 && list->e == 1)
    my_putstr_error(2);
  if (list->s == 1 && list->c == 1)
    my_putstr_error(12);
  if ((list->d == 0 && list->e == 0) ||
      (list->f == 0 || list->o == 0 ||
       list->k == 0))
      my_putstr_error(3);
  if (list->d > 1 || list->e > 1 ||
      (list->f > 1 || list->o > 1 ||
       list->k > 1) || list->s > 1 || list->c > 1)
    my_putstr_error(11);
}

void		init_argv(char **argv)
{
  int		compt_argv;
  t_arg		list;

  init_list(&list);
  compt_argv = 0;
  while (argv[++compt_argv] != '\0')
    {
      if (my_strcmp_exact("--usage", argv[compt_argv], 0) == 0)
	my_notice();
      else if (my_strcmp_exact("-d", argv[compt_argv], 0) == 0)
	list.d += 1;
      else if (my_strcmp_exact("-e", argv[compt_argv], 0) == 0)
	list.e += 1;
      else if (my_strcmp_exact("-f", argv[compt_argv], 0) == 0)
	list.f += 1;
      else if (my_strcmp_exact("-o", argv[compt_argv], 0) == 0)
	list.o += 1;
      else if (my_strcmp_exact("-k", argv[compt_argv], 0) == 0)
	list.k += 1;
      else if (my_strcmp_exact("-1", argv[compt_argv], 0) == 0)
	list.s += 1;
      else if (my_strcmp_exact("-2", argv[compt_argv], 0) == 0)
	list.c += 1;
    }
  check_list_arg(&list);
}
