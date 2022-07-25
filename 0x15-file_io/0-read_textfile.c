#include "main.h"
/**
 * read_textfile - reads a test file a nd prints it to the POSIX
 * @filename: file to be read from using the system call read
 * @letters: no of letters to be printed to buf
 * Return: returns 0 if filename is null, returns the actual n
 * umber of letters it can read if successful
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buf, letters);
	w = write(STDOUT_FILENO, buf, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(o);

	return (w);
}
