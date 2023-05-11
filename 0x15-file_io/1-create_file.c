#include "main.h"
#include "main.h"

/**
 * create_file -- a new file will be created
 *
 * @filename : Description of paramaters.
 * @filename : Description of paramaters.
 *
 * @text_content : Ddescription of paramaters.
 *
 * Return:  int
 */
int create_file(const char *filename, char *text_content)
{
	int fb, length = 0, fbWrite;

	fb = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);

	if (fb == -1)
		return (-1);

	if (text_content == NULL)
	{
		text_content = "";
	}

	while (text_content[length] != '\0')
	{
		length++;
	}

	fbWrite = write(fb, text_content, length);

	if (fbWrite == -1)
	{
		return (-1);
	}
	close(fb);
	return (1);
}
