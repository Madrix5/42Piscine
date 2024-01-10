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

int ft_count_rows(char *buffer) {
    int i;
    int col;
    int row;
    int cols;

    i = 0;
    row = 0;
    col = 0;
    cols = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            row++;
            if (col > cols)
                cols = col;
            col = -1;
        }
        i++;
        col++;
    }
    return (row);
}

int ft_count_cols(char *buffer) {
    int i;
    int col;
    int row;
    int cols;

    i = 0;
    row = 0;
    col = 0;
    cols = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            row++;
            if (col > cols)
                cols = col;
            col = -1;
        }
        i++;
        col++;
    }
    return (cols);
}