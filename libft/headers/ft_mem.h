/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:19:28 by lfrederi          #+#    #+#             */
/*   Updated: 2022/01/07 14:24:45 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <stddef.h>

/*
 * Writes n bytes of value c (converted to an usigned char)
 * to the s (pointer start).
 * Return: s
 */
void	*ft_memset(void *s, int c, size_t n);

/*
 * Writes n bytes of 0 to the s (start pointer).
 * If (n == 0) function does nothing.
 * Return: nothing
 */
void	ft_bzero(void *s, size_t n);

/*
 * Copies n bytes from src to dst.
 * Return: dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/*
 * Copies n bytes from src to dest and manage if dest and src overlap.
 * Retun: dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/*
 * Locates the first occurrence of c (converted to an unsigned char).
 * Pointer start c and n bytes to search.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/*
 * Compares bytes between s1 and s2 on n bytes (unsigned char values).
 * Return: 0 if none difference or difference between first difference
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
 * Contiguously allocates enough space for count objects 
 * that are size bytes of memory each and fill all bytes of value zero.
 * Return a pointer to the allocated memory or NULL if allocating failed.
 */
void	*ft_calloc(size_t count, size_t size);

#endif
