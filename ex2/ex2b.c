#include <stdio.h>
#define N 3
#define K 5


void reSize (int* in, int* out)
{
    int* p_out = NULL;
    
    int i,j;
    for (i=0; i < N; i++)
    {
        for (j=0; j < N; j++)
        {
            int* p_copy = (in + i * N) + j;

            p_out              = (out + i * 4*N) + 2*j;
            *(p_out)       = *p_copy;
            *(p_out + 1)       = *p_copy;
            *(p_out + 2*N)     = *p_copy;
            *(p_out + 2*N + 1) = *p_copy;
        }
    }

    for (i=0; i < 2*N; i++)
    {
        for (j=0; j < 2*N; j++)
        {
            printf("%4d", *(out + 2*i*N + j));
        }
        printf("\n");
    }
}

int matrix (int* matrix)
{
    int i,j;
    int* p_mat;
    int* p1;
    for (i = 0; i < K ; i++)
    {
        p_mat = (matrix + i * K);
        p1 = p_mat;
        printf("%4d", *p_mat);
        for ( j=0;j<i;j++){
            printf("%4d ",*(p1-4));
           p1 -= 4;
        }
        printf("\n");
    }

    for (i = K - 1; i > 0; i--)
    {
        p_mat += 1;
        p1 = p_mat;
        printf("%4d", *p_mat);
        for (j=1;j<i;j++)
        {
            printf("%4d ", *(p1-4));
            p1 -= 4;
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    
    int arr1[N][N] = {{3,2,12},{9,34,6},{7,90,30}};
    int arr2[2*N][2*N];
    int mat[K][K] = {{45,13,19,69,86},
                     {89,22,42,25,75},
                     {4,55,57,42,36},
                     {95,35,94,10,99},
                     {51,37,34,5,61}};

    reSize(*arr1,*arr2);



    matrix(*mat);

    return 0;
}