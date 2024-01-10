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

void split_matrix(char **original, char ***before, char ***after, int rows, int cols)
{
    *before = (char **)malloc(rows * sizeof(char *));
    *after = (char **)malloc(rows * sizeof(char *));

    int i = 0;
    while (i < rows) {
        (*before)[i] = (char *)malloc(cols * sizeof(char));
        (*after)[i] = (char *)malloc(cols * sizeof(char));
        i++;
    }

    // Iterar sobre la matriz original y dividirla en las matrices antes y después
    i = 0;
    while (i < rows) {
        int j = 0;
        while (original[i][j] != '\0' && original[i][j] != ':') {
            (*before)[i][j] = original[i][j];
            j++;
        }
        (*before)[i][j] = '\0'; // Asegurarse de agregar el terminador nulo

        j++; // Saltar el ':'

        int k = 0;
        while (original[i][j] != '\0') {
            (*after)[i][k] = original[i][j];
            j++;
            k++;
        }
        (*after)[i][k] = '\0'; // Asegurarse de agregar el terminador nulo

        i++;
    }
}

char *ft_buffer(int file_descriptor) {
    size_t size_buffer;
    char *buffer;

    size_buffer = 1000;
    buffer = (char *)malloc(sizeof(char) * size_buffer);
    if (buffer == NULL) {
        write(1, "An error occurred during memory allocation", 43);
        close(file_descriptor);
        return ("1");
    }
    return (buffer);
}