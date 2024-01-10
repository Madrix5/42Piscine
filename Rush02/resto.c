#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_print(int len, char *str, char **m_bef, char **m_aft);
int	ft_calc_len(int *len, char *str);
int	ft_openfile(char *argv1);
void	ft_print_matrix(char *buffer, char **matrix);
int	find_string_in_matrix(char *src, char **matrix);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_print_unidades(char *str, int x,char **m_bef, char **m_aft);
void	ft_print_teens(char *str, int x, char **m_bef, char **m_aft);
void	ft_print_decenas(char *str, int x, char **m_bef, char **m_aft);
void	ft_print_centenas(char *str, int x, char **m_bef, char **m_aft);
void	ft_apellidos(int m, char **m_bef, char **m_aft);
void	ft_write_in_matrix(char **matrix, char *buffer);
char	**ft_create_matrix(char *buffer, int DescriptorFile);
int	ft_count_cols(char *buffer);
int	ft_count_rows(char *buffer);
char	ft_read(char *buffer, int file_descriptor);
char	*ft_buffer(int file_descriptor);
void	split_matrix(char **original, char ***before, char ***after, int rows, int cols);
void	freee(char **matrix, char **matrix_before, char **matrix_after, int rows);

char **ft_create_matrix(char *buffer, int DescriptorFile)
{
    int i;
    int rows;
    int cols;
    char **matrix;

    i = 0;
    rows = ft_count_rows(buffer);
    cols = ft_count_cols(buffer);
    matrix = (char **)malloc(rows * sizeof(char *));
    while (i < rows) {
        matrix[i] = (char *)malloc(cols * sizeof(char));
        i++;
    }
    if (matrix == NULL) {
        write(1, "Error.\n", 7);
        close(DescriptorFile);
    }
    return (matrix);
}

void ft_write_in_matrix(char **matrix, char *buffer)
{
    int x;
    int y;
    int i;

    x = 0;
    y = 0;
    i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] != ' ') {
            if (buffer[i] != '\n') {
                matrix[x][y] = buffer[i];
                y++;
            }
            if (buffer[i] == '\n') {
                x++;
                y = 0;
            }
        }
        i++;
    }
}

void ft_apellidos(int m, char **m_bef, char **m_aft)
{
    int i;
    int j;

    i = 0;
    while(m_bef[i][m*3] != '0' || m_bef[i][m*3+1] == '0')
    {
        i++;
    }
    j = 0;
    while (m_aft[i][j])
    {
        write(1, &m_aft[i][j],1);
        j++;
    }
    write(1, ", ", 2);
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int find_string_in_matrix(char *src, char **matrix)
{
    int j; 
    
    j = 0;
    while (matrix[j] && ft_strcmp(src, matrix[0]) != 0)
    {
        j++;
    }
    return (j);
}

