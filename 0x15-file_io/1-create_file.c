#include "main.h"
/**
 *create_file- Creat bothe File & a Text into the file.
 *
 *@filename: Create a File.
 *
 *@text_content: Write a Text Into The File.
 *
 *Return: in case of failure return -1, forsuccess return 1.
 */
int create_file(const char *filename, char *text_content)
{
	int o, w, p, c;

	if (filename == NULL)
		return (-1);
	o = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0600);
	if (o == -1)
		return (-1);
	if (text_content == NULL)
	{
		p = 0;
	}
	else
	{
		p = 0;
		while (text_content[p] != '\0')
			p++;
	}
	w = write(o, text_content, p);
	if (w == -1)
		return (-1);
	c = close(o);
	if (c == -1)
		return (-1);
	return (1);
}
