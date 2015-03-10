/*
** error.c for elcrypt in /home/zanard_a/rendu/Projets_TEK1/elcrypt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb 27 20:25:35 2015 Antoine Zanardi
** Last update Sun Mar  1 16:24:00 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"elcrypt.h"

void		my_notice()
{
  my_putstr("Notice : Elcrypt prend en paramètre : \n");
  my_putstr("-d : Elcrypt va déchiffrer\n");
  my_putstr("-e : Elcrypt va chiffrer\n");
  my_putstr("-f 'file_name' : Le fichier source\n");
  my_putstr("-o 'file_name' : Le fichier qui contiendra le résultat\n");
  my_putstr("-k 'clef' : La clef primaire de 64bits\n");
  my_putstr("-1 : Version numéro 1 du cryptage\n");
  my_putstr("-2 : Version numéro 2 du cryptage\n");
  my_putstr("Erreur existante : On ne peut utiliser -d et -e ensemble\n");
  exit(0);
}

void		my_putstr_error2(int error)
{
  if (error == 1)
    my_putstr("Le fichier d'output et input doivent être différents !\n");
  exit(1);
}

void		my_putstr_error(int error)
{
  if (error == 1)
    my_putstr("Le nombre d'argument est incorrect. Notice avec '--usage'\n");
  else if (error == 2)
    my_putstr("On ne peut chiffrer et déchiffrer en même temps\n");
  else if (error == 3)
    my_putstr("Il manque des arguments, veuillez checker la notice\n");
  else if (error == 4)
    my_putstr("Il manque des noms de fichier dans les arguments\n");
  else if (error == 5)
    my_putstr("La clé 64 bits est introuvable\n");
  else if (error == 6)
    my_putstr("Overflow dans la clef, elle ne peut dépasser 64 bits\n");
  else if (error == 7)
    my_putstr("Ceci n'est pas une clef valide\n");
  else if (error == 8)
    my_putstr("Impossible de lire dans le fichier\n");
  else if (error == 9)
    my_putstr("Malloc failed, end of program\n");
  else if (error == 10)
    my_putstr("Aucun mode n'a été trouvé\n");
  else if (error == 11)
    my_putstr("Des arguments sont spécifiés plusieurs fois\n");
  else if (error == 12)
    my_putstr("Vous ne pouvez spécifier qu'une version à la fois\n");
  exit(1);
}
