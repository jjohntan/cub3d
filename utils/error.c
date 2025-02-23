/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:22:13 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/18 10:22:13 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_include/cub3d.h"

/*
Error Message Output:

Error
---------------------------------------------
Issue : Input file extension is incorrect

Expect: .cub

>>> ./invalid_path.txt
---------------------------------------------

*/
void	err_msg(char *issue, char *expect, char *info)
{
	if (issue)
	{
		print("Error\n");
		print(RED "---------------------------------------------" RESET);
		print("\nIssue : ");
		print(issue);
		if (expect)
		{
			print("\n\nExpected : ");
			print(expect);
		}
		if (info)
		{
			print("\n\n>>> ");
			print(info);
		}
		print("\n");
		print(RED "---------------------------------------------" RESET);
		print("\n\n");
	}
}

int	print(char *s)
{
	return (write(2, s, ft_strlen(s)));
}

/*
int main()
{
	char *issue = "Input file extension is incorrect";
	char *expect = ".cub";
	char *filename = "./invalid_path";
	
	err_msg(issue, expect, filename);
	printf("\n\n");
	err_msg(NULL, expect, filename);
	printf("\n\n\n");
	err_msg(issue, NULL, filename);
	printf("\n\n\n");
	err_msg(issue, expect, NULL);
	printf("\n\n\n");
	err_msg(issue, NULL, NULL);
}
*/
