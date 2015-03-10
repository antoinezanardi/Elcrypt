/*
** write_file.c for elcrypt in /home/zanard_a/rendu/Projets_TEK1/elcrypt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb 28 14:41:54 2015 Antoine Zanardi
** Last update Sun Mar  1 12:14:57 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"elcrypt.h"

int		check_padding(unsigned char *str, int pad)
{
  int		compt_str;

  compt_str = 0;
  while (compt_str < pad)
    {
      if (str[compt_str] == pad)
	compt_str++;
      else
	return (1);
    }
  return (0);
}

int		erase_padding(t_block *block, t_data *data)
{
  int		compt_write;
  int		compt_str;
  int		pad;

  compt_str = 0;
  compt_write = 0;
  pad = block->str[compt_str];
  if (block->str[compt_str] >= 3 && block->str[compt_str] <= 8)
    {
    if (check_padding(block->str, pad) == 0)
      {
	while (compt_write < (8 - pad))
	  {
	    write(data->fd_output, &(block->str[7 - compt_write]), 1);
	    compt_write++;
	  }
	return (0);
      }
    }
  return (1);
}

void		write_file(t_data *data, t_block sec)
{
  int		compt_write;

  compt_write = 0;
  while (compt_write < 8)
    {
      write(data->fd_output, &(sec.str[7 - compt_write]), 1);
      compt_write++;
    }
}
