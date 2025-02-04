/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:11:02 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/01/30 01:09:11 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	normal_test(void)
{
	int i = 0;
	int original_tolower;
	int libft_tolower;
	int ok = 0;
	int iregular_ok = 0;
	int ko = 0;
	
	while (i < 256)
	{
		original_tolower = tolower(i);
		libft_tolower = ft_tolower(i);
		if (original_tolower == libft_tolower)
			ok++;
		else if ((original_tolower && libft_tolower) || (!original_tolower && !libft_tolower))
			iregular_ok++;
		else
			ko++;
		i++;
	}
	if (ko > 0)
		printf("%s[ko]%s (%d/512)\n", COLOR_RED, COLOR_RESET, (ok * 2 + iregular_ok));
	else if (iregular_ok > 0)
		printf("%s[ok]%s (%d/512)\n", COLOR_YELLOW, COLOR_RESET, (ok * 2 + iregular_ok));
	else
		printf("%s[ok]%s (%d/512)\n", COLOR_GREEN, COLOR_RESET, (ok * 2 + iregular_ok));
	return (ko * 2 + iregular_ok);
}

static void	detail_test(void)
{
	int i = 0;
	int original_tolower;
	int libft_tolower;
	
	while (i < 256)
	{
		original_tolower = tolower(i);
		libft_tolower = ft_tolower(i);
		if (tolower(i))
		{
			if (original_tolower == libft_tolower)
				printf("char: (%c)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_tolower && libft_tolower) || (!original_tolower && !libft_tolower))
				printf("char: (%c)%s[ok]%s[tolower: %d][ft_tolower: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_tolower, libft_tolower);
			else
				printf("char: (%c)%s[ko]%s[tolower: %d][ft_tolower: %d]\n", i, COLOR_RED, COLOR_RESET, original_tolower, libft_tolower);
		}
		else
		{
			if (original_tolower == libft_tolower)
				printf("char: (%d)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_tolower && libft_tolower) || (!original_tolower && !libft_tolower))
				printf("char: (%d)%s[ok]%s[tolower: %d][ft_tolower: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_tolower, libft_tolower);
			else
				printf("char: (%d)%s[ko]%s[tolower: %d][ft_tolower: %d]\n", i, COLOR_RED, COLOR_RESET, original_tolower, libft_tolower);
		}
		i++;
	}
}

static void test_irregular_cases(void)
{
	int i = 0;
	int original_tolower;
	int libft_tolower;
	
	while (i < 256)
	{
		original_tolower = tolower(i);
		libft_tolower = ft_tolower(i);
		if (tolower(i))
		{
			if (!(original_tolower == libft_tolower) && ((original_tolower && libft_tolower) || (!original_tolower && !libft_tolower)))
				printf("char: (%c)%s[ok]%s[tolower: %d][ft_tolower: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_tolower, libft_tolower);
		}
		else
		{
			if (!(original_tolower == libft_tolower) && ((original_tolower && libft_tolower) || (!original_tolower && !libft_tolower)))
				printf("char: (%d)%s[ok]%s[tolower: %d][ft_tolower: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_tolower, libft_tolower);
		}
		i++;
	}
}

static void test_error_cases(void)
{
	int i = 0;
	int original_tolower;
	int libft_tolower;
	
	while (i < 256)
	{
		original_tolower = tolower(i);
		libft_tolower = ft_tolower(i);
		if (tolower(i))
		{
			if ((!original_tolower && libft_tolower) || (original_tolower && !libft_tolower))
				printf("char: (%c)%s[ko]%s[tolower: %d][ft_tolower: %d]\n", i, COLOR_RED, COLOR_RESET, original_tolower, libft_tolower);
		}
		else
		{
			if ((!original_tolower && libft_tolower) || (original_tolower && !libft_tolower))
				printf("char: (%d)%s[ko]%s[tolower: %d][ft_tolower: %d]\n", i, COLOR_RED, COLOR_RESET, original_tolower, libft_tolower);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int	result;
	int i = 1;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_tolower:", COLOR_RESET);
	result = normal_test();
	if (argc > 1)
	{
		while (i < argc)
		{
			if ((!strcmp(argv[i], "-d") || !strcmp(argv[i], "--detail")) && result < 512)
				detail_test();
			if ((!strcmp(argv[i], "-i") || !strcmp(argv[i], "--irregular")) && result < 512)
				test_irregular_cases();
			if ((!strcmp(argv[i], "-e") || !strcmp(argv[i], "--error")) && result < 512)
				test_error_cases();
			i++;
		}
	}
	return (0);
}
