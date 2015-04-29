/*
** la_crypto_c_cool.c for 102_chiffrement in /home/ducate_c/rendu/102chiffrement
**
** Made by Corentin Ducatez
** Login   <ducate_c@epitech.net>
**
** Started on  Mon Nov 24 16:34:16 2014 Corentin Ducatez
** Last update Wed Apr 29 20:28:22 2015 Corentin Ducatez
*/

#include	<math.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>

static int	my_tab_int(int size, char *str, int b)
{
  int		tab[size + 1];
  int		a;

  a = 0;
  tab[size] = '\0';
  if (str[a] == '\0')
    return (0);
  while (str[a] != '\0')
    {
      if (str[a] >= 'a' && str[a] <= 'z')
	tab[a] = str[a] - 96;
      else
	tab[a] = 0;
      a++;
    }
  return (tab[b]);
}

static int	my_code_function(char *str, char *base,
				 int cle1, int cle2, int cle3, int cle4)
{
  int		tab[strlen(str) + 1];
  int		a;
  int		result[strlen(str) + 1];
  unsigned int	size = strlen(str);

  a = -1;
  while (a++ != (size = ((size % 2) == 1) ? size : size - 1))
    tab[a] = my_tab_int(size, str, a);
  a = 0;
  while (a != (size = ((size % 2) == 1) ? size + 1: size))
    {
      result[a] = (cle1 * tab[a]) + (cle3 * tab[a + 1]);
      result[a + 1] = (cle2 * tab[a]) + (cle4 * tab[a + 1]);
      my_putnbr_base(result[a], base);
      write(1, " ", 1);
      my_putnbr_base(result[a + 1], base);
      write(1, " ", 1);
      a += 2;
    }
  write(1, "\n", 1);
  return (0);
}

static int	my_decode_function(char *str, char *base,
				   float cle1, float cle2, float cle3, float cle4, float det)
{
  int		tab[strlen(str) + 1];
  int		a = -1;
  int		b;
  int		c;
  int		d = 0;
  int		f;
  int		r;
  unsigned int	size = strlen(str);

  while (a++ != size)
    tab[a] = 0;
  a = 0;
  while (str[a] != '\0')
    {
      c = 0;
      f = a;
      b = 0;
      while (str[f] != ' ' && str[f] != '\0')
	f++;
      while (a != f)
	{
	  while (str[a] != base[b])
	    b++;
	  c = pow(strlen(base), (f - a - 1));
	  tab[d] += (b * c);
	  a++;
	  b = 0;
	}
      d++;
      if (str[a] != '\0')
	a++;
    }
  c = 0;
  d = 1;
  while (str[c] != '\0')
    {
      d = (str[c] == ' ') ? d + 1 : d;
      c++;
    }
  a = 0;
  if (d == 1)
    {
      printf("Aucun message n'a pu être codé de cette manière: Décodage impossible\n");
      exit(0);
    }
  else
    {
      while (a != (d = ((d % 2) == 1) ? d - 1 : d))
	{
	  r = (cle1 * tab[a] * det) + (cle3 * tab[a + 1] * det);
	  my_putnbr_base(r, " abcdefghijklmnopqrstuvwxyz");
	  r = (tab[a] * cle2 * det) + (tab[a + 1] * cle4 * det);
	  my_putnbr_base(r, " abcdefghijklmnopqrstuvwxyz");
	  a += 2;
	}
    }
  write(1, "\n", 1);
  return (0);
}

int	main(int ac, char **av)
{
  float	a;
  float	b;
  float	c;
  float	d;
  float	det;

  my_check_error(ac, av);
  a = atoi(av[2]);
  b = atoi(av[3]);
  c = atoi(av[4]);
  d = atoi(av[5]);
  det = 1 / ((a * d) - (b * c));
  if (av[7][0] == '0')
    {
      printf("Chiffrement de %s à l'aide de la clé %s %s %s %s dans la base %s:\n",
	     av[1], av[2], av[3], av[4], av[5], av[6]);
      my_code_function(av[1], av[6], a, b, c, d);
    }
  else if (av[7][0] == '1')
    {
      if (((a * d) - (b * c)) == 0)
	{
	  printf("La matrice clé n'est pas inversible\n");
	  exit(0);
	}
      printf("Déchiffrement de %s à l'aide de la clé %s %s %s %s dans la base %s:\n",
	     av[1], av[2], av[3], av[4], av[5], av[6]);
      my_decode_function(av[1], av[6], d, -b, -c, a, det);
    }
  return (0);
}
