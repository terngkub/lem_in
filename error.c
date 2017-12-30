/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:58:22 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 19:31:31 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error", 2);
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	*ft_malloc_e(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		ft_error("malloc failed");
	return (mem);
}

char	*ft_strdup_e(char *str)
{
	char	*dup;

	if (!(dup = ft_strdup(str)))
		ft_error("malloc failed in ft_strdup");
	return (dup);
}

char	**ft_strsplit_e(char *str, char c)
{
	char	**arr;

	if (!(arr = ft_strsplit(str, c)))
		ft_error("malloc failed in ft_strsplit");
	return (arr);
}

char	*ft_strfreecat_back_e(char **str1, char *str2)
{
	char	*str;

	if (!(str = ft_strfreecat_back(str1, str2)))
		ft_error("malloc failed in ft_strfreecat_back");
	return (str);
}
