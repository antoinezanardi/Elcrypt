/*
** union.h for elcrypt in /home/descam_d/rendu/elcrypt/include
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Sat Feb 28 10:12:45 2015 Corentin Descamps
** Last update Sun Mar  1 11:50:06 2015 Corentin Descamps
*/

#ifndef		UNION_H_
# define	UNION_H_

# include	<stdint.h>

typedef union	u_block
{
  uint64_t	block;
  uint32_t	part[2];
  unsigned char	str[8];
}		t_block;

#endif		/* UNION_H_ */
