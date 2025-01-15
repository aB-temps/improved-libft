/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_improved.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:03:41 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/14 16:18:53 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_IMPROVED_H
# define LIB_IMPROVED_H

// Libraries ============================================================
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
// ======================================================================

// Var ==================================================================
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif
// ======================================================================

// Structures ===========================================================
// linked list struct ---------------------------------------------------
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
// get_next_line struct -------------------------------------------------
typedef struct s_buff
{
	char			*full_buff;
	char			*residual;
	char			*valid_line;
	int				read_value;
}					t_buff;
// ======================================================================
// Print something ======================================================
int					ft_printf(int fd, const char *str,
						...) __attribute__((format(printf, 2, 3)));
void				ft_handle_datatype(char c, va_list *cursor, ssize_t *length,
						int fd);
void				ft_putaddr_fd(void *ptr, ssize_t *len, int fd);
void				ft_putchar_fd(char c, ssize_t *len, int fd);
void				ft_putstr_fd(char *s, ssize_t *len, int fd);
void				ft_putnbr_fd(long long n, ssize_t *len, int fd);
void				ft_putnbr_base_fd(unsigned long int nbr, char c,
						ssize_t *len, int fd);
// =======================================================================

// Read a file ===========================================================
char				*get_next_line(int fd);
void				*ft_parse_line(int fd, t_buff *data);
void				*ft_extract_line(t_buff *data);
void				ft_init_struct(t_buff *data, char *residual);
void				*ft_clear_struct(t_buff *data);
// =======================================================================

// Utils =================================================================
// Char & String  --------------------------------------------------------
size_t				ft_strlen(const char *s);
int					ft_count_words(char const *s, char c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				**ft_split(char const *s, char c);
char				*ft_stradd(char *s1, char *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strndup(char *s, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(const char *s, unsigned int start, size_t len);
// Linked List  ----------------------------------------------------------
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
// Memory ----------------------------------------------------------------
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_freestr(char *s);
void				*ft_freestr_tab(char **nstrs);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
// Conversion & Int management -------------------------------------------
int					ft_uintlen(unsigned int n);
int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
// =======================================================================

#endif