/*
** fc_base.c for elcrypt in /home/zanard_a/rendu/Projets_TEK1/elcrypt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb 27 20:33:42 2015 Antoine Zanardi
** Last update Fri Feb 27 20:36:04 2015 Antoine Zanardi
*/

#include	<unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      my_putchar(str[compt_str]);
      compt_str++;
    }
}
