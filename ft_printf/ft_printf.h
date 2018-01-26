/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:33:26 by djoly             #+#    #+#             */
/*   Updated: 2016/03/10 15:44:02 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>
# include <string.h>
# include <wchar.h>
# include <limits.h>
# define TOKEN "sSpdDioOuUxXcC"
# define FLAGS "#0-+ hljz."
# define HEXA "0123456789abcdef"
# define HEXA2 "0123456789ABCDEF"
# define FONCT env->fonct
# define FORMAT env->format
# define IFOR env->ifor
# define ITOK   env->itok
# define ARG    env->arg
# define AP     env->ap
# define NBR    env->nbr
# define NBRPREC	env->nbr_precision
# define FNDFLAGS  env->fndflags
# define RET    env->ret
# define ARGLEN env->arglen
# define NBNEG	env->nbneg

typedef struct s_env	t_env;

typedef struct			s_tab
{
	char				c;
	int					(*fonction)(t_env *env);
}						t_tab;

struct					s_env
{
	int					(*fonction[14])(t_env *env);
	t_tab				*fonct;
	const char			*format;
	int					ifor;
	int					itok;
	void				*arg;
	int					putneg;
	va_list				ap;
	int					error;
	int					nbr;
	int					nbr_precision;
	char				fndflags[10];
	int					ret;
	int					arglen;
	long long int		nbneg;
};

void					before_nbrd_prec(t_env *env);
void					fonct_error(t_env *env);
int						fonct_s(t_env *env);
int						fonct_ss(t_env *env);
int						fonct_p(t_env *env);
int						fonct_d(t_env *env);
int						fonct_dd(t_env *env);
int						fonct_i(t_env *env);
int						fonct_o(t_env *env);
int						fonct_oo(t_env *env);
int						fonct_u(t_env *env);
int						fonct_uu(t_env *env);
int						fonct_x(t_env *env);
int						fonct_xx(t_env *env);
int						fonct_c(t_env *env);
int						fonct_cc(t_env *env);
int						ft_arglendd(t_env *env);
int						ft_arglens(t_env *env);
int						ft_arglendd(t_env *env);
int						ft_argleno(t_env *env);
int						ft_atoi(const char *str);
int						ft_check_token(t_env *env);
int						ft_check_flags(t_env *env);
int						ft_check_nbr(t_env *env);
void					ft_init(t_tab *t_token);
t_tab					*ft_init_list();
void					ft_init_env(t_env *env);
int						ft_nbrlen(int nb);
int						ft_nbrlenh(unsigned short int nb);
int						ft_nbrlenl(long unsigned int nb);
int						ft_nbrlenj(uintmax_t nb);
int						ft_nbrlenll(long long unsigned int nb);
int						ft_nbrlenoo(unsigned long int nb);
int						ft_printf(const char *format, ...);
int						ft_putchar(char c);
int						ft_putnbr(long long int nbr);
int						ft_putnbr2(long long unsigned int nbr);
int						ft_putoo(unsigned long int nbr);
int						ft_putstr2(const char *str, int len);
int						ft_putstr(const char *str);
int						ft_putspace(int nbr);
void					ft_putzero(t_env *env);
int						ft_putzero2(int nbr);
int						ft_put_w_char(wchar_t c);
int						ft_put_wn_str(wchar_t *str, int n);
int						ft_put_w_str(wchar_t *str);
void					ft_re_init_env(t_env *env);
size_t					ft_strlen(const char *str);
char					*ft_strchr(const char *s, int c);
int						ft_unbrlen(unsigned int nb);
int						ft_which_putnbr(t_env *env);
void					ft_which_putnbrd(t_env *env);
void					ft_which_putnbrnegd(t_env *env);
void					ft_which_putnbrnegdd(t_env *env);
int						ft_which_putoctal(t_env *env);
int						ft_wcharlen(wchar_t c);
void					ft_which_putnbrdd(t_env *env);
int						ft_wstrlen(wchar_t *str);
int						hexa_lenp(t_env *env);
int						hexa_lenx(t_env *env);
void					is_neg(t_env *env);
void					print_percent(t_env *env);
void					print_hexap(t_env *env);
void					print_hexax(t_env *env);
void					run_format(t_env *env);
void					statut(t_env *env);
int						write_wc(unsigned char c);

#endif
