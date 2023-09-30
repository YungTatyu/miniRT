/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterao <tterao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:42:27 by tterao            #+#    #+#             */
/*   Updated: 2023/09/30 17:43:52 by tterao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "objs.h"
#include <stdlib.h>

void	global_data_free(t_global_data *data)
{
	free(data->ambient_light);
	free(data->light);
	free(data->camera);
	objs_free(data->objs_list);
}
