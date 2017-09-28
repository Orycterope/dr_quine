#include <stdio.h>

/*
	Im a comment ! :D
*/

int	nl(void)
{
	return 10;
}

int	main(void)
{
	/*
		Im inside main !
	*/
	char	*format = "#include <stdio.h>%c%c/*%c	Im a comment ! :D%c*/%c%cint	nl(void)%c{%c	return 10;%c}%c%cint	main(void)%c{%c	/*%c		Im inside main !%c	*/%c	char	*format = %c%s%c;%c%c	printf(format, nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), 34, format, 34, nl(), nl(), nl(), nl());%c}%c";

	printf(format, nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), nl(), 34, format, 34, nl(), nl(), nl(), nl());
}
