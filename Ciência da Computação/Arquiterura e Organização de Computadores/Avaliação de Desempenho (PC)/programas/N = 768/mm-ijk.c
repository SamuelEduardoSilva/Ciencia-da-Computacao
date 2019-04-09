#include <stdio.h>
#include <time.h>

#define N 768

double A[N][N], B[N][N], C[N][N];

int main ()
{
int i, j, k;
clock_t start, end;

/* inicia matrizes */
for (i=0; i<N; i++)
  for (j=0; j<N; j++)
    {
    A[i][j] = 0.5;
    B[i][j] = 2.0;
    C[i][j] = 0.;
    }

/* multiplicacao -- versao ijk */
start = clock();
for (i=0; i<N; i++)
  for (j=0; j<N; j++)
    for (k=0; k<N; k++)
      C[i][j] = C[i][j] +  A[i][k] * B[k][j];
end = clock();

printf("Tempo: %.3f seg N: %d\n", (double)(end-start)/CLOCKS_PER_SEC, N);

/* verifica resultado */
for (i=0; i<N; i++)
  for (j=0; j<N; j++)
    if (C[i][j] != (double)N)
      {
      printf ("Erro em C[%d][%d]: %f != %d\n", i,j,C[i][j],N);
      return 1;
      }

return 0;
}
