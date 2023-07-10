#include "main.h"

/**
 *read_textfile- read and Print  the Text File into a POSIX stdout.
 *
 *@filename: ptr for Name Of File
 *
 *@letters: it Should Be Read & Print the Nums Of Letter of Function
 *
 *Return: Return 0 in case of The Filename Is NULL
 *
 *           in case of Writing  Failed Or it doesn’t  Write -1
 *
 *          Return 0, for Expected Amounts Of Bytes.
 */

ssize_t read_textfile(const char *filename, size_t letters)
	{
	char *buff;
	ssize_t o, w, r;

	if (filename == NULL)
		return (0);
	o = open(filename, O_RDONLY);
	if (o == -1)
		return (0);
	buff = malloc(letters);
	if (buff == NULL)
		return (0);
	r = read(o, buff, letters);
	if (r == -1)
		return (0);
	w = write(STDOUT_FILENO, buff, r);
	if (w == -1 || w != r)
		return (0);
	close(o);
	free(buff);
	return (w);
	}
