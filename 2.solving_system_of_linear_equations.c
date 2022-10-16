#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void set_matrix_element(double *matrix, double value, int size, int i, int j)
{
    matrix[i*size + j] = value;
}

double get_matrix_element(double *matrix, int size, int i, int j)
{
    return matrix[i*size + j];
}

double dot_product(double *vector_a, double *vector_b, int size)
{
    double result = 0.0;

    for (int i = 0; i < size; i++)
    {
        result += vector_a[i] * vector_b[i];
    }

    return result;
}

void matrix_multiplication(double *matrix, double *vector, double *result, int size)
{
    double *temp = malloc(size * sizeof(double));

    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            temp[j] = get_matrix_element(matrix, size, i, j);
        }

        double r = dot_product(temp, vector, size);
        result[i] = r;
    } 
}

void scalar_multiplication(double *vector, double scalar, int size)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] *= scalar;
    }
}

void subtract_vectors(double *vector_a, double *vector_b, double *result, int size)
{
    for (int i = 0; i < size; i++)
    {
        result[i] = vector_a[i] - vector_b[i];
    }
}

void array_abs(double *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = fabs(array[i]);
    }
}

void print_array(double *array, int size)
{   
    for (int i = 0; i < size; i++)
    {
        printf("%g ", array[i]);  
    }
    printf("\n");
}

double find_max_element(double *array, int size)
{
    double max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

void swap_array_elements(double *new_array, double *initial_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        new_array[i] = initial_array[i];
    }
}

void print_matrix(double *matrix, int nx, int ny)
{
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            printf("%g ", get_matrix_element(matrix, ny, i, j));
        }
        printf("\n");   
    }
    printf("\n");
}

int main()
{
    int nx = 3;
    int ny = 3;
    int n = 3;
    double eps = 1e6;
    double tau = 0.01;
    int num_iter = 0;

    double *A = malloc(nx * ny * sizeof(double));
    double *b = malloc(n * sizeof(double));
    double *x = malloc(n * sizeof(double));
    double *xn = malloc(n * sizeof(double));
    double *xn1 = malloc(n * sizeof(double));
	
    double *result1 = malloc(n * sizeof(double));
    double *result2 = malloc(n * sizeof(double));
    double *result3 = malloc(n * sizeof(double));
    double *result4 = malloc(n * sizeof(double));

    for (int i = 0; i < nx; i++)
    {
      for (int j = 0; j < ny; j++)
      {
        if (i == j)
        {
            set_matrix_element(A, 1.0, n, i, j);
        }
        else
        {
            set_matrix_element(A, 0.0, n, i, j);
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
        x[i] = 1.0;
    }

    puts("Identity matrix:");
    print_matrix(A, nx, ny);

    matrix_multiplication(A, x, b, n);

    puts("Vector of free members:");
    print_array(b, n);

    puts("\nActual solution vector:");
    print_array(x, n);
    printf("\n");

    while (eps > 1e-3)
    {
        matrix_multiplication(A, xn, result1, n);
        subtract_vectors(result1, b, result2, n);
        scalar_multiplication(result2, tau, n);
        subtract_vectors(xn, result2, xn1, n);

        subtract_vectors(xn, xn1, result4, n);
        array_abs(result4, n);
        eps = find_max_element(result4, n);

        num_iter++;
        
        swap_array_elements(xn, xn1, n);

        printf("%d. %g\n", num_iter, eps);
    }

    printf("\n");
    puts("Approximate solution vector:");
    print_array(xn, n);

    return 0;
}
