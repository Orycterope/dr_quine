#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	i = 5;

#define SRC_PARAMS 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 34, src_format, 34, 10, 10, 34, gcc_cmdline_format, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 34, 37, 34, 10, 34, 37, 34, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10

char	*src_format = "#include <stdio.h>%c#include <stdlib.h>%c#include <unistd.h>%c#include <string.h>%c%cint	i = %d;%c%c#define SRC_PARAMS 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 34, src_format, 34, 10, 10, 34, gcc_cmdline_format, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 34, 37, 34, 10, 34, 37, 34, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10%c%cchar	*src_format = %c%s%c;%c%cchar	*gcc_cmdline_format = %c%s%c;%c%cint	main(void)%c{%c	char	filename_c[64];%c	char	filename_exe[64];%c	char	gcc_cmdline[64];%c	FILE	*f;%c%c	i -= strcmp(__FILE__, %cSully/Sully.c%c) == 0 ? 0 : 1;%c	snprintf(filename_c, sizeof(filename_c), %cSully_%cd.c%c, i);%c	snprintf(filename_exe, sizeof(filename_exe), %c./Sully_%cd%c, i);%c	snprintf(gcc_cmdline, sizeof(gcc_cmdline), gcc_cmdline_format, filename_c, filename_exe);%c	if ((f = fopen(filename_c, %cw%c)) == NULL)%c		return (EXIT_FAILURE);%c	fprintf(f, src_format, SRC_PARAMS);%c	fclose(f);%c	if (system(gcc_cmdline) == 0 && i > 0)%c		execv(filename_exe, NULL);%c	return (EXIT_SUCCESS);%c}%c";

char	*gcc_cmdline_format = "clang -Wall -Wextra -Werror %s -o %s";

int	main(void)
{
	char	filename_c[64];
	char	filename_exe[64];
	char	gcc_cmdline[64];
	FILE	*f;

	i -= strcmp(__FILE__, "Sully/Sully.c") == 0 ? 0 : 1;
	snprintf(filename_c, sizeof(filename_c), "Sully_%d.c", i);
	snprintf(filename_exe, sizeof(filename_exe), "./Sully_%d", i);
	snprintf(gcc_cmdline, sizeof(gcc_cmdline), gcc_cmdline_format, filename_c, filename_exe);
	if ((f = fopen(filename_c, "w")) == NULL)
		return (EXIT_FAILURE);
	fprintf(f, src_format, SRC_PARAMS);
	fclose(f);
	if (system(gcc_cmdline) == 0 && i > 0)
		execv(filename_exe, NULL);
	return (EXIT_SUCCESS);
}
