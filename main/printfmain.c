/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:19:28 by xgilbert          #+#    #+#             */
/*   Updated: 2018/07/11 16:28:54 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

int		main(int argc, char **argv)
{
	wchar_t		str[4];
	int			i;
	int			r;
	char		*locale;

	locale = setlocale(LC_ALL, "");
//	ft_putnbr(MB_CUR_MAX);
	if (argc < 1)
	{
		ft_putstr("pas assez d'arguments");
		return (0);
	}
	if (argc > 1)
		printf("%s\n", argv[1]);
	i = 0;
	r = 0;
	str[0] = 945;
	str[1] = 946;
	str[2] = 947;
	str[3] = '\0';

	ft_putstr("√");
	ft_printf("ft_printf : %lc\n", 254);
	printf("___printf : %lc\n", 254);
	i = ft_printf("ft_printf : %-+10.5d\n", 4242);
	r = printf("___printf : %-+10.5d\n", 4242);
	ft_printf("valeur retour ft_printf/printf :%d/%d\n", i, r);
	i = ft_printf("ft_printf : √\n");
	r = printf("___printf : √\n");
	i = ft_printf("ft_printf : %d\n", 0xd800);
	r = printf("___printf : %d\n", 0xd800);
	i = ft_printf("ft_printf : %d\n", 0xdb02);
	r = printf("___printf : %d\n", 0xdb02);
	i = ft_printf("ft_printf : %d\n", 0xdfff);
	r = printf("___printf : %d\n", 0xdfff);
	i = ft_printf("ft_printf : %d\n", 0x10FFFF);
	r = printf("___printf : %d\n", 0x10FFFF);
	i = ft_printf("ft_printf : un caractere special %C\n", 945);
	r = printf("___printf : un caractere special %C\n", 945);
	i = ft_printf("ft_printf : une chaine speciale %S\n", str);
	r = printf("___printf : une chaine speciale %S\n", str);
	i = ft_printf("ft_printf : before %d after\n", 42);
	r = printf("___printf : before %d after\n", 42);
	i = ft_printf("ft_printf : test % 20.12ld et %+05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
	r = printf("___printf : test % 20.12ld et %+05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
	i = ft_printf("ft_printf : 42%15.56i42!\n", -1673699724);
	r = printf("___printf : 42%15.56i42!\n", -1673699724);
	r = ft_printf("___printf : hello ca%----4c va %10c%-c ??\n", '\0', (char)564, 0);
	i = printf("___printf : hello ca%----4c va %10c%-c ??\n", '\0', (char)564, 0);
	r = ft_printf("ft_printf : %0+5d\n", 42);
	i = printf("___printf : %0+5d\n", 42);
	r = ft_printf("ft_printf : %s\n", NULL);
	i = printf("___printf : %s\n", NULL);
	r = ft_printf("ft_printf : %0024hho et%#1.2o %0012.O\n", (unsigned char)12, 0, 123654789);
	i = printf("___printf : %0024hho et%#1.2o %0012.O\n", (unsigned char)12, 0, 123654789);
	r = ft_printf("ft_printf : %-+-12.7D t %0 4i %04.2% et\n", 125, 124);
	i = printf("___printf : %-+-12.7D t %0 4i %04.2% et\n", 125, 124);
	r = ft_printf("ft_printf : %.i\n", 44);
	i = printf("___printf : %.i\n", 44);
	r = ft_printf("ft_printf : %+12.5d\n", 140);
	i = printf("___printf : %+12.5d\n", 140);
	r = ft_printf("ft_printf : %.2s is a string\n", "");
	i = printf("___printf : %.2s is a string\n", "");
	r = ft_printf("ft_printf : %-c ??\n", 0);
	i = printf("___printf : %-c ??\n", 0);
	r = ft_printf("ft_printf : t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);
	i = printf("___printf : t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);
	r = ft_printf("ft_printf : %.0X\n", 0xaabbcc);
	i = printf("___printf : %.0X\n", 0xaabbcc);
	r = ft_printf("ft_printf : %.x\n", 12);
	i = printf("___printf : %.x\n", 12);
	r = ft_printf("ft_printf : %#X\n", 0xff7744);
	i = printf("___printf : %#X\n", 0xff7744);
	r = ft_printf("ft_printf : % 20.12ld et % 05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
	i = printf("___printf : % 20.12ld et % 05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
	r = ft_printf("ft_printf : %08i\n", -71);
	i = printf("___printf : %08i\n", -71);
	r = ft_printf("ft_printf : coco et %-#-#--2O titi%#013o\n", 12, -874);
	i = printf("___printf : coco et %-#-#--2O titi%#013o\n", 12, -874);
	r = ft_printf("ft_printf : toto %###.0o%#.O\n", 0, 0);
	i = printf("___printf : toto %###.0o%#.O\n", 0, 0);
	r = ft_printf("ft_printf : %#-8.3o titi\n", 0);
	i = printf("___printf : %#-8.3o titi\n", 0);
	r = ft_printf("ft_printf : test%#.4o\n", 012);
	i = printf("___printf : test%#.4o\n", 012);
	r = ft_printf("ft_printf : %-d\n", 79);
	i = printf("___printf : %-d\n", 79);
	r = ft_printf("ft_printf : toto et %00009U%-2lu mimi et titi%--14u\n", 0, (unsigned long)14, 200);
	i = printf("___printf : toto et %00009U%-2lu mimi et titi%--14u\n", 0, (unsigned long)14, 200);
	r = ft_printf("ft_printf : %.u\n", 0);
	i = printf("___printf : %.u\n", 0);
	r = ft_printf("ft_printf : %.10u\n", 21);
	i = printf("___printf : %.10u\n", 21);
	r = ft_printf("ft_printf : toto%.0d et %+.i et  %   .0D !!!\n", 0, 0, 0);
	i = printf("___printf : toto%.0d et %+.i et  %   .0D !!!\n", 0, 0, 0);
	r = ft_printf("ft_printf : #.x #.x : %.x %.x\n", 0, 0);
	i = printf("___printf : #.x #.x : %.x %.x\n", 0, 0);
	r = ft_printf("ft_printf : #x de 0 : %#x\n", 0);
	i = printf("___printf : #x de 0 : %#x\n", 0);
	r = ft_printf("ft_printf : %%\n");
	i = printf("___printf : %%\n");
	r = ft_printf("ft_printf : %#08x\n", 42);
	i = printf("___printf : %#08x\n", 42);
	r = ft_printf("ft_printf : ceci est un %s ducon\n", "test");
	i = printf("___printf : ceci est un %s ducon\n", "test");
	r = ft_printf("ft_printf : %lX\n", 12300000000);
	i = printf("___printf : %lX\n", 12300000000);
	r = ft_printf("ft_printf : %010.5i blablabla\n", 42);
	i = printf("___printf : %010.5i blablabla\n", 42);
	r = ft_printf("ft_printf : %.5s a la con\n", "une chaine");
	i = printf("___printf : %.5s a la con\n", "une chaine");
	r = ft_printf("ft_printf : une adresse %p\n", &str[0]);
	i = printf("___printf : une adresse %p\n", &str[0]);
	r = ft_printf("ft_printf : un decimal d %ld et i %li\n", 16000000000, 17000000000);
	i = printf("___printf : un decimal d %ld et i %li\n", 16000000000, 17000000000);
	r = ft_printf("ft_printf : un long decimal %D\n", 16);
	i = printf("___printf : un long decimal %D\n", 16);
	r = ft_printf("ft_printf : un octal %#o\n", 10);
	i = printf("___printf : un octal %#o\n", 10);
	r = ft_printf("ft_printf : un long octal %O\n", 10);
	i = printf("___printf : un long octal %O\n", 10);
	r = ft_printf("ft_printf : un unsigned int %u\n", -2147483000);
	i = printf("___printf : un unsigned int %u\n", -2147483000);
	r = ft_printf("ft_printf : un long unsigned int %U\n", 2147483);
	i = printf("___printf : un long unsigned int %U\n", 2147483);
	r = ft_printf("ft_printf : un hexadecimal %x\n", 30);
	i = printf("___printf : un hexadecimal %x\n", 30);
	r = ft_printf("ft_printf : un HEXADECIMAL %X\n", 30);
	i = printf("___printf : un HEXADECIMAL %X\n", 30);
	r = ft_printf("ft_printf : un caractere : %c\n", 'c');
	i = printf("___printf : un caractere : %c\n", 'c');
	r = ft_printf("ft_printf : fake test %r\n", 800);
	ft_printf("fin du programme\n");
	return (0);
}
