#include "main.h"

/**
 * create_file - creates a new file
 *
 * @filename: param dsecription
 *
 * @text_content: param description
 *
 * Return int
 */
int create_file(const char *filename, char *text_content)
{
	int fd, length = 0, fdwrite;
	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);

	if (fd == 1)
		return (-1);

	if (text_content == NULL)
	{
		text_content ="";
	}
	while (text_content[length] != '\0')
	{
		length++;
	}
	fdwrite = write(fd, text_content, length);
	if (fdwrite == -1)
	{
		return (-1);
	}
	close(fd);
	return (1);
}
