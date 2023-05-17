/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:24:37 by bbendiou          #+#    #+#             */
/*   Updated: 2023/05/10 17:25:01 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_line_with_newline(char *str)
{
	char	*output;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	output = malloc(i + 2);
	if (!output)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		output[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		output[i] = str[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

int	ft_check_newline(char *ptr)
{
	while (*ptr)
	{
		if (*ptr == '\n')
			return (1);
		ptr++;
	}
	return (0);
}

char	*ft_read(int fd, char *container)
{
	char	*buff;
	int		i;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(container);
			return (NULL);
		}
		if (i == 0)
			break ;
		buff[i] = '\0';
		container = ft_strjoin(container, buff);
		if (ft_check_newline(buff))
			break ;
	}
	free(buff);
	return (container);
}

char	*ft_rest(char *str)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0' || (str[i] == '\n' && str[i + 1] == '\0'))
		return (NULL);
	output = malloc(ft_strlen(str) - i);
	if (!output)
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		output[j++] = str[i++];
	output[j] = '\0';
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;
	char		*tmp;

	container = ft_read(fd, container);
	if (BUFFER_SIZE == 0 || fd < 0 || !container)
		return (NULL);
	tmp = container;
	line = ft_line_with_newline(tmp);
	container = ft_rest(tmp);
	free(tmp);
	return (line);
}
