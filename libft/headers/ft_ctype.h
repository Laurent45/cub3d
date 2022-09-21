/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:53:20 by lfrederi          #+#    #+#             */
/*   Updated: 2022/01/07 14:21:03 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

/*
 * Check if c is an alphabetic character (upper and lower case)
 * Return: false (0) / true (non-negative)
 */
int		ft_isalpha(int c);

/*
 * Check if c is a decimal-digit character 
 * Return: false (0) / true (non-negative)
 */
int		ft_isdigit(int c);

/*
 * Check if c is an alphanumeric character 
 * Return: false (0) / true (non-negative)
 */
int		ft_isalnum(int c);

/*
 * Check if c is an ASCII character 
 * Return: false (0) / true (non-negative)
 */
int		ft_isascii(int c);

/*
 * Check if c is a printing character (' ' to '~') 
 * Return: false (0) / true (non-negative)
 */
int		ft_isprint(int c);
#endif
