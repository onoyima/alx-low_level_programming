#include "main.h"

/**
 * create_file - Create a files.
 * @filename: A pointer to the names of the files to creates.
 * @text_content: A pointer to a strings to write to the file.
 *
 * Return: If the functions fails - -1.
 *         Otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int mak, wr, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	mak = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(mak, text_content, len);

	if (mak == -1 || wr == -1)
		return (-1);

	close(mak);

	return (1);
}
