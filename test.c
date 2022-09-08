#include "./libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

// gcc test.c libft/libft.a
// ./a.out

int main(void)
{
	char	*buf;
	int 	fp = open("7_permutations.txt", O_RDONLY);
	if (fp < 0)
		return (-1);
	while (get_next_line(fp, &buf))
	{
		system("sleep 0.2");
		buf = strjoin_pro("ARG=\"", buf, 2);
		buf = strjoin_pro(buf, "\";./push_swap $ARG | ./checker $ARG", 1);
		system((const char *)buf);
		ft_strdel(&buf);
	}
	return (0);
}