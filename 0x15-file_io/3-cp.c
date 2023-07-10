#include <stdlib.h>
#include <stdio.h>
#include "main.h"

void cls_fle(int fed);
char *crt_buff(char *fle);


/**
 *crt_buff - 1024 Bytes to be allocated into the Buffer
 *
 *@fle: Sorting the characters of name Of a File's Buffer
 *Return: Pointer To a Newly Buffer that will be Allocated
 */

char *crt_buff(char *fle)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "error: it Cannot Write into %s\n", fle);
		exit(99);
	}

	return (buff);
}

/**
 * cls_fle - File Descriptor will be closed
 *
 * @fed: Close File Descriptor.
 */

void cls_fle(int fed)
{
	int d;

	d = close(fed);

	if (d == -1)
	{
		dprintf(STDERR_FILENO, "error: Cannot close fed %d\n", fed);
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
	int r, w, f, t;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: copy fle_from fle_to\n");
		exit(97);
	}

	buff = crt_buff(argv[2]);
	f = open(argv[1], O_RDONLY);
	r = read(f, buff, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "error: Cannot Read From a File %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		w = write(t, buff, r);
		if (t == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "error: Cannot Write t %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		r = read(f, buff, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buff);
	cls_fle(f);
	cls_fle(t);

	return (0);
}
