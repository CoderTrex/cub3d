/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:04:01 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/18 15:26:35 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	print_error(char *str)
{
	printf("Error\n%s\n", str);
	return (-1);
}

void	free_all()
{
	// free all malloced memory
}

void	exit_with_code(int code, char *str)
{
	printf("Error\n%s\n", str);
	free_all();
	exit(code);
}
