/*
** cryptV2.c for elcrypt in /home/descam_d/rendu/elcrypt
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Sun Mar  1 10:24:52 2015 Corentin Descamps
** Last update Sun Mar  1 16:41:27 2015 Antoine Zanardi
*/

#include	"union.h"
#include	"elcrypt.h"

uint32_t	rotate(t_block *key, int n)
{
  uint32_t	left;
  uint32_t	right;

  right = key->block << 36 >> 36;
  left = key->block >> 28;
  left = (left << n) | (left >> (28 - n));
  right = (right << n) | (right >> (28 - n));
  return ((right >> 16) | (left << 16));
}

void		dekryptonv2(t_block *block, t_data *data, t_block *key)
{
  uint64_t	tmp;
  uint32_t	right;
  uint32_t	left;
  uint32_t	poly;
  t_block	sec;
  int		n;

  n = 15;
  swap(block);
  sec = *key;
  right = block->part[0];
  left = block->part[1];
  while (n >= 0)
    {
      sec.block = rotate(key, n);
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

void		kryptonv2(t_block *block, t_data *data, t_block *key)
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
  while (n < 16)
    {
      sec.block = rotate(key, n);
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
