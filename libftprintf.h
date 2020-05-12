/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:45:09 by dmoreira          #+#    #+#             */
/*   Updated: 2020/04/25 21:04:47 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef	struct		s_param
{
	char			perc;
	int				left;
	int				width;
	int				wdha;
	int				wdh_op;
	int				zero;
	int				qtd_char;
	int				prec;
	int				pcna;
	int				pcn_op;
	int				ast;
	char			type;
	char			*result;
}					t_param;

int					cont_flags(const char *pnt);
int					ft_printf(const char *pnt, ...);
int					ft_newparam(int size);
void				fill_struct(const char *ptr, int size, int chars);
int					ver_flag_set(const char *ptr, int pos);
int					ver_flag_ast(const char *ptr, int pos);
int					ver_flag(const char *ptr);
int					while_ast(const char *ptr, int pos, char let);
int					setting_struct(const char *ptr, int pos);
void				value_asterisk(const char *ptr, va_list ap, int num);
int					ver_char(char let);
void				options_struct(const char *ptr, int pos, int mv);
void				put_di(int pos);
void				case1_di(char chr, int wdh, int str, int pos);
void				case2_di(char chr, int wdh, int prec, int pos);
void				case3_di(char chr, int wdh, int pos);
int					count_di(int pos);
void				put_percent(int pos);
void				case1_percent(int wdh, int pos);
int					count_percent(int pos);
void				put_char(int pos);
void				case1_char(int wdh, int pos);
int					count_pchar(int pos);
char				*ft_chrdup(const char s1);
int					count_chars(const char *pnt, int max_pos);
void				put_string(int pos);
void				case1_string(int wdh, int prec, int str, int pos);
int					count_string(int pos);
void				put_uint(int pos);
void				case1_uint(int whd, int str, int pos);
void				case2_uint(int wdh, int prec, int str, int pos);
int					count_uint(int pos);
char				*ft_uitoa(unsigned int n);
char				*change_low16(unsigned int num);
char				alphanum_low16(unsigned int n);
char				*change_upper16(unsigned int num);
char				*put_p(size_t num);
char				*aloc_p(size_t n);
char				*filter_valist(va_list ap, char cha, int pos);
void				final_reading(const char *ptr);
int					zero_ast(const char *ptr);
void				case3_p(int wdh, int pos);
int					if_ast(int rec, char chr, int pos);
int					ver_ast(char chr, int rec, const char *p);
int					ver_option_struct(char chr, const char *p, int pos);
void				free_struct(int num);
#endif
