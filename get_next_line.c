/*
** get_next_line.c for getnextline in /home/ouranos27/my_desktop/CPE/CPE_2016_getnextline
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Thu Jan  5 11:23:13 2017 philippe kam
** Last update Wed Feb 15 14:36:12 2017 philippe kam
*/

#include "get_next_line.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char	*my_realloc(char *s1, char *s2)
{
  char	*temp;
  int	i;
  int	j;

  i = 0;
  if ((temp = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2)) + 1)) == NULL)
    return (NULL);
  while (s2[i] != '\0')
    {
      temp[i] = s2[i];
      i = i + 1;
    }
  j = 0;
  while (s1[j] != '\0')
    {
      temp[i] = s1[j];
      i = i + 1;
      j = j + 1;
    }
  temp[i] = '\0';
  free(s2);
  return (temp);
}

char		*fill_buffer(char *buffer)
{
  static int   	i;
  int		j;
  static char		*temp;
  
  i = 0;
  j = 0;
  if ((temp = malloc(sizeof(char) * my_strlen(buffer) + 1)) == NULL)
    return (NULL);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	{
	  temp[j] = '\0';
	  return (temp);
	}
      else
	temp[j] = buffer[i];
      i = i + 1;
      j = j + 1;
    }
  if (buffer[i] == '\0')
    {
      temp[j] = '\0';
      free(buffer);
    }
  return (temp);
}

char		*get_next_line(const int fd)
{
  char		*read_buffer;
  static char		*temp;
  static char	*buffer;
  int		rep;
  int		i;

  i = 0;
  if ((read_buffer = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  if ((buffer = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  if ((temp = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  buffer[0] == '\0';
  while ((rep = read(fd, read_buffer, READ_SIZE)) > 0)
    {
      buffer = my_realloc(read_buffer, buffer);
    }
  /*while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	temp = fill_buffer(buffer);
      i = i + 1;
      }*/
  /*if (buffer[i] == '\0')
    temp = fill_buffer(buffer);*/
  return (buffer);
}

int	main()
{
  get_next_line(0);
  /*char	*s;

  while (s = get_next_line(0))
    {
      printf("%s\n", s);
      free(s);
      }*/
  return (0);
}
