/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpme_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:27:58 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/07 23:16:23 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static long int	dgts(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			counts;
	char		*p;
	long int	num;

	counts = dgts(n);
	num = n;
	p = malloc(counts + 1);
	if (!p)
		return (NULL);
	p[counts] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		num = -num;
	}
	while (counts > 0 && num != 0)
	{
		p[counts - 1] = num % 10 + '0';
		num = num / 10;
		counts--;
	}
	if (n == 0)
		p[0] = '0';
	return (p);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb <= 9)
		ft_putchar(nb + 48);
}

void	ft_putstr(char *s, int f)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (f, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
