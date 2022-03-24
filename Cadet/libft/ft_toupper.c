/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungwol <seungwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:17:24 by seungwol          #+#    #+#             */
/*   Updated: 2022/03/24 22:27:40 by seungwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <ctype.h>
*	DESCRIPTION
*	The toupper() function converts a lower-case letter to the corresponding 
*	upper-case letter. The argument must be representable as an unsigned char 
*	or the value of EOF.
*	PARAMETERS
*	#1. The character to convert.
*	RETURN VALUES
*	If the argument is a lower-case letter, the toupper() function returns the 
*	corresponding upper-case letter if there is one; otherwise, the argument is 
*	returned unchanged.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		c = c - 32;
	return (c);
}
