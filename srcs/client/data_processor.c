/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 08:15:28 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/17 08:15:29 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

void		nickname_action(t_socket_client *client, char type, char *nick)
{
	if (nick == NULL)
		return ;
	if (type == 'C')
	{
		client->pseudo = nick;
	}
	else if (type == 'L')
	{
		printf("Votre pseudonyme %s doit avoir une longueur ", nick);
		printf("comprise entre 2 et 10 characters\n");
	}
}

void	data_processor(t_socket_client *client, char *message)
{
	char	action;
	char	type;

	action = '\0';
	type = '\0';
	ft_putstr("\033[u\033[K");
	if (MODE_DEBUG)
		printf("New message : %s\n", message);
	if (ft_strlen(message) > 0)
		action = message[0];
	if (ft_strlen(message) > 1)
		type = message[1];
	if (action == 'N')
		nickname_action(client, type,\
			ft_strsub(message, 2, ft_strlen(message)));
	reprint_line(client);
}