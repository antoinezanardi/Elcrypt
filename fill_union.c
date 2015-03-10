/*
** fill_union.c for elcrypt in /home/zanard_a/rendu/Projets_TEK1/elcrypt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb 28 13:02:55 2015 Antoine Zanardi
** Last update Sun Mar  1 15:52:44 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"union.h"
#include	"elcrypt.h"

void		padding(t_block *block, int ret)
{
  int		save_ret;

  save_ret = 8 - ret;
  while (ret < 8)
    {
      block->str[ret] = save_ret;
      ret++;
    }
}

void		fill_unionv2(t_data *data, t_block *key, int mode)
{
  t_block	block;
  int		ret;

  while ((ret = read(data->fd_input, block.str, 8)) > 0)
    {
      if (ret != 8)
	padding(&block, ret);
      if (mode == 1)
	kryptonv2(&block, data, key);
      else if (mode == 0)
	dekryptonv2(&block, data, key);
    }
  close(data->fd_input);
  if (ret < 0)
    my_putstr_error(8);
}

void		fill_union(t_data *data, t_block *key, int mode)
{
  t_block	block;
  int		ret;

  while ((ret = read(data->fd_input, block.str, 8)) > 0)
    {
      if (ret != 8)
	padding(&block, ret);
      if (mode == 1)
	krypton(&block, data, key);
      else if (mode == 0)
	dekrypton(&block, data, key);
    }
  close(data->fd_input);
  if (ret < 0)
    my_putstr_error(8);
}
