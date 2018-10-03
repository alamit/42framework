#include "../include/test42f.h"

bool	test42f_strarr_eq(char *title, char **arr, char **expected)
{
	char	*trace;
	int		res;
	int		line;

	trace = malloc(INIT_STR_LEN * sizeof(char));
	line = 0;
	while (*arr && *expected)
	{
		++arr;
		++expected;
		++line;
	}
	res = (*arr == *expected) || !strcmp(*expected, *arr);
	if (res)
	{
		printf("%sSUCCESS: ", KGRN);
		free(trace);
		trace = "";
	}
	else
	{
		printf("%sFAILED:  ", KRED);
		sprintf(trace,
				"%s\tTRACE: %s\"%s\"%s was expected to be %s\"%s\"%s(line %i)\n",
				KCYN,
				KRED,
				*arr,
				KNRM,
				KGRN,
				*expected,
				KNRM,
				line);
	}
	printf("%s%s \n", KNRM, title);
	printf("%s", trace);
	if (!res)
		free(trace);
	return (res);
}

bool	test42f_strarr_neq(char *title, char **arr, char **expected)
{
	char	*trace;
	int		res;
	int		line;

	trace = malloc(INIT_STR_LEN * sizeof(char));
	line = 0;
	while (*arr && *expected)
	{
		++arr;
		++expected;
		++line;
	}
	res = (*arr == *expected) || !strcmp(*expected, *arr);
	if (!res)
	{
		printf("%sSUCCESS: ", KGRN);
		free(trace);
		trace = "";
	}
	else
	{
		printf("%sFAILED:  ", KRED);
		sprintf(trace,
				"%s\tTRACE: %s\"%s\"%s was expected to be %s\"%s\"%s(line %i)\n",
				KCYN,
				KRED,
				*arr,
				KNRM,
				KGRN,
				*expected,
				KNRM,
				line);
	}
	printf("%s%s \n", KNRM, title);
	printf("%s", trace);
	if (!res)
		free(trace);
	return (res);
}

