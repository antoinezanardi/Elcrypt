/*
** fc_str.c for corewar in /home/zanard_a/rendu/Projets_TEK1/CPE_2014_corewar/asm
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb 27 15:54:01 2015 Antoine Zanardi
** Last update Sat Feb 28 14:00:48 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"elcrypt.h"

int		my_strlen(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    compt_str++;
  return (compt_str);
}

char		*my_str_dup(char *str)
{
  char		*dest;
  int		compt_str;

  compt_str = 0;
  if ((dest = malloc(sizeof(char) * my_strlen(str))) == NULL)
    my_putstr_error(9);
  while (str[compt_str] != '\0')
    {
      dest[compt_str] = str[compt_str];
      compt_str++;
    }
  dest[compt_str] = '\0';
  return (dest);
}

int		my_strcmp_exact(char *str, char *str2, int compt2)
{
  int		compt;

  compt = 0;
  while (str[compt] != '\0')
    {
      if (str2[compt2] == '\0' || str[compt] != str2[compt2])
	return (1);
      else
	{
	  compt++;
	  compt2++;
	}
    }
  if (str[compt] != '\0' || str2[compt2] != '\0')
    return (1);
  return (0);
}

int		my_strcmp(char *str, char *str2, int compt2)
{
  int		compt;

  compt = 0;
  while (str[compt] != '\0')
    {
      if (str2[compt2] == '\0' || str[compt] != str2[compt2])
	return (1);
      else
	{
	  compt++;
	  compt2++;
	}
    }
  return (0);
}
