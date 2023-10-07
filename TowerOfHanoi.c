#include<stdio.h>
#include<stdlib.h>
//TOWER OF HANOI
//here the source is A,auxillary is B and the destination is C. Bigger valued disk can never be put on the
//smaller valued disk
void hanoi(int num,char sor,char dest,char aux)
{
    if(num==0||num<0)
    {
       printf("Invalid input");
    }
    else if(num==1)
    {
        printf("Move the %d from %c to %c.\n",num,sor,dest);
    }
    else{
        hanoi(num-1,sor,aux,dest);
        printf("Move the %d from %c to %c.\n",num,sor,dest);
        hanoi(num-1,aux,dest,sor);
    }
    
}

int main(){
    int line;
    char sor='A',aux='B',dest='C';

    printf("Enter the no of line:");
    scanf("%d",&line);
    hanoi(line,sor,dest,aux);

    
    return 0;
}