#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int nx;
    int ny;
    double *arr;
} matrix;

void set_matrix_element(matrix mat, double value, int i, int j)
{
    mat.arr[i*mat.nx+j] = value;
}

double get_matrix_element(matrix mat, int i, int j)
{
    return mat.arr[i*mat.nx+j];
}

double dot_product(double *vector_a, double *vector_b, int size)
{
    double product = 0.0;
    for (int i = 0; i < size; i++)
        product += vector_a[i] * vector_b[i];

    return product;
}

void matrix_multiplication(matrix mat, double *vector,
double *result)
{
    double *temp = malloc(mat.nx*sizeof(double));
    for (int i = 0; i < mat.nx; i++)
    {
        for(int j = 0; j < mat.ny; j++)
            temp[j] = get_matrix_element(mat, i, j);

        double r = dot_product(temp, vector, mat.nx);
        result[i] = r;
    } 
}

void scalar_multiplication(double *vector, double scalar, int size)
{
    for (int i = 0; i < size; i++)
        vector[i] *= scalar;
}

void subtract_vectors(double *vector_a, double *vector_b,
double *result, int size)
{
    for (int i = 0; i < size; i++)
        result[i] = vector_a[i] - vector_b[i];
}

void array_abs(double *array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = fabs(array[i]);
}

void print_array(double *array, int size)
{   
    for (int i = 0; i < size; i++)
        printf("%g ", array[i]);  
    printf("\n");
}

double find_max(double *array, int size)
{
    double max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

void swap_arrays(double *new_array, double *old_array, int size)
{
    for (int i = 0; i < size; i++)
        new_array[i] = old_array[i];
}

void print_matrix(matrix mat)
{
    for (int i = 0; i < mat.nx; i++)
    {
        for (int j = 0; j < mat.ny; j++)
            printf("%g ", get_matrix_element(mat, i, j));
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

    double *A = malloc(nx*ny*sizeof(double));
    double *b = malloc(n*sizeof(double));
    double *x = malloc(n*sizeof(double));
    double *xn = malloc(n*sizeof(double));
    double *xn1 = malloc(n*sizeof(double));
	
    double *result1 = malloc(n*sizeof(double));
    double *result2 = malloc(n*sizeof(double));
    double *result3 = malloc(n*sizeof(double));
    double *result4 = malloc(n*sizeof(double));

    matrix unit_matrix = {nx, ny, A};

    for (int i = 0; i < unit_matrix.nx; i++)
    {
      for (int j = 0; j < unit_matrix.ny; j++)
      {
        if (i == j)
            set_matrix_element(unit_matrix, 1.0, i, j);
        else
            set_matrix_element(unit_matrix, 0.0, i, j);
      }
    }

    for (int i = 0; i < n; i++)
        x[i] = 1.0;

    puts("Identity matrix:");
    print_matrix(unit_matrix);

    matrix_multiplication(unit_matrix, x, b);

    puts("Vector of free members:");
    print_array(b, n);

    puts("\nActual solution vector:");
    print_array(x, n);
    printf("\n");

    while (eps > 1e-3)
    {
        matrix_multiplication(unit_matrix, xn, result1);
        subtract_vectors(result1, b, result2, n);
        scalar_multiplication(result2, tau, n);
        subtract_vectors(xn, result2, xn1, n);

        subtract_vectors(xn, xn1, result4, n);
        array_abs(result4, n);
        eps = find_max(result4, n);

        num_iter++;
        
        swap_arrays(xn, xn1, n);

        printf("%d. %g\n", num_iter, eps);
    }

    printf("\n");
    puts("Approximate solution vector:");
    print_array(xn, n);

    return 0;
}
