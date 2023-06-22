/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:37:30 by mprofett          #+#    #+#             */
/*   Updated: 2022/10/25 09:37:32 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		if (s[i] == '\0')
			return (i);
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

char	*reset_str(char *s)
{
	free(s);
	s = NULL;
	return (s);
}

char	*add_to_buffer(char *buffer, char *new_buffer)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(sizeof(char)
			* (ft_strlen(buffer) + ft_strlen(new_buffer) + 1));
	if (!result)
	{
		new_buffer = reset_str(new_buffer);
		return (reset_str(buffer));
	}
	i = -1;
	j = -1;
	while (buffer[++i])
		result[i] = buffer[i];
	while (new_buffer[++j])
		result[i + j] = new_buffer[j];
	result[i + j] = '\0';
	buffer = reset_str(buffer);
	return (result);
}
