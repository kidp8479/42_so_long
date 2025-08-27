/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:30:48 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/25 00:36:34 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/* GNL utils */
size_t	ft_strlen_gnl(const char *str);
char	*ft_strdup_gnl(const char *str);
bool	ft_strchr_gnl(char	*str, char c);
void	ft_strcpy_gnl(char *dest, const char *src, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);

/* GNL main */
char	*extract_line(char *rest);
char	*update_rest(char *rest);
char	*ft_read_until_newline(int fd, char *rest);
char	*get_next_line(int fd);

#endif
