/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:37:19 by mprofett          #+#    #+#             */
/*   Updated: 2022/10/25 09:37:20 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save_end_of_buffer(char *buffer, int end_of_line)
{
	char	*new_buffer;
	int		i;

	if (end_of_line == -1)
		return (reset_str(buffer));
	if (ft_strlen(buffer) == (end_of_line + 1))
		return (reset_str(buffer));
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - end_of_line) + 1);
	if (!new_buffer)
		return (reset_str(buffer));
	i = -1;
	while (buffer[++end_of_line])
		new_buffer[++i] = buffer[end_of_line];
	new_buffer[++i] = '\0';
	buffer = reset_str(buffer);
	return (new_buffer);
}

char	*get_current_line(char *buffer, int end_of_line)
{
	char	*line;
	int		i;

	if (end_of_line == -1)
		end_of_line = (ft_strlen(buffer) - 1);
	line = malloc(sizeof(char) * (end_of_line + 2));
	if (!line)
		return (reset_str(buffer));
	i = -1;
	while (++i <= end_of_line)
		line[i] = buffer[i];
	line[i] = '\0';
	return (line);
}

char	*read_until_next_line(char *buffer, const int fd)
{
	char	*new_buffer;
	int		check_result;

	new_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!new_buffer)
		return (reset_str(buffer));
	check_result = ft_strchr(buffer, '\n');
	while (buffer && check_result == -1)
	{
		check_result = read(fd, new_buffer, BUFFER_SIZE);
		if (check_result <= 0)
		{
			reset_str(new_buffer);
			if (buffer[0] == '\0' || check_result == -1)
				return (reset_str(buffer));
			return (buffer);
		}
		new_buffer[check_result] = '\0';
		check_result = ft_strchr(new_buffer, '\n');
		buffer = add_to_buffer(buffer, new_buffer);
	}
	reset_str(new_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer_tab[OPEN_MAX];
	char		*line;
	int			end_of_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE > SSIZE_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer_tab[fd])
	{
		buffer_tab[fd] = malloc(sizeof(char));
		if (!buffer_tab[fd])
			return (NULL);
		buffer_tab[fd][0] = '\0';
	}
	buffer_tab[fd] = read_until_next_line(buffer_tab[fd], fd);
	if (!buffer_tab[fd])
		return (NULL);
	end_of_line = ft_strchr(buffer_tab[fd], '\n');
	line = get_current_line(buffer_tab[fd], end_of_line);
	if (!line)
		return (NULL);
	buffer_tab[fd] = save_end_of_buffer(buffer_tab[fd], end_of_line);
	return (line);
}
