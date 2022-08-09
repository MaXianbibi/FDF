/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:50:08 by jmorneau          #+#    #+#             */
/*   Updated: 2022/05/25 16:03:46 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>

# define BUFFER_SIZE 5

int		ft_atoi(const char *str);
void	ft_bzero(void *s, unsigned long n);
void	*ft_calloc(size_t nitems, size_t size);
int		ft_isalnum(int arg);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int arg);
int		ft_isprint(int arg);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, unsigned long n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
void	*ft_memset(void *str, int c, unsigned long n);
int		ft_strlen(char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_strlen(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *s, int c);
void	ft_free_chartable(char **table);
int		ft_chartable_linecount(char **table);

// printf
int		ft_printf(const char *fmt, ...);
int		ft_printf_string(const char *str);
int		ft_printf_nbr(int n);
int		ft_printf_ptr(unsigned long ptr);
int		ft_print_unsigned(unsigned int n);
int		ft_printf_hex(unsigned int num, const char format);
int		ft_print_char(const char c);
// gnl
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(char *str);
int		ft_strchr_index(const char *str, int c);

#endif