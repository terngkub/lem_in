/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:58:22 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/30 16:38:48 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
