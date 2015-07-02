/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 19:45:47 by maissa-b          #+#    #+#             */
/*   Updated: 2015/05/09 18:29:27 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/****************************** Fonctions Part_1 ******************************/

void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *s);

/****************************** Fonctions Part_2 ******************************/

size_t	ft_strlen(const char *s);
void	*ft_memset(void *mem, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char*	ft_strdup(const char *s1);

/******************************* Fonction Part_3 ******************************/

void	ft_cat(int fd);

/****************************** Fonctions Bonus *******************************/

void	ft_putspace(size_t len);
int		ft_isspace(int c);
char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n);
int		ft_isupper(int c);
int		ft_islower(int c);
char	*ft_strcpy(char *restrict dst, const char *restrict src);
char	*ft_strchr(const char *s, char c);
int		ft_strbcmp(const char *s1, const char *s2);
void	ft_puts_fd(char *s, int fd);

/*********************** Fonctions Tests Part_1 *******************************/

void	ft_putstr(char *str)
{
	int i = -1;

	while (str[++i])
	{
		write(1, &str[i], 1);
	}
}

void		test_ft_bzero(void)
{

	char *str1 = strdup("Les marins aiment le rhum");
	char *str2 = strdup("Les marins aiment le rhum");
	ft_putstr("bzero(\"");
	ft_putstr(str1);
	ft_putstr("\", 10) ->");
	ft_bzero(str1, 10);
	bzero(str2, 10);
	(memcmp(str1, str2, 10) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	str1 = strdup("Les marins aiment le rhum");
	str2 = strdup("Les marins aiment le rhum");
	ft_putstr("bzero(\"");
	ft_putstr(str1);
	ft_putstr("\", strlen(str1)) ->");
	int a = strlen(str1);
	ft_bzero(str1, strlen(str1));
	bzero(str2, strlen(str2));
	(memcmp(str1, str2, a) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	str1 = strdup("Les marins aiment le rhum");
	str2 = strdup("Les marins aiment le rhum");
	ft_putstr("bzero(\"");
	ft_putstr(str1);
	ft_putstr("\", 1) ->");
	ft_bzero(str1, 1);
	bzero(str2, 1);
	(memcmp(str1, str2, 1) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	str1 = strdup("Les marins aiment le rhum");
	str2 = strdup("Les marins aiment le rhum");
	ft_putstr("bzero(\"");
	ft_putstr(str1);
	ft_putstr("\", 0) ->");
	ft_bzero(str1, 0);
	bzero(str2, 0);
	(memcmp(str1, str2, 0) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");
}

void test_ft_strcat(void)
{
	char	*str1;
	char	*str2;


	str1 = (char *)malloc(sizeof(char) * 40);
	str2 = (char *)malloc(sizeof(char) * 40);
	ft_putstr("strcat(\"\", pasteque) -> ");
	ft_putstr("strcat : ");
	strcat(str2, "pasteque");
	ft_putstr(str2);
	ft_putstr(", ft_strcat: ");
	strcat(str1, "pasteque");
	ft_putstr(str1);
	(strcmp(str1, str2) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	ft_putstr("strcat(pasteque, \\\\\\) -> ");
	ft_putstr("strcat : ");
	strcat(str2, "\\\\\\");
	ft_putstr(str2);
	ft_putstr(", ft_strcat: ");
	strcat(str1, "\\\\\\");
	ft_putstr(str1);
	(strcmp(str1, str2) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	str1 = strdup("hello");
	str2 = strdup("hello");
	ft_putstr("strcat(hello, \" world\") -> ");
	ft_putstr("strcat : ");
	strcat(str2, " world");
	ft_putstr(str2);
	ft_putstr(", ft_strcat: ");
	strcat(str1, " world");
	ft_putstr(str1);
	(strcmp(str1, str2) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	ft_putstr("strcat(hello world, po\\0mme) -> ");
	ft_putstr("strcat : ");
	strcat(str2, "po\0mme");
	ft_putstr(str2);
	ft_putstr(", ft_strcat: ");
	strcat(str1, "po\0mme");
	ft_putstr(str1);
	(strcmp(str1, str2) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");

	ft_putstr("strcat(hello worldpo, \"\") -> ");
	ft_putstr("strcat : ");
	strcat(str2, "");
	ft_putstr(str2);
	ft_putstr(", ft_strcat: ");
	strcat(str1, "");
	ft_putstr(str1);
	(strcmp(str1, str2) == 0) ? ft_putstr("\033[32m OK \033[m") : ft_putstr("\033[31m FAIL \033[m");
	ft_putstr("\n");
}

void		test_ft_isalpha(void)
{
	int i = -1;
	int res;
	int ft_res;

	while (++i < 127)
	{
		res = isalpha(i);
		ft_res = ft_isalpha(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		printf("%d\n", i);
		ft_putstr("\033[m");
	}
	ft_putstr("\n");
}

void	test_ft_isdigit(void)
{
	int i = -1;
	int res;
	int ft_res;

	while (++i < 127)
	{
		res = isdigit(i);
		ft_res = ft_isdigit(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		printf("%d\n", i);
		ft_putstr("\033[m");
	}
	ft_putstr("\n");
}

void		test_ft_isalnum(void)
{
	int i = -1;
	int res;
	int ft_res;

	while (++i < 127)
	{
		res = isalnum(i);
		ft_res = ft_isalnum(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		printf("%d\n", i);
		ft_putstr("\033[m");
	}
	ft_putstr("\n");
}

void		test_ft_isascii(void)
{
	int i = -50;
	int res;
	int ft_res;

	while (++i < 200)
	{
		res = isascii(i);
		ft_res = ft_isascii(i);
		if (res != ft_res)
			break;
	}
	if (i == 200)
	{
		ft_putstr("\033[32mAll test OK \033[m");
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("\033[31mFAIL test ");
		printf("%d\n", i);
		ft_putstr("\033[m");
	}
}

void		test_ft_isprint(void)
{
	int i = -1;
	int res;
	int ft_res;

	while (++i < 127)
	{
		res = isprint(i);
		ft_res = ft_isprint(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
	{
		ft_putstr("\033[32mAll test OK \033[m");
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("\033[31mFAIL test ");
		printf("%d\n", i);
		ft_putstr("\033[m");
	}
}

void		test_ft_toupper(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += toupper(i);
		ft_res += ft_toupper(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		printf("%d\n", i);
		ft_putstr("\033[m");
	}
	ft_putstr("\n");
}

void	test_ft_tolower(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += tolower(i);
		ft_res += ft_tolower(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		printf("%d\n", i);
		ft_putstr("\033[m");
	}
}

void	test_ft_puts(void)
{
	char *str1 = "Bonjour";
	ft_putstr("puts: ");
	puts(str1);
	ft_putstr("ft_puts: ");
	ft_puts(str1);

	ft_putstr("puts: ");
	puts("ca roule ?");
	ft_putstr("ft_puts: ");
	ft_puts("ca roule ?");

	ft_putstr("puts: ");
	puts("");
	ft_putstr("ft_puts: ");
	ft_puts("");

	ft_putstr("puts: ");
	puts(NULL);
	ft_putstr("ft_puts: ");
	ft_puts(NULL);
}

/*********************** Fonctions Tests Part_2 *******************************/

void		test_ft_strlen(void)
{
	char str1[] = "Ici, la taille compte";
	char str2[] = "Oui mais on dit quelle ne compte pas";
	char str3[] = "Seulement les rageux disent ça\n\n\n\n";
	char str4[] = "Moi je ne suis\0 pourtant pas un rageu";
	char str5[] = "T'en a pas marre de parler solo?";
	char str6[] = "Un peu, on arrête là";
	char str7[] = "Ok!";
	char str8[] = "\0";

	(ft_strlen(str1) == strlen(str1)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("%s -> strlen: %zd, ft_strlen: %zd\n", str1, strlen(str1), ft_strlen(str1));

	(ft_strlen(str2) == strlen(str2)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("%s -> strlen: %zd, ft_strlen: %zd\n", str2, strlen(str2), ft_strlen(str2));

	(ft_strlen(str3) == strlen(str3)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("Seulement les rageux disent ca\\n\\n\\n\\n-> strlen: %zd, ft_strlen: %zd\n", strlen(str3), ft_strlen(str3));

	(ft_strlen(str4) == strlen(str4)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("%s -> strlen: %zd, ft_strlen: %zd\n", str4, strlen(str4), ft_strlen(str4));

	(ft_strlen(str5) == strlen(str5)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("%s -> strlen: %zd, ft_strlen: %zd\n", str5, strlen(str5), ft_strlen(str5));

	(ft_strlen(str6) == strlen(str6)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("%s -> strlen: %zd, ft_strlen: %zd\n", str6, strlen(str6), ft_strlen(str6));

	(ft_strlen(str7) == strlen(str7)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("%s -> strlen: %zd, ft_strlen: %zd\n", str7, strlen(str7), ft_strlen(str7));

	(ft_strlen(str8) == strlen(str8)) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("%s -> strlen: %zd, ft_strlen: %zd\n", str8, strlen(str8), ft_strlen(str8));
}

void		test_ft_memcpy(void)
{
	char *str1 = strdup("Coucou toi!");
	char *str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "aaaaaaaa", 0), memcpy(str2, "aaaaaaaa", 0), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"aaaaaaa\", 0) ->"); 
	ft_putstr(" ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "AAAAAAAA", 8), memcpy(str2, "AAAAAAAA", 8), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");	
	ft_putstr("memcpy(\"Coucou toi!\", \"AAAAAAAA\", 8) ->"); 
	ft_putstr("ft_mempy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "12345678", 8), memcpy(str2, "12345678", 8), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"12345678\", 8) ->"); 
	ft_putstr("ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "jIujIuH", 7), memcpy(str2, "jIujIuH", 7),11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"jIujIuH\", 7) ->"); 
	ft_putstr("ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "/>*<+|@-12345", 13), memcpy(str2, "/>*<+|@-12345", 13), 14)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"/>*<+|@-12345\", 13) ->"); 
	ft_putstr("ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "yoloswag", 15), memcpy(str2, "yoloswag", 15), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"yoloswag\", 15) ->"); 
	ft_putstr("ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memcpy(str1, "\0", strlen(str1)), memcpy(str2, "\0", strlen(str2)), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memcpy(\"Coucou toi!\", \"\\0\", strlen(str1)) ->"); 
	ft_putstr("ft_memcpy: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("memcpy: ");
	ft_putstr(str2);
	ft_putstr("\n");
}


void		test_ft_memset(void)
{

	char *str1 = strdup("Coucou toi!");
	char *str2 = strdup("Coucou toi!");
	((memcmp(ft_memset(str1, 'a', 4), memset(str2, 'a', 4), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memset(\"Coucou toi!\", \'a\', 4) -> "); 
	ft_putstr("memset: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("ft_memset: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memset(str1, 'A', 14), memset(str2, 'A', 14), 14)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");	
	ft_putstr("memset(\"Coucou toi!\", \'A\', 14) -> "); 
	ft_putstr("memset: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("ft_memset: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memset(str1, '1', strlen(str1)), memset(str2, '1', strlen(str2)), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memset(\"Coucou toi!\", \'1\', strlen(str1)) -> "); 
	ft_putstr("memset: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("ft_memset: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memset(str1, '!', 0), memset(str2, '!', 0),11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memset(\"Coucou toi!\", \'!\', 0) -> "); 
	ft_putstr("memset: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("ft_memset: ");
	ft_putstr(str2);
	ft_putstr("\n");

	str1 = strdup("Coucou toi!");
	str2 = strdup("Coucou toi!");
	((memcmp(ft_memset(str1, ' ', 4), memset(str2, ' ', 4), 11)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("memset(\"Coucou toi!\", \' \', 4) -> "); 
	ft_putstr("memset: ");
	ft_putstr(str1);
	ft_putstr(", ");
	ft_putstr("ft_memset: ");
	ft_putstr(str2);
	ft_putstr("\n");
}

void		test_ft_strdup(void)
{
	char *str1 = strdup("Ici, la taille compte.");
	char str2[] = "Oui mais on dit qu'elle ne compte pas";
	char str3[] = "Seulement les rageux disent ça";
	char str4[] = "Moi je ne suis \0 pourtant pas un rageu.";
	char str5[] = "T'en as pas marre de parler solo?";
	char str6[] = "Un peu, on arrête là.";
	char str7[] = "Ok!";

	(strcmp(ft_strdup(str1), strdup(str1)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str1);
	ft_putstr("\n");

	(strcmp(ft_strdup(str2), strdup(str2)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str2);
	ft_putstr("\n");

	(strcmp(ft_strdup(str3), strdup(str3)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str3);
	ft_putstr("\n");

	(strcmp(ft_strdup(str4), strdup(str4)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str4);
	ft_putstr("\n");

	(strcmp(ft_strdup(str5), strdup(str5)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str5);
	ft_putstr("\n");

	(strcmp(ft_strdup(str6), strdup(str6)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str6);
	ft_putstr("\n");

	(strcmp(ft_strdup(str7), strdup(str7)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("strdup : ");
	ft_putstr(str7);
	ft_putstr("\n");

}
/*********************** Fonctions Tests Part_3 *******************************/

int	test_ft_cat(void)
{
	int fd;

	ft_putstr("\n");


	if ((fd = open("main.c", O_RDONLY)) == (-1))
	{
		ft_putstr("ERROR !");
	}
	ft_cat(fd);
	return (0);
}

/************************ Fonctions Tests Bonus *******************************/

void		test_ft_isupper(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += isupper(i);
		ft_res += ft_isupper(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		printf("%d\n", i);
		ft_putstr("\033[m");
	}
}

void		test_ft_islower(void)
{
	int i = -1;
	int res = 0;
	int ft_res = 0;

	while (++i < 127)
	{
		res += islower(i);
		ft_res += ft_islower(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		printf("%d\n", i);
		ft_putstr("\033[m");
	}
}


void	test_ft_strchr(void)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = strdup("bonjour");
	str2 = strdup("bonjour");
	str3 = strchr(str1, 'b');
	str4 = ft_strchr(str2, 'b');
	(strcmp(str3, str4) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("bonjour");
	printf(", %c -> strchr: %s, ft_strchr: %s\n", 'b', str3, str4);

	str1 = strdup("bonjour");
	str2 = strdup("bonjour");
	str3 = strchr(str1, 'r');
	str4 = ft_strchr(str2, 'r');
	(strcmp(str3, str4) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("bonjour");
	printf(", %c -> strchr: %s, ft_strchr: %s\n", 'r', str3, str4);

	str1 = strdup("bonjour");
	str2 = strdup("bonjour");
	str3 = strchr(str1, 'a');
	str4 = ft_strchr(str2, 'a');
	if (!str3 && !str4)
		ft_putstr("\033[32mOK \033[m");
	else
		ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("bonjour");
	printf(", %c -> strchr: %s, ft_strchr: %s\n", 'a', str3, str4);

	str1 = strdup("bonjour");
	str2 = strdup("bonjour");
	str3 = strchr(str1, 'o');
	str4 = ft_strchr(str2, 'o');
	(strcmp(str3, str4) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("bonjour");
	printf(", %c -> strchr: %s, ft_strchr: %s\n", 'o', str3, str4);
}


void test_ft_strbcmp(void)
{
	char *s1;
	char *s2;
	int res;
	int ft_res;

	s1 = strdup("bonjour");
	s2 = strdup("salut");
	res = strcmp(s1, s2);
	ft_res = ft_strbcmp(s1, s2);
	(res/res == ft_res/ft_res) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(s1);
	ft_putstr(" / ");
	ft_putstr(s2);
	printf(" -> cmp: %d, ft_cmp: %d\n", res, ft_res);

	s1 = strdup("abcdd");
	s2 = strdup("abcd");
	res = strcmp(s1, s2);
	ft_res = ft_strbcmp(s1, s2);
	(res/res == ft_res/ft_res) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(s1);
	ft_putstr(" / ");
	ft_putstr(s2);
	printf(" -> cmp: %d, ft_cmp: %d\n", res, ft_res);

	s1 = strdup("bonjour");
	s2 = strdup("bonjour");
	res = strcmp(s1, s2);
	ft_res = ft_strbcmp(s1, s2);
	(res == ft_res) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(s1);
	ft_putstr(" / ");
	ft_putstr(s2);
	printf(" -> cmp: %d, ft_cmp: %d\n", res, ft_res);

	s1 = strdup("toto");
	s2 = strdup("TOTO");
	res = strcmp(s1, s2);
	ft_res = ft_strbcmp(s1, s2);
	(res/res == ft_res/ft_res) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(s1);
	ft_putstr(" / ");
	ft_putstr(s2);
	printf(" -> cmp: %d, ft_cmp: %d\n", res, ft_res);

	s1 = strdup("");
	s2 = strdup("1");
	res = strcmp(s1, s2);
	ft_res = ft_strbcmp(s1, s2);
	(res/res == ft_res/ft_res) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(s1);
	ft_putstr(" / ");
	ft_putstr(s2);
	printf(" -> cmp: %d, ft_cmp: %d\n", res, ft_res);

	s1 = strdup("");
	s2 = strdup("");
	res = strcmp(s1, s2);
	ft_res = ft_strbcmp(s1, s2);
	(res == ft_res) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(s1);
	ft_putstr(" / ");
	ft_putstr(s2);
	printf(" -> cmp: %d, ft_cmp: %d\n", res, ft_res);

	s1 = strdup("1");
	s2 = strdup("");
	res = strcmp(s1, s2);
	ft_res = ft_strbcmp(s1, s2);
	(res/res == ft_res/ft_res) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr(s1);
	ft_putstr(" / ");
	ft_putstr(s2);
	printf(" -> cmp: %d, ft_cmp: %d\n", res, ft_res);
}

void		test_ft_strcpy(void)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strcpy(str1, "coucou");
	str4 = ft_strcpy(str2, "coucou");
	((strcmp(str3, str4)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("COUCOU");
	ft_putstr(" / ");
	ft_putstr("coucou");
	printf(" -> strcpy: %s, ft_strcpy: %s", str3, str4);
	printf("\n");

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strcpy(str1, "hello");
	str4 = ft_strcpy(str2, "hello");
	((strcmp(str3, str4)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("COUCOU");
	ft_putstr(" / ");
	ft_putstr("hello");
	printf(" -> strcpy: %s, ft_strcpy: %s", str3, str4);
	printf("\n");

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strcpy(str1, "qwertyuiop");
	str4 = ft_strcpy(str2, "qwertyuiop");
	((strcmp(str3, str4)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("COUCOU");
	ft_putstr(" / ");
	ft_putstr("qwertyuiop");
	printf(" -> strcpy: %s, ft_strcpy: %s", str3, str4);
	printf("\n");

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strcpy(str1, "");
	str4 = ft_strcpy(str2, "");
	((strcmp(str3, str4)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	ft_putstr("COUCOU");
	ft_putstr(" / ");
	ft_putstr("\"\"");
	printf(" -> strcpy: %s, ft_strcpy: %s", str3, str4);
	printf("\n");
}

void		test_ft_strncpy(void)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strncpy(str1, "coucou", 10);
	str4 = ft_strncpy(str2, "coucou", 10);
	((memcmp(str3, str4, 10)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("strncpy(COUCOU, coucou, 10) -> strncpy: %s, ft_strncpy: %s\n", str3, str4);

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strncpy(str1, "hello", 10);
	str4 = ft_strncpy(str2, "hello", 10);
	((memcmp(str3, str4, 10)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("strncpy(COUCOU, hello, 10) -> strncpy: %s, ft_strncpy: %s\n", str3, str4);

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strncpy(str1, "hello", 2);
	str4 = ft_strncpy(str2, "hello", 2);
	((memcmp(str3, str4, 10)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("strncpy(COUCOU, hello, 2) -> strncpy: %s, ft_strncpy: %s\n", str3, str4);

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strncpy(str1, "qwertyuiop", 8);
	str4 = ft_strncpy(str2, "qwertyuiop", 8);
	((memcmp(str3, str4, 10)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("strncpy(COUCOU, qwertyuiop, 8) -> strncpy: %s, ft_strncpy: %s\n", str3, str4);

	str1 = strdup("COUCOU");
	str2 = strdup("COUCOU");
	str3 = strncpy(str1, "qwertyuiop", 0);
	str4 = ft_strncpy(str2, "qwertyuiop", 0);
	((memcmp(str3, str4, 10)) == 0) ? ft_putstr("\033[32mOK \033[m") : ft_putstr("\033[31mFAIL \033[m");
	printf("strncpy(COUCOU, qwertyuiop, 0) -> strncpy: %s, ft_strncpy: %s\n", str3, str4);
}

void test_ft_isspace(void)
{
	int i = -1;
	int res;
	int ft_res;

	while (++i < 127)
	{
		res = isspace(i);
		ft_res = ft_isspace(i);
		if (res != ft_res)
			break;
	}
	if (i == 127)
		ft_putstr("\033[32mAll test OK \033[m");
	else
	{
		ft_putstr("\033[31mFAIL test ");
		printf("%d\n", i);
		ft_putstr("\033[m");
	}
	ft_putstr("\n");
}

void test_ft_putspace(void)
{
	ft_putstr("1");
	ft_putspace(2);
	ft_putstr("333");
	ft_putspace(4);
	ft_putstr("55555|\n");
	ft_putspace(1);
	ft_putstr("22");
	ft_putspace(3);
	ft_putstr("4444");
	ft_putspace(5);
	ft_putstr("|\n");
}

void *ft_memalloc(size_t size);
void *ft_strnew(size_t size);

void test_ft_memalloc(void)
{
	char *s1;
	char s2[] = "\0\0\0\0\0";

	ft_putstr("ft_memalloc(5) ->");
	s1 = ft_memalloc(5);
	memcmp(s1, s2, 5) == 0 ? ft_putstr("\033[32m OK\n\033[m") : ft_putstr("\033[31m FAIL\n\033[m");
	ft_putstr("ft_memalloc(0) -> ");
	puts(ft_memalloc(0));
}

void test_ft_strnew(void)
{
	char *s1;
	char s2[] = "\0\0\0\0\0\0";

	ft_putstr("ft_strnew(5) ->");
	s1 = ft_strnew(5);
	memcmp(s1, s2, 6) == 0 ? ft_putstr("\033[32m OK\n\033[m") : ft_putstr("\033[31m FAIL\n\033[m");

	char *s3;
	char s4[] = "\0";
	ft_putstr("ft_strnew(0) ->");
	s3 = ft_strnew(0);
	memcmp(s3, s4, 1) == 0 ? ft_putstr("\033[32m OK\n\033[m") : ft_putstr("\033[31m FAIL\n\033[m");
}

void	test_ft_puts_fd(void)
{
	int fd;


	fd = open("test_puts_fd", O_WRONLY | O_CREAT | O_APPEND);

	ft_putstr("tests envoyes dans le fichier \"test_puts_fd\":\n");
	ft_putstr("Bonjour\n");
	ft_putstr("13\n");
	ft_putstr("hello world\n");
	ft_putstr("!@#$%^&*()\n");

	ft_puts_fd("Bonjour", fd);
	ft_puts_fd("13", fd);
	ft_puts_fd("hello world", fd);
	ft_puts_fd("!@#$%^&*()", fd);
	
	close(fd);
}
/****************************** Core test *************************************/

int main(void)
{
	ft_putstr("\033[33mPart_1:\n\033[m");

	ft_putstr("\nFT_BZERO:\n");
	test_ft_bzero();
	ft_putstr("\nFT_STRCAT:\n");
	test_ft_strcat();
	ft_putstr("\nFT_ISALPHA:\n");
	test_ft_isalpha();
	ft_putstr("\nFT_ISDIGIT:\n");
	test_ft_isdigit();
	ft_putstr("\nFT_ISALNUM:\n");
	test_ft_isalnum();
	ft_putstr("\nFT_SIASCII:\n");
	test_ft_isascii();
	ft_putstr("\nFT_ISPRINT:\n");
	test_ft_isprint();
	ft_putstr("\nFT_TOUPPER:\n");
	test_ft_toupper();
	ft_putstr("\nFT_TOLOWER:\n");
	test_ft_tolower();
	ft_putstr("\n\nFT_PUTS:\n");
	test_ft_puts();

	ft_putstr("\n\n\033[33mPart_2:\n\033[m");

	ft_putstr("\nFT_STRLEN:\n");
	test_ft_strlen();
	ft_putstr("\nFT_MEMCPY:\n");
	test_ft_memcpy();
	ft_putstr("\nFT_MEMSET:\n");
	test_ft_memset();
	ft_putstr("\nFT_STRDUP:\n");
	test_ft_strdup();

	ft_putstr("\n\033[33mPart_3:\n\033[m");

	ft_putstr("\nFT_CAT:\n");
//	test_ft_cat();

	ft_putstr("\n\033[33mPart Bonus:\n\033[m");

	ft_putstr("\nFT_ISUPPER:\n");
	test_ft_isupper();
	ft_putstr("\n\nFT_ISLOWER:\n");
	test_ft_islower();
	ft_putstr("\n\nFT_STRCHR:\n");
	test_ft_strchr();
	ft_putstr("\nFT_STRBCMP:\n");
	test_ft_strbcmp();
	ft_putstr("\nFT_STRCPY:\n");
	test_ft_strcpy();
	ft_putstr("\nFT_STRNCPY:\n");
	test_ft_strncpy();
	ft_putstr("\nFT_ISSPACE:\n");
	test_ft_isspace();
	ft_putstr("\nFT_PUTSPACE:\n");
	test_ft_putspace();
	ft_putstr("\nFT_MEMALLOC:\n");
	test_ft_memalloc();
	ft_putstr("\nFT_STRNEW:\n");
	test_ft_strnew();
	ft_putstr("\n\nFT_PUTS_FD:\n");
	test_ft_puts_fd();
}
