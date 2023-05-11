#include "main.h"

/**
 * read_textfile -- read all texts from a file and print all of it
 * @filename: read all file's name 
 * @letters: read all number of bytes.
 *
 * Return: print all number of bytes
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fb;
	ssize_t bytes;
	char buf[READ_BUF_SIZE * 8];

	if (!filename || !letters)
		return (0);
	fb = open(filename, O_RDONLY);
	if (fb == -1)
		return (0);
	bytes = read(fb, &buf[0], letters);
	bytes = write(STDOUT_FILENO, &buf[0], bytes);
	close(fb);
	return (bytes);
}
