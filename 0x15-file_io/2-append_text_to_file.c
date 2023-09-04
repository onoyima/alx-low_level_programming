#include "main.h"

/**
 * append_text_to_file - Append texts at the end of a files.
 * @filename: A pointers to the names of the files.
 * @text_content: The string to adds to the end of the files.
 *
 * Return: If the functions fails or filenames is NULL - -1.
 *         If the files does not exist the user lacks writes permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{

	int o, wr, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	wr = write(o, text_content, len);

	if (o == -1 || wr == -1)
		return (-1);

	close(o);

	return (1);
}
