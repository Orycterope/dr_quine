#include <stdio.h>
#include <stdlib.h>

/*
	Im a comment ! :D
*/

#define FORMAT "#include <stdio.h>%c#include <stdlib.h>%c%c/*%c	Im a comment ! :D%c*/%c%c#define FORMAT %c%s%c%c%c#define NL 10%c%c#define START(FILENAME) %c%cint	main(void) %c%c{ %c%c	FILE *f; %c%c	if ((f = fopen(FILENAME, %cw%c)) == NULL) %c%c		return (EXIT_FAILURE); %c%c	fprintf(f, FORMAT, NL, NL, NL, NL, NL, NL, NL, 34, FORMAT, 34, NL, NL, NL, NL, 92, NL, 92, NL, 92, NL, 92, NL, 34, 34,  92, NL, 92, NL, 92, NL, 92, NL, NL, NL, 34, FILENAME, 34, NL); %c%c	return (EXIT_SUCCESS); %c%c}%c%cSTART(%c%s%c)%c"

#define NL 10

#define START(FILENAME) \
int	main(void) \
{ \
	FILE *f; \
	if ((f = fopen(FILENAME, "w")) == NULL) \
		return (EXIT_FAILURE); \
	fprintf(f, FORMAT, NL, NL, NL, NL, NL, NL, NL, 34, FORMAT, 34, NL, NL, NL, NL, 92, NL, 92, NL, 92, NL, 92, NL, 34, 34,  92, NL, 92, NL, 92, NL, 92, NL, NL, NL, 34, FILENAME, 34, NL); \
	return (EXIT_SUCCESS); \
}

START("Grace_kid.c")
