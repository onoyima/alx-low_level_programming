#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Reads text file print to STDOUT.
 * @filename: text files being read
 * @letters: number of letters to be read
 * Return: w- actual numbers of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t mak;
	ssize_t wr;
	ssize_t t;

	mak = open(filename, O_RDONLY);
	if (mak == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(mak, buf, letters);
	wr = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(mak);
	return (wr);
}
