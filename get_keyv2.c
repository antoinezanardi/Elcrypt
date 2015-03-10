/*
** get_keyV2.c for elcrypt in /home/descam_d/rendu/elcrypt
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Sun Mar  1 10:26:07 2015 Corentin Descamps
** Last update Sun Mar  1 15:38:48 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"union.h"
#include	"elcrypt.h"

int	is_pair(t_block *key)
{
  int	i;

  i = 0;
  while (i < 8)
    {
      if ((key->str[i] & 1) == 1)
	i++;
      else
	{
	  my_putstr("Les bits de parités ne sont pas tous à 1\n");
	  exit(1);
	}
    }
  return (0);
}

void	get_keyv2(t_data *data, t_block *key)
{
  key->block = data->key;
  if (is_pair(key) == 0)
    key->block = modif_key(key);
}
