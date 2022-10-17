
#include <stdio.h>
void addition()
{
int  a[3][3], b[3][3], sum[3][3], i, j;
int *p=&a[0][0];
int *q=&b[0][0];
int *r=&sum[0][0];

  printf("Enter elements of 1st matrix:\n");
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j) {
      scanf("%d", (p+(i*3)+j));
    }

  printf("Enter elements of 2nd matrix:\n");
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j) {
      scanf("%d", (q+(i*3)+j));
    }

  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j) {
     *(r+(i*3)+j) = *(p+(i*3)+j) + *(q+(i*3)+j);
    }

  printf("Sum of two matrices: \n");
  for (i = 0; i < 3; ++i)
  {
    for (j = 0; j < 3; ++j) {
      printf("%d   ", *(r+(i*3)+j));
    }
    printf("\n");
  }

}
void multiplication()
{
     int a[10][10], b[10][10], c[10][10], i, j, k;
     int *p=&a[0][0];
     int *q=&b[0][0];
     int *r=&c[0][0];

      printf("Enter elements of 1st matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d",  (p+(i*3)+j));
        }
    }

     printf("Enter elements of 2nd matrix:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d",  (q+(i*3)+j));
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
             *(r+(i*3)+j) = 0;
            for (k = 0; k < 3; k++) {
               *(r+(i*3)+j) += *(p+(i*3)+k) * *(q+(k*3)+j);
            }
        }
    }

    printf("The product of the two matrices is: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", *(r+(i*3)+j));
        }
        printf("\n");
    }
}
void saddlepoint()
{
    int a[3][3],flag=0;
      int *p=&a[0][0];
   printf("Enter elements of matrix \n");
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        scanf("%d",(p+(i*3)+j));
     for (int i = 0; i < 3; i++)
    {
        int min = *(p+(i*3)+0), index = 0;
        for (int j = 1; j < 3; j++)
        {
            if (min > *(p+(i*3)+j))
            {
                min = *(p+(i*3)+j);
                index = j;
            }
        }
 
        int k,max=*(p+(0*3)+index);
        for (k = 0; k < 3; k++)
              if(*(p+(k*3)+index)>max) max=*(p+(k*3)+index);
            

        if (min==max)
        {
           printf("Saddle point is %d\n ",min);
           flag++;
        }
    }
    if(flag==0) printf("No saddle point\n ");
}
int main()
{
 char c,d;
 do {
 printf("Please enter \n1 for addition of matrices \n2 for multiplication of matrices\n3 for saddle point\n");
 scanf(" %c",&c);
 switch (c) {
    case '1': 
      addition();
      break;
    case '2':
      multiplication();
      break;
    case '3':
     saddlepoint();
      break;
    default:
      printf("Wrong input");
  }
  printf("Enter y to continue or n to stop\n");
  scanf(" %c",&d);
 }while(d=='y');
 return 0;
}
