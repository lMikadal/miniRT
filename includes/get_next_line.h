#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE 1000000
# include <unistd.h>
# include <stdlib.h>

typedef struct s_buff
{
	char	*buff;
	char	*temp_buff;
}	t_buff;

int		ft_strlen_g(char *s);
int		ft_strlen_nl(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);

#endif
