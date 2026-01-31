#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 1;
	while (!gnl_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		buffer[bytes] = '\0';
		stash = gnl_strjoin(stash, buffer);
	}
	return (stash);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	int		i;

	if (!*stash || **stash == '\0')
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	line = gnl_substr(*stash, 0, i + ((*stash)[i] == '\n'));
	new_stash = gnl_substr(*stash, i + ((*stash)[i] == '\n'), gnl_strlen(*stash) - i);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	return (extract_line(&stash));
}
