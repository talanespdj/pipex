/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:11:44 by tespandj          #+#    #+#             */
/*   Updated: 2024/06/03 17:11:45 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

t_parse	piparse(char **argv)
{
	t_parse	info;

	info.first_file = argv[1];
	info.first_cmd = argv[2];
	info.sec_file = argv[3];
	info.sec_cmd = argv[4];
	return (info);
}

void	print_info(t_parse info)
{
	printf("first_file = %s\nfirst_cmd = %s\nsec_file = %s\nsec_cmd = %s\n",
		info.first_file, info.first_cmd, info.sec_file, info.sec_cmd);
}
