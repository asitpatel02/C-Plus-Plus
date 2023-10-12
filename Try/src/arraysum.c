#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arraySum (int x[], int y[], int sizex, int sizey);
void main()
{
  int n, m, i;
  printf ("Enter size of first array: ");
  scanf ("%d", &n);

  printf ("Enter size of second array: ");
  scanf ("%d", &m);
  int x[n], y[m];
  for (i = 0; i < n; i++)
    {
      printf ("Enter an element for 1st array: ");
      scanf ("%d", &x[i]);
    }
  for (i = 0; i < m; i++)
    {
      printf ("Enter an element for 2nd array: ");
      scanf ("%d", &y[i]);
    }
  printf ("sum = %d", arraySum (x, y, n, m));
}
int arraySum(int *x, int *y, int n, int m)
{
    int sum=0;
    if(n>m)
    {
        for(int i=0;i<m;i++)
        {
            sum+=x[i]+y[i];
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            sum+=x[i]+y[i];
        }
    }
    return sum;
}
