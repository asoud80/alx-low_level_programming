#include <stdio.h>

#include "main.h"

#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 *create_buffer - allocate 1024 Bytes into BUFFER
 *
 *@file: Sorting Charcater for The Name Of a File's Buffer
 *Return: Pointer for New Allocat Buffer
 */

char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "error: not able to Write To %s\n", file);
		exit(99);
	}

	return (buff);
}
/**
 * close_file - File Ddescriptor to be Closed
 *
 * @fd: Close File Descriptor
 */

void close_file(int fd)
{
	int p;

	p = close(fd);

	if (p == -1)
	{
		dprintf(STDERR_FILENO, "error: not able to Close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Contents Of File to be Copied into Another File
 *
 * @argc: NUMs Of Argus will be Supplied into a Program
 *
 * @argv: Arrays Of Pointer into Argus.
 *
 * Return: in case of sucess reurn 0
 *
 * Description: Exit code 97, in case of Argument Count not correct
 *              Exit code 98, in case file_from Not Exist Or cannot be Readed
 *              Exit code 99, in case of file_to Cannot be Created Or Written
 *              Exit code 100, in case of file_to Or file_from Cannot Be Closed
 */

int main(int argc, char *argv[])
{
	int w, from, r, to;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	r = read(from, buff, 1024);
	from = open(argv[1], O_RDONLY);
	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		w = write(to, buff, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
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
