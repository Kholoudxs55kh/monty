#include "main.h"
#include <stdio.h>
/**
 * main - .
 * @argc: .
 * @argv: .
 * Return: .
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	FILE *fd;
	unsigned int line_num;
	size_t line_len;

	if (argc != 2)
	{
		fprintf(stderr, "USSAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_num = 1;
	while (getline(&line, &len, fd) != -1)
	{
		line_len = strlen(line);
		if (line_len > 0 && line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		/*
		 *the functions calls
		 */
		line_num++;
	}
	free(line);
	fclose(fd);
	return (0);
}
