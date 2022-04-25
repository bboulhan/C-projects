/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:47:07 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/19 16:23:28 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*mallcpy(char *source, char *del);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(char *s, int c);
#endif
