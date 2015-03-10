/*
** get_key.c for elcrypt in /home/descam_d/rendu/elcrypt
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Sat Feb 28 11:02:06 2015 Corentin Descamps
** Last update Sun Mar  1 10:39:21 2015 Corentin Descamps
*/

#include	"union.h"
#include	"elcrypt.h"

uint64_t	modif_key(t_block *key)
{
  int		i;
  uint64_t	result;
  unsigned char	tmp;

  i = 0;
  result = 0;
  while (i < 8)
    {
      tmp = key->str[i] >> 1;
      result = result | ((uint64_t)tmp << (7 * i));
      i++;
    }
  return (result);
}

void	get_key(t_data *data, t_block *key)
{
  key->block = data->key;
  key->block = modif_key(key);
}
