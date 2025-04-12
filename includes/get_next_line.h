/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:00:17 by anass             #+#    #+#             */
/*   Updated: 2025/03/25 15:00:22 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strlen(char *str);
char	*ft_strljoin(char *s1, char *s2, int size);
int		ft_new_line_check(char *str);
char	*ft_init(char *str);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);

#endif