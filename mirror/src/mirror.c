#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int IsPrime(int n)/*function to check if a number n is prime*/
{
    if (!(n % 2))/*if the number is even return 0*/
    {
        return 0;
    }
    for (int i = 3; i <= sqrt(n); i += 2){/*the loops check efficiently if the number is divided by any potential fatcors other than 2 and if yes it returns 0*/
            if (!(n % i))
                return 0;
        }
    return 1;/*if the program reaches this line it means he number is prime*/
}
long long int mirror(long long int n){/*this function checks if a number n is mirror*/
    long long int result=0;
    int tmp;
    while(n>0){/*for every digit of n we do the following steps:*/
        tmp=(n%10);/*we save the last digit in this variable*/
        result= 10*result+tmp;/*we move the existing result one position to the left by multiplying it with 10 and we add the last digit*/
        n/=10;/*we divide n with 10 and as it is saved as an integer we eliminate its last digit*/
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
    for (i = (ceil(sqrt(low))); i <= (floor(sqrt(high))); i++)/*we efficiently check the potential numbers that may be specular first squares*/
    {
        if(IsPrime(i) && (sqrt(mirror(i*i))==(int)(sqrt(mirror(i*i))) && IsPrime(mirror(sqrt(i*i)))) && mirror(i*i)!=i*i){/*this is the condition for a number n=i*i to be a specular first square*/
            sum+=i*i;/*we calculate the sum of the spectacular first squares*/
        }
    }
    printf("%lld\n",sum);
}
