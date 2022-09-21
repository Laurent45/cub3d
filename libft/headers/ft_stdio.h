/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:54:03 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/06 11:45:15 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stddef.h>
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/******************************************************************************
 * Get next line.
 *****************************************************************************/
# define FD_MAX 1024
# define BUFFER_SIZE 1024

typedef struct s_buffd
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
}	t_buffd;

char	*get_next_line(int fd);
size_t	ft_sizetocpy(char *buf);
size_t	ft_strlen_gnl(char *buf);
void	ft_strlcat_gnl(char *dest, char *src, size_t lencopy);
void	ft_managebuffer(char *buf, size_t lenbuffer, size_t lencopy);
char	*ft_createline(int fd, char *curr);
int		ft_isnewline(char *str);
char	*ft_getbuffer(t_buffd *buffd, int fd);

/******************************************************************************
 * Printf
 *****************************************************************************/
int		ft_printf(const char *s, ...);

typedef struct s_args
{
	char	format;
	int		sharp_flag;
	int		sign_flag;
	int		blank_flag;
	int		zero_flag;
	int		digit_padding;
	int		minus_flag;
	int		dot_flag;
}	t_args;

typedef struct s_putflag
{
	char	flag;
	int		(*f_specifer)(va_list *ap, t_args *arg);	
}	t_putflag;

// ft_print_flag.c
int		ft_print_x(va_list *ap, t_args *arg);
int		ft_print_xx(va_list *ap, t_args *arg);
int		ft_print_u(va_list *ap, t_args *arg);
int		ft_print_p(va_list *ap, t_args *arg);
int		ft_print_di(va_list *ap, t_args *arg);
int		ft_print_c(va_list *ap, t_args *arg);
int		ft_print_percent(t_args *args);
int		ft_print_s(va_list *ap, t_args *arg);

//ft_putnbr.c ft_putstr.c
void	ft_putnbr_x(unsigned int nbr, int upper);
void	ft_putnbr_u(unsigned int nbr);
void	ft_putnbr_lux(unsigned long p);
void	ft_putnbr_d(int nbr);
int		ft_putstr(const char *s, int size);
int		ft_putchar(char c);
int		ft_putzero(int n);
int		ft_putblank(int n);
int		ft_strlen_pf(const char *s);

//ft_utils.c
void	ft_fill_array(t_putflag flags[9]);
void	ft_init_t_args(t_args *arg);
int		ft_countdigit_p(unsigned long nbr);
int		ft_countdigit_ux(unsigned int nbr, int lenbase);
int		ft_countdigit_d(int nbr);

int		ft_padding_blank(t_args *arg, long n, int size);
int		ft_left_adjustment(t_args *arg, int len);
int		ft_putzero_dotflag(t_args *arg, int len);
int		ft_putzero_zeroflag(t_args *arg, int len);
void	ft_put_sharpflag(t_args *arg, unsigned int n, int upper);

int		ft_getindex(t_putflag *flags, char c);
int		ft_isformat(char c);
int		ft_digit(char c);
int		ft_isarguments(char c);

#endif
