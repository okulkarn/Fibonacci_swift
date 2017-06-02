#include <stdio.h>
#include <stdlib.h>

/*  I have made assumptions that 0 is divisible by all numbers.
    length of fibo must be less than the value of long int.
    I have allowed the integers to overflow too as negative + positive give + and -*/

int f(int n){
    static int i = 0;
    int c, first = 0, second = 1, next = 0;
    for ( c = 0 ; c < n ; c++ )
    {
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      if(i==0)
        printf("%d  ",next);
    }
    i = i + 1;
    return next;
}

int prime(int n){
    int i,flag=0;
    for(i=2; i<=n/2; ++i)
    {
        // condition for nonprime number
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    return flag;
}

int main()
{
    int n,k,fibo;

    printf("Enter the number of terms\n");
    //n = length of the series
    scanf("%d",&n);

    printf("First %d terms of Fibonacci series are :-\n",n);
    //f(n) = function that computes the last element of the fibonacci series and the length of the series
    fibo = f(n);
    printf("\n%d\n",fibo);

    //conditions to check and print accordingly
    if(fibo%15 == 0)
        printf("FizzBuzz");
    else if(fibo%3 == 0)
        printf("Buzz");
    else if(fibo%5 == 0)
        printf("Fizz");
    else if(prime(fibo) == 0)
        printf("BuzzFizz");
    else
        printf("%d",fibo);

    return 0;
}

