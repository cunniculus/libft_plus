#include "libft.h"

void print_split(char **split);
void	free_split(char **split);

int main()
{
	char **split;

	ft_printf("empty string, char 0: \n");
	split = ft_split("", 0);
	print_split(split);
	free_split(split);

	ft_printf("\nempty string, char ' ': \n");
	split = ft_split("", ' ');
	print_split(split);
	free_split(split);

	ft_printf("\nstring made of delimiters only, char ' ': \n");
	split = ft_split("      ", ' ');
	print_split(split);
	free_split(split);

	ft_printf("\nNULL, 0 \n");
	split = ft_split(NULL, 0);
	print_split(split);
	free_split(split);

	ft_printf("\nAmor, 0 \n");
	split = ft_split("Amor", 0);
	print_split(split);
	free_split(split);

	ft_printf("\nFuria funesta, ' ' \n");
	split = ft_split("Furia funesta",  ' ');
	print_split(split);
	free_split(split);

	ft_printf("\n      Furia       funesta     , ' ' \n");
	split = ft_split("       Furia      funesta        ",  ' ');
	print_split(split);
	free_split(split);
	return (0);
}

void print_split(char **split)
{
	if (!split)
		ft_printf("split is %p\n", split);
	else if (!*split)
		ft_printf("split with %p element.\n", *split);
	else
		while (*split)
		{
			ft_printf("%s\n", *split);
			split++;
		}
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while(split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);

}
