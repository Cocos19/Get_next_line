/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:36:53 by mprofett          #+#    #+#             */
/*   Updated: 2022/10/25 09:36:54 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_until_next_line(char *buffer, const int fd);
char	*get_current_line(char *buffer, int end_of_line);
char	*save_end_of_buffer(char *buffer, int end_of_line);
char	*add_to_buffer(char *buffer, char *new_read);
char	*reset_str(char *buffer);
int		ft_strchr(const char *buffer, int c);
int		ft_strlen(const char *s);

#endif
