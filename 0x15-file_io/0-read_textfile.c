#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Reads texts file prints to STDOUT.
 * @filenames: texts files being read
 * @letters: numbers of letters to be reads
 * Return: w- actual numbers of bytes reads and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
