#include<stdio.h>
#include<string.h>
#include<ctype.h>		//*
 
char input[10];                  //7 lines
int i,error;
void E();
void T();
void Eprime();
void Tprime();
void F(); 

main()
{
	i=0;						//8 lines
	error=0;
        printf("Enter an arithmetic expression   :  "); // Eg: a+a*a
        gets(input);
        E();
        if(strlen(input)==i&&error==0)
               printf("\nAccepted..!!!\n");
         else printf("\nRejected..!!!\n");
}

void E()
{
     T();
     Eprime();
}
void Eprime()
{
     if(input[i]=='+')
     {
     	i++;
     	T();
     	Eprime();
     }
}
void T()
{
     F();
     Tprime();
}
void Tprime()
{
     if(input[i]=='*')
     {
            i++;
            F();
            Tprime();
     }
}
void F()
{
     if(isalnum(input[i]))i++;
     else if(input[i]=='(')
     {
          i++;
          E();
          if(input[i]==')')
          i++;
          else error=1;
       }
       else error=1;
}
           
           
/*OUTPUT
ruchika@ubuntu:~/Desktop$ gcc rdp.c
rdp.c:12:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
rdp.c: In function ‘main’:
rdp.c:17:9: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
         gets(input);
         ^
/tmp/ccBooLfR.o: In function `main':
rdp.c:(.text+0x32): warning: the `gets' function is dangerous and should not be used.
ruchika@ubuntu:~/Desktop$ ./a.out
Enter an arithmetic expression   :  aAAAAAAAAAAAAAAAAAA^[[3~^[[3~^[[3~^[[3~^[[3~                                   

Rejected..!!!
ruchika@ubuntu:~/Desktop$ ./a.out
Enter an arithmetic expression   :  a+b*c

Accepted..!!!
ruchika@ubuntu:~/Desktop$ ./a.out
Enter an arithmetic expression   :  (a=b)*c 

Rejected..!!!
ruchika@ubuntu:~/Desktop$ (a+b)*c

