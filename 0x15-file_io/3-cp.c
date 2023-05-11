#include "main.h"

/**
 * main - all content will be copied to another files
 *
 * @argc:  int description
 *
 * @argv: double ptr description
 *
 * Return: copies of all file - copy description
 */

int main(int argc, char **argv)
{
	int fb1, fb2, filecheck;
	char buffer[1024];

	if (argc != 3)
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	fb1 = open(argv[1], O_RDONLY);
	if (fb1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fb2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fb2 == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	while ((filecheck = read(fb1, buffer, 1024)) > 0)
	{
		if (filecheck == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		filecheck = write(fb2, buffer, filecheck);
		if (filecheck == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (filecheck == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (close(fb1) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fb1), exit(100);
	if (close(fb2) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fb2), exit(100);

	return (0);
}
