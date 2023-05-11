#include "main.h"

/**
 * append_text_to_file: append_text_to_file - append description
 *
 * @filename : Const char ptr
 *
 * @text_content : Char ptr
 *
 * Return: int
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fbopen, bdWrite, length = 0;

	if (filename == NULL)
		return (-1);

	fbopen = open(filename, O_WRONLY | O_APPEND);

	if (fbopen == -1)
	{
		return (-1);
	}
	if (text_content == NULL)
		text_content = "";

	while (text_content[length] != '\0')
	{
		length++;
	}
	fbWrite = write(fbopen, text_content, length);

	if (fbWrite == -1)
		return (-1);
	close(fbopen);

	return (1);
}
