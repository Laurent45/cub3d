/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:37:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/08/20 11:20:08 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

/*
 * See man (strlcpy)
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*
 * See man (strlcat)
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/*
 * Set c to upper if lower.
 * Return: c set.
 */
int		ft_toupper(int c);

/*
 * Set c to lower if upper.
 * Return: c set.
 */
int		ft_tolower(int c);

/*
 * Get the size of s.
 * Return: size of s.
 */
size_t	ft_strlen(const char *s);

/*
 * Locates the first occurrence of c (char) in the string pointed to by s.
 * The '\0' is considered to be part of the string; therefore if c is `\0',
 * the functions locate the terminating `\0'.
 * Return: locate of first occurence or NULL.
 */
char	*ft_strchr(const char *s, int c);

/*
 * Locates the last occurrence of c (char) in the string pointed to by s.
 * The '\0' is considered to be part of the string; therefore if c is `\0',
 * the functions locate the terminating `\0'.
 * Return: locate of last occurence or NULL.
 */
char	*ft_strrchr(const char *s, int c);

/*
 * See man (strcmp)
 */
int		ft_strcmp(const char *s1, const char *s2);

/*
 * See man (strncmp)
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
 * Locates the first occurrence of the null-terminated little in the big,
 * where not more than len characters are searched.
 * Characters that appear after a `\0' character are not searched.
 * Return: Locate if find or NULL.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/*
 * Converts the initial portion of the string pointed to by str
 * to int representation.
 * Return: result of conversion.
 */
int		ft_atoi(const char *str);

/*
 * Converts the initial portion of the string pointed to by str
 * to long representation.
 * Return: result of conversion.
 */
long	ft_atol(const char *str);

/*
 * Allocates sufficient memory for a copy of the string s1, does the copy.
 * Returns: pointer to duplicate.
 */
char	*ft_strdup(const char *s1);

/*
 * Allocates len memory and copy len bytes to start.
 * Return: Pointer or NULL
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);
void	ft_clear_split(char **split);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
#endif
