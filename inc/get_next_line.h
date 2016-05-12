/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:05:15 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/21 20:05:57 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE		1
# define MULTI_MEMORY	2
# define MAX_FD			1000

typedef struct		s_var
{
	char			*return_line;
	char			*memory;
	long			len;
	long			tampon;
	int				file_lecture;
}					t_var;

int					get_next_line(int fd, char **line);

#endif
