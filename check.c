/*
** check.c for  in /home/ducate_c/rendu/github/102chiffrement
** 
** Made by Corentin Ducatez
** Login   <ducate_c@epitech.net>
** 
** Started on  Wed Apr 29 20:01:44 2015 Corentin Ducatez
** Last update Wed Apr 29 20:27:45 2015 Corentin Ducatez
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>

static void	check_base(char *base, int *counter)
{
  int		b = 0;
  int		c;

  while (base[b] != '\0')
    {
      c = b + 1;
      while (base[c] != '\0' && base[c] != base[b])
        c++;
      if (base[c] == '\0')
        b++;
      else
        {
          printf("La base ne doit pas comporter deux fois le même caractère: BASE INVALIDE\n");
          *counter += 1;
          break;
        }
    }
}
static void	check_my_key(char **av, int *counter)
{
  int		a = 2;
  int		b;

  while (a < 6)
    {
      b = 0;
      while (av[a][b] != '\0')
	{
	  if (av[a][b] != '-' && av[a][b] != '+' && (av[a][b] < '0' || av[a][b] > '9'))
	    {
	      printf("Le paramètre %d de la clé doit être un nombre entier\
et ne pas contenir de caractères autre que des chiffres\n", a - 1);
	      *counter += 1;
	    }
	  b++;
	}
      a++;
    }
}

static void	check_nbr_arg_or_empty(int ac, char **av, int *counter)
{
  int		a = 1;

  if (ac < 8)
    {
      printf("Le nombre d'arguments doit être de 8, il manque\
%d arguments actuellement\n", (8 - ac));
      exit(0);
    }
  if (ac > 8)
    {
      printf("Le nombre d'arguments doit être de 8, il y a %d\
arguments en trop actuellement\n", (ac - 8));
      exit(0);
    }
  while (av[a] != NULL)
    if (av[a++][0] == '\0')
      {
	printf("Le paramètre %d ne doit pas être vide\n", a - 1);
	*counter += 1;
      }
}
void	my_check_error(int ac, char **av)
{
  int	a = 0;
  int	b = 0;
  int	c = 0;

  check_nbr_arg_or_empty(ac, av, &a);
  if (av[7][0] == '0' && av[7][1] == '\0')
    {
      while (av[1][b] != '\0')
	{
	  if (av[1][b] == ' ')
	    b++;
	  else if (av[1][b] <= 'z' && av[1][b] >= 'a')
	    b++;
	  else
	    {
	      printf("Seul les caractères allant de 'a' à 'z'\
ainsi que l'espace sont autorisés dans le message\n");
	      a++;
	      break;
	    }
	}
    }
  check_my_key(av, &a);
  b = 0;
  if (strlen(av[6]) < 2)
    {
      a++;
      printf("La base doit contenir au moins 2 caractères\n");
    }
  if ((av[7][0] != '0' && av[7][0] != '1') || av[7][1] != '\0')
    {
      printf("L'argument 7 indique si il faut déchiffrer ou chiffre\
et doit être de 0 pour chiffrer ou de 1 dans le cas contraire\
\n");
      a++;
    }
  else if (av[7][0] == '1')
    {
      while (av[1][b] != '\0')
        {
          while (av[1][b] != av[6][c] && av[6][c] != '\0')
            c++;
          if (av[1][b] == ' ')
            c = 0;
          else if (av[6][c] == '\0')
            {
              printf("Le message doit uniquement contenir les caractères de la\
base et des espaces entre chaque groupe de lettres\
\n");
              a++;
            }
          b++;
          c = 0;
        }
    }
  check_base(av[6], &a);
  b = 0;
  if ((atoi(av[2]) * atoi(av[5]) - (atoi(av[3]) * atoi(av[4])) == 0))
    {
      printf("La matrice cle n'est pas inversible donc le décodage est impossible\n");
      a++;
    }
  if (a > 0)
    exit (0);
}
