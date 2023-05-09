#include "main.h"

/**
 * read_textfile - reads text from a file and prints it
 * @filename: name of file to read
 * @letters: number of bytes to read
 *
 * Return: number of bytes to read or printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fp;
	ssize_t bytes;
	char buf[READ_BUF_SIZE * 8];

	if (!filename || letters)
		return (0);
	fp = open(filename, 0_RDONLY);
	if (fp == -1)
		return (0);
	bytes = read(fp, &buf[0], letters);
	bytes = write(STDOUT_FILENO, &buf[0], bytes);
	close(fp);
	return (bytes);
}
