#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int x, y, n, t, i, flag;
long int e[50], d[50], temp[50], j, m[50], en[50];
char msg[100];
int prime(long int);
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();

int main()
{
  printf("\nEnter first prime number: \n");
  scanf("%d", &x);
  flag = prime(x);
  if(flag == 0)
  {
    printf("\nINVALID INPUT\n");
    exit(0);
  }
  printf("\nEnter second prime number\n");
  scanf("%d", &y);
  flag = prime(y);
  if(flag == 0 || x == y)
  {
    printf("\nINVALID INPUT\n");
    exit(0);
  }
  printf("\nEnter your message: \n");

  scanf("%s",msg);
  for(i = 0; msg[i] != NULL; i++)
    m[i] = msg[i];
  n = x * y;
  t = (x-1) * (y-1);
  encryption_key();
  printf("\nPossible values of e and d are:\n");
  for(i = 0; i < j-1; i++)
    printf("\n%ld\t%ld", e[i], d[i]);
  encrypt();
  decrypt();
  return 0;
}
int prime(long int pr)
{
  int i;
  j = sqrt(pr);
  for(i = 2; i <= j; i++)
  {
   if(pr % i == 0)
     return 0;
  }
  return 1;
 }

void encryption_key()
{
  int k;
  k = 0;
  for(i = 2; i < t; i++)
  {
    if(t % i == 0)
     continue;
    flag = prime(i);
    if(flag == 1 && i != x && i != y)
    {
     e[k] = i;
     flag = cd(e[k]);
    if(flag > 0)
    {
     d[k] = flag;
     k++;
    }
   if(k == 99)
    break;
   }
 }
}
long int cd(long int a)
{
  long int k = 1;
  while(1)
  {
    k = k + t;
    if(k % a == 0)
     return(k / a);
  }
}

void encrypt()
{
  long int pt, ct, key = e[0], k, len;
  i = 0;
  len = strlen(msg);
  while(i != len)
  {
    pt = m[i];
    pt = pt - 96;
    k = 1;
    for(j = 0; j < key; j++)
    {
     k = k * pt;
     k = k % n;
    }
   temp[i] = k;
   ct = k + 96;
   en[i] = ct;
   i++;
  }
  en[i] = -1;
  printf("\n\nEncrypted message: \n");
  for(i = 0; en[i] != -1; i++)
    printf("%c", en[i]);
}

void decrypt()
{
  long int pt, ct, key = d[0], k;
  i = 0;
  while(en[i] != -1)
  {
    ct = temp[i];
    k = 1;
    for(j = 0; j < key; j++)
    {
      k = k * ct;
      k = k % n;
    }
   pt = k + 96;
   m[i] = pt;
   i++;
  }
  m[i] = -1;
  printf("\n\nDecrypted message:\n");
  for(i = 0; m[i] != -1; i++)
   printf("%c", m[i]);
  printf("\n");
}
