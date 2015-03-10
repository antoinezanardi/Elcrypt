/*
** crypt.c for elcrypt in /home/descam_d/rendu/elcrypt
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Sat Feb 28 13:38:36 2015 Corentin Descamps
** Last update Sun Mar  1 16:41:29 2015 Antoine Zanardi
*/

#include	"elcrypt.h"
#include	"union.h"

void		swap(t_block *block)
{
  unsigned char	tmp;
  int		i;

  i = 0;
  while (i < 4)
    {
      tmp = block->str[i];
      block->str[i] = block->str[7 - i];
      block->str[7 - i] = tmp;
      i++;
    }
}

void		dekrypton(t_block *block, t_data *data, t_block *key)
{
  uint64_t	tmp;
  uint32_t	right;
  uint32_t	left;
  uint32_t	poly;
  t_block	sec;
  int		n;

  n = 7;
  swap(block);
  sec = *key;
  right = block->part[0];
  left = block->part[1];
  while (n >= 0)
    {
      sec.block = ((key->block << (4 * n)) | (key->block >> (56 - 4 * n)));
      poly = sec.block ^ right;
      tmp = right;
      right = poly ^ left;
      left = tmp;
      n--;
    }
  sec.part[0] = left;
  sec.part[1] = right;
  if (erase_padding(&sec, data) == 1)
    write_file(data, sec);
}

void		krypton(t_block *block, t_data *data, t_block *key)
{
  uint64_t	tmp;
  uint32_t	right;
  uint32_t	left;
  uint32_t	poly;
  t_block	sec;
  int		n;

  n = 0;
  swap(block);
  sec = *key;
  right = block->part[0];
  left = block->part[1];
  while (n < 8)
    {
      sec.block = ((key->block << (4 * n)) | (key->block >> (56 - 4 * n)));
      poly = sec.block ^ right;
      tmp = right;
      right = poly ^ left;
      left = tmp;
      n++;
    }
  sec.part[0] = left;
  sec.part[1] = right;
  write_file(data, sec);
}
