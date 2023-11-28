#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int IsPrime(int n)/*function to check if a number is prime*/
{
    if (!(n % 2))/*if the number is even return 0*/
    {
        return 0;
    }
    for (int i = 3; i <= sqrt(n); i += 2){
            if (!(n % i))
                return 0;
        }
    return 1;
}
long long int mirror(long long int n){
    long long int result=0;
    int tmp;
    while(n>0){
        tmp=(n%10);
        result= 10*result+tmp;
        n/=10;
    }
    return result;
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("The programm must be called as ./mirror low high\n");
        return 1;
    }
    long long int low = atoll(argv[1]);
    long long int high = atoll(argv[2]);
    if (high < low)
        return 1;
    if (low < 1 || high > 1e+15)
        return 1;
    long long int i;
    long long int sum=0;
    for (i = (ceil(sqrt(low))); i <= (floor(sqrt(high))); i++)
    {
        if(IsPrime(i) && (sqrt(mirror(i*i))==(int)(sqrt(mirror(i*i))) && IsPrime(mirror(sqrt(i*i)))) && mirror(i*i)!=i*i){
            sum+=i*i;
        }
    }
    printf("%lld\n",sum);
}
