/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:07:13 by dnishsha          #+#    #+#             */
/*   Updated: 2024/08/24 13:07:17 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define ERROR_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

void	print_capital_str(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		std::cout << (char)(toupper(str[i]));
		i ++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << ERROR_MSG << std::endl;
	else
	{
		argv ++;
		while (*argv)
		{
			print_capital_str(*argv);
			argv ++;
		}
		std::cout << std::endl;
	}
	return (0);
}
