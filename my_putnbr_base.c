/*
** putnbr_base.c for  in /home/ducate_c/rendu/102chiffrement
** 
** Made by Corentin Ducatez
** Login   <ducate_c@epitech.net>
** 
** Started on  Wed Apr 29 19:56:11 2015 Corentin Ducatez
** Last update Wed Apr 29 19:58:38 2015 Corentin Ducatez
*/

#include	<string.h>

int		my_putnbr_base(int nbr, char *base)
{
  int		a;
  int		diviseur;
  int		result;

  a = (nbr < 0) ? 1 : 0;
  if (nbr < 0)
    {
      write(1, "-", 1);
      nbr = -nbr;
    }
  diviseur = 1;
  while ((nbr / diviseur) >= strlen(base))
    diviseur = diviseur * strlen(base);
  while (diviseur > 0)
    {
      result = (nbr / diviseur) % strlen(base);
      write(1, &base[result], 1);
      diviseur /= strlen(base);
      a++;
    }
  return (a);
}
