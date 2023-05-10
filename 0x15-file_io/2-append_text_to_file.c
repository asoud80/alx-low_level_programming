#include "main.h"

/**
 * append_text_to_file - appends text at the end of the file
 *
 * @filename: const char pointer
 *
 * @text_content: char pointer
 *
 * Return int
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fdopen, fdWrite, length = 0;

	if (filename == NULL)
		return (-1);

	fdopen = open(filename, O_WRONLY | O_APPEND);

	if (fdopen == -1)
	{
		return (-1);
	}
	if (text_content == NULL)
		text_content = "";

	while (text_content[length] != '\0')
	{
		length++;
	}
	fdWrite = write(fdopen, text_content, length);

	if (fdWrite == -1)
		return (-1);
	close(fdopen);

	return (1);
}
