/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2035openfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:41:28 by adrijime          #+#    #+#             */
/*   Updated: 2023/12/12 15:03:09 by adrijime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void split_matrix(char **original, char ***before, char ***after, int rows, int cols) {
    // Asignar memoria para las nuevas matrices antes y después
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

char ft_read(char *buffer, int file_descriptor) {
    size_t size_buffer;
    ssize_t readed_bytes;
    size_t buffer_index;

    size_buffer = 1000;
    buffer_index = 0;
    while ((readed_bytes = read(file_descriptor, buffer + buffer_index, size_buffer - buffer_index)) > 0) {
        buffer_index += readed_bytes;
    }
    if (readed_bytes == -1) {
        write(1, "An error occurred while reading the file", 42);
        free(buffer);
        close(file_descriptor);
        return ('1');
    }
    return ('0');
}

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

char **ft_create_matrix(char *buffer, int DescriptorFile) {
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
        write(1, "An error occurred in the memory allocation process", 50);
        close(DescriptorFile);
        //return("cierraprograma");
    }
    return (matrix);
}

void ft_write_in_matrix(char **matrix, char *buffer) {
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

void ft_print_centenas(char *str, int x, char **m_bef, char **m_aft)
{
    int i;
    int j;

    i = 0;
    while (str[x] != m_bef[i][0] && !(m_bef[i][1] >= '0' && m_bef[i][1] <= '9')) 
    {
        i++;
    }
    j = 0;
    while (m_aft[i][j])
    {
        write(1, &m_aft[i][j],1);
        j++;
    }
    write(1, " hundred ", 9);
    if (str[x + 1] != '0' && str[x + 2] != '0')
    {
        write(1, "and ", 4);
    }
}

void ft_print_decenas(char *str, int x, char **m_bef, char **m_aft)
{
    int i;
    int j;

    i = 0;
    while (str[x] != m_bef[i][0] || m_bef[i][1] != '0') 
    {
        i++;
    }
    j = 0;
    while (m_aft[i][j])
    {
        write(1, &m_aft[i][j],1);
        j++;
    }
    if (str[x+1] == '0')
    {
        write(1, " ", 1);
    }
    else
    {
        write(1, "-", 1);
    }
}
void ft_print_teens(char *str, int x, char **m_bef, char **m_aft)
{
    int i;
    int j;

    i = 0;
    while (str[x+1] != m_bef[i][1]) 
    {
        i++;
    }
    j = 0;
    while (m_aft[i][j])
    {
        write(1, &m_aft[i][j],1);
        j++;
    }
    if (str[x + 2] != '\0')
        write(1, " ", 1);
}
void ft_print_unidades(char *str, int x,char **m_bef, char **m_aft)
{
    int i;
    int j;

    i = 0;
    while ((str[x] != m_bef[i][0]) && !(m_bef[i][1] >= '0' && m_bef[i][1] <= '9'))
    {
        i++;
    }
    j = 0;
    while (m_aft[i][j])
    {
        write(1, &m_aft[i][j],1);
        j++;
    }
    if (str[x + 1] != '\0')
        write(1, " ", 1);
}

int ft_strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// Buscar una cadena en una matriz y devolver el índice de la fila
int find_string_in_matrix(char *src, char **matrix) {
    int j; 
    
    j = 0;
    while (matrix[j] && ft_strcmp(src, matrix[0]) != 0)
    {
        j++;
    }
    return (j);
}

void ft_print_matrix(char *buffer, char **matrix) {
    int i;
    int j;
    int row;
    int cols;

    row = ft_count_rows(buffer);
    cols = ft_count_cols(buffer);
    i = 0;
    j = 0;
    while (i < row) {
        while (j < cols) {
            j++;
        }
        i++;
    }
}


int ft_openfile(char *argv1) {
    const char *FileName;
    int file_descriptor;
    char *buf;

    FileName = argv1;
    file_descriptor = open(FileName, O_RDONLY);
    if (file_descriptor == -1) {
        write(1, "The file cannot be opened", 25);
        return ('1');
    }
    return (file_descriptor);
}

int ft_calc_len(int *len, char *str)
{
    if (str[0] == '-')
        return (0);
    while (str[*len])
    {
        *len = *len + 1;
    }
    if (*len > 37)
        return (0);
    return (-1); // DEVUELVE ERROR EN EL MAIN
}
// NUEVO ARCHIVO
void ft_print(int len, char *str, char **m_bef, char **m_aft)
{
    int x;
    int y;
    int teens;
    int m;

    m = (len - 1) / 3;
    x = 0;
    y = 0;
    teens = 0;
    if (len % 3 == 1)
    {
        y = 2;
    }
    else if (len % 3 == 2)
    {
        y = 1;
    }
    while (str[x])
    {
        // MOVERLO A OTRA FUNCION
        if (y == 0)
        {
            if (str[x] != '0')
            {
                ft_print_centenas(str,x,m_bef,m_aft);
            }
            y++;
            x++;
        }
        // MOVERLO A OTRA FUNCION
        if (y == 1)
        {
            if (str[x] == '1')
            {
                teens = 1;
                ft_print_teens(str,x,m_bef,m_aft);
            }
            else if (str[x] != '0')
            {
                ft_print_decenas(str,x,m_bef,m_aft);
            }
            y++;
            x++;
        }
        // MOVERLO A OTRA FUNCION
        if (y == 2)
        {
            if (teens == 1)
            {
                teens = 0;
            }
            else if (str[x] != '0')
            {
                ft_print_unidades(str,x,m_bef,m_aft);
 
            }
            if (m > 0)
            {
                ft_apellidos(m, m_bef, m_aft);
                m--;
            }
            x++;
        }
        y = 0;
    }
}

int main(int argc, char **argv) {
    int file;
    char *bufer;
    char **matrix;
    char **matrix_before;
    char **matrix_after;
    char *defaultFileName;
    int len;

    len = 0;
    defaultFileName = "numbers.dict";
    if (argc == 2) 
    {
        file = ft_openfile(defaultFileName);
    } 
    if (argc == 3)
    {
        file = ft_openfile(argv[1]);
    }
    if (argc > 3) {
        write(1, "Incorrect use. Provide a file as an argument.\n", 46);
        return (-1);
    } 
    // UP TO ÑU
    bufer = ft_buffer(file);
    ft_read(bufer, file);
    int rows = ft_count_rows(bufer);
    int cols = ft_count_cols(bufer);
    matrix = ft_create_matrix(bufer, file);
    matrix_before = ft_create_matrix(bufer, file);
    matrix_after = ft_create_matrix(bufer, file);
    ft_write_in_matrix(matrix, bufer);
    ft_print_matrix(bufer, matrix);
    split_matrix(matrix, &matrix_before, &matrix_after, rows, cols);
    ft_print_matrix(bufer, matrix_before);
    ft_print_matrix(bufer, matrix_after);
    ft_calc_len(&len,argv[1]);
    ft_print(len, argv[1], matrix_before, matrix_after);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
        free(matrix_before[i]);
        free(matrix_after[i]);
    }
    free(matrix);
    free(matrix_before);
    free(matrix_after);

    return (0);
}