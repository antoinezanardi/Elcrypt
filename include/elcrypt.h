/*
** elcrypt.h for elcrypt in /home/zanard_a/rendu/Projets_TEK1/elcrypt/include
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb 27 20:24:24 2015 Antoine Zanardi
** Last update Sun Mar  1 16:38:04 2015 Antoine Zanardi
*/

#ifndef		ELCRYPT_H_
# define	ELCRYPT_H_

# include	<stdint.h>
# include	"union.h"

typedef struct	s_arg
{
  int		d;
  int		e;
  int		f;
  int		o;
  int		k;
  int		s;
  int		c;
}		t_arg;

typedef struct	s_data
{
  int		fd_input;
  int		fd_output;
  uint64_t	key;
}		t_data;

void		my_putstr(char *);
void		my_putstr_error(int);
void		my_putstr_error2(int);
void		my_notice(void);
void		init_argv(char **);
void		parsing(char **);
void		fill_data(t_data *, char **);
void		fill_union(t_data *, t_block *, int);
void		fill_unionv2(t_data *, t_block *, int);
void		get_key(t_data *, t_block *);
void		get_keyv2(t_data *, t_block *);
void		krypton(t_block *, t_data *, t_block *);
void		kryptonv2(t_block *, t_data *, t_block *);
void		dekrypton(t_block *, t_data *, t_block *);
void		dekryptonv2(t_block *, t_data *, t_block *);
void		write_file(t_data *, t_block);
void		swap(t_block *);
int		erase_padding(t_block *, t_data *);
int		check_padding(unsigned char *, int);
int		my_strcmp_exact(char *, char *, int);
int		my_strcmp(char *, char *, int);
uint64_t	modif_key(t_block *);

#endif		/* !ELCRYPT_H_ */
