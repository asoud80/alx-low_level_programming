#include <stdlib.h>
#include <stdio.h>
#include "main.h"

void close_file(int fd);
char *create_buffer(char *file);

/**
 * create_buffer - 1024 Bytes to be allocated into the Buffer
 *
 *@file: Sorting the characters of name Of a File's Buffer
 *Return: Pointer To a Newly Buffer that will be Allocated
 */

char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "error: it Cannot Write into %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - File Descriptor will be closed
 *
 * @fd: Close File Descriptor.
 */

void close_file(int fd)
{
	int d;

	d = close(fd);

	if (d == -1)
	{
		dprintf(STDERR_FILENO, "error: Cannot close fed %d\n", fd);
		exit(100);
	}
}

/**
 * main - a Contents Of the File will be Copied into Another File
 *
 * @argc: Numb Of args will be Supplied into a Program
 *
 * @argv: the Array Of the Pointers into Args
 *
 * Return: in case of Success return 0.
 * Description: Exit Code 97, in case of Arg's Count not Correct
 *
 *              Exit code 98,in case of fle_from Does't Exist Or Cannot Be Read
 *
 *              Exit code 99, in case of fle Can't Be Created Or Written
 *
 *              Exit code 100, in case of fle_to Or fle_from Can't Be Closed
 */

int main(int argc, char *argv[])
{
	int r, w, from, to;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: copy fle_from fle_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "error: Cannot Read From a File %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		w = write(to, buff, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "error: Cannot Write t %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		r = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buff);
	close_file(from);
	close_file(to);

	return (0);
}
