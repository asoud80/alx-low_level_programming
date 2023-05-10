#include "main.h"
#include "main.h"

/**
 * create_file - creates a new file
 *
 * @filename: Param description
 * @filename: param description
 *
 * @text_content: param description
 *
 * Return: int
 */
int create_file(const char *filename, char *text_content)
{
	int fp, length = 0, fpwrite;

	fp = open(filename, O_CREAT | o_TRUNC | O-WRONLY, 0600);

	if (fp == -1)
		return (-1);

	if (text_content == NULL)
	{
		text_content = "";
	}

	while (text_content[length] != '\0')
	{
		length++;
	}

	fpWrite = write(fp, text_content, length);

	if (fpWrite == -1)
	{
		return (-1);
	}
	close(fp);
	return (1);
}
