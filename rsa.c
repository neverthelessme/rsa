#include<stdio.h>
#include<stdlib.h>
int cprime(int n)
{
int i;
int m = n / 2;
for (i = 2; i <= m; i++)
{
if (n % i == 0)
{
return 0;
}
}
return 1;
}
int findGCD(int n1, int n2) {
int i, gcd;
for(i = 1; i <= n1 && i <= n2; ++i) {
if(n1 % i == 0 && n2 % i == 0)
gcd = i;
}
return gcd;
}
int powmod(int a, int b, int n) {
long x = 1, y = a;
while (b > 0) {
if (b % 2 == 1)
x = (x * y) % n;
y = (y * y) % n;
b /= 2;
}
return x % n;
}
int main()
{
int n,p,q,phin;
int data,cipher,decrypt;
printf("Enter the prime numbers:\n");
scanf("%d %d",&p,&q);
if(cprime(p)==0 || cprime(q)==0)
{
printf("invalid input");
exit(1);
}
n=p*q;
phin=(p-1)*(q-1);
int e = 0,d;
for (e = 5; e <= 100; e++) {
if (findGCD(phin, e) == 1)
break;
}
for (int i = 1; i < phin; i++)
if ((i * e) %phin== 1)
d=i;
printf("Enter message: ");
scanf("%d", &data);
cipher = powmod(data, e, n);
printf("encryption: %d\n", cipher);
decrypt = powmod(cipher, d, n);
printf("decryption: %d\n", decrypt);
return 0;
}
