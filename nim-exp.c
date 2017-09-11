
/* Statement beginning with a # are Preprocessor Directives that modifies our source
   code by macro expansions and conditional compilation. Here we have used include
   preprocessor that fetches the header files (containing necessary functions) and
   writes to source code. */

#include<stdio.h>
// stdio.h = Standard Input Output Header File. Handles all I/O functions in program execution.
// Contains prototype and function definition for functions such as printf() , scanf() ,
//   gets() , puts() , fopen() , fclose() , rewind() , sscanf() , sprintf() , remove() , fflush()

#include<stdlib.h>
// stdlib.h = Standard Library Header File.
// Contains functions to be used for system and memory tasks such as setenv() , getenv()
//        delay(), system() , malloc() , calloc() , free() , exit() , abort() , perror()

/* variables in C are declared using Data Types.
   Data Types - Primary (fundamental) = int , float , double , char , void.
   Data Types - Secondary(Derived) = Functions , Pointers , Arrays , Structures , Union , Enumeration
   Data Type tells -
                     1. what is type of variable/data to be used.
                          >  int corresponds to an integer, float to real number
                             char to a character and void simply represents nothing
                     2. how much size would that variable take up in memory.
                          >  int takes 2 or 4 bytes , long and float takes 4 bytes each
                             double takes 8 bytes and char is simply 1 byte reserved in memory.
                     3. how the data can be processed
                          >  such as Modular Division is allowed only for ints not for floats.
 */

// Local variables - defined inside a function. Scope limited to that function only.
// Global Variables - defined outside main() function and can be used by any function. 

int sticks,user,comp,turn;  // these four are defined as Global variables & are integer(whole number) type variables.

/*
   Functions are set of statements that perform a particular task.
   Functions in C language needs to define its prototype(Decleration). THen Function definition itself.
   
   Prototype Decleration --->  <Return_type> <function_name> (<data_type> <parameter> ,<data_type> <parameter> , .... );
                               Return type = data type of variable that function will return.
                               Function name = can be anything excluding C reserved keywords.
                               Parameters = variables that take values when function is called.
                               
   Function Definition -->  <Return_type> <function_name> (<data_type> <parameter> ,<data_type> <parameter> , .... )
                              {
                                 // statements to be executed on function call.
                              }
   Function Call --> <function_name> (<argument> , <argument> , . . . );
   
   Example : float area(float radius);     // Prototype Declaration
             float area(float radius)      // Function Definition
                  { float area=3.14*r*r; 
                    return(area);
                  }
             area(2.5);  // Function call
*/

                               // Function Prototype Declarations as well as definition
                               // Return type = integer
                               // Function name = check_sticks
int check_sticks(int x,int y)  // Parameters = x & y both ints.
{
    if(x>y)   // If-else condition construct. If is executed when x>y is TRUE.
    {
        printf("\n\t\t\tYou cannot pick sticks more than left ones\n\n");   return(1);
    }
    else if(x>4||x<1)  // else if part is executed if x>y is FALSE.
    {
        printf("\n\t\t\tYou can pick minimum 1 and maximum 4 sticks\n\n");  return(1);
    }
    return(0);
} 

void user_takes()
{
    printf("\t\t\t\t\t\t    User Takes :   ");
     scanf("%3d",&user);
}

int main()
{
    int x;
    char op;
    printf("\n  ================================== Game of Nim =======================================\n\n");
    printf("\t\t\t\t Enter number of Sticks : ");
    
    while(1)
    {
        if(scanf("%d",&x))
        {
            if(x>=10)
            { 
                sticks=x;   break;
            }
            else
            {
                printf("\t\tSelect atleast 10 Sticks for a fair Play : ");
            }
        }
        else
        {
            printf("Invalid Input : Please enter a number\n");
        }
    }

    printf("\n\t\tHow about I give you the first Shot\n\t\tPress 1 to play First or 2 for Computer : "); 
     scanf("%d",&turn);
   
    while(turn!=1&&turn!=2)
    {
        printf("\t\tPress 1 to play First or 2 for Computer : ");
         scanf("%d",&turn);
    }
    
    printf("\n\t---------------------------------------------------------------------\n\n");
    while(sticks>14)
    {
        printf("\t\tSticks Left : %3d",sticks);
        switch(turn)
        {
            case 2: // Computer's Turn
                    comp=rand()%5+1;
                    sticks-=comp;
                    printf("\t\tComputer Takes : %3d\n",comp);
                    turn=1;
                    break;
            case 1: // User'sTurn
                    printf("\t\t    User Takes :   ");
                     scanf("%3d",&user);
                    while(check_sticks(user,sticks))
                        user_takes();
                    sticks-=user;
                    turn=2;
                    break;
        }
    }
   
   while(sticks>1)
   {
        printf("\t\tSticks Left : %3d",sticks);
        switch(turn)
        {
            case 2: // Computer's Turn
                    comp=(sticks>6&&sticks<=10)?(sticks-6):(5-user);
                    sticks-=comp;
                    printf("\t\tComputer Takes : %3d\n",comp);
                    turn=1;
                    break;
            case 1: // User's Turn
                    printf("\t\t    User Takes :   ");
                     scanf("%3d",&user);
                    while(check_sticks(user,sticks))
                        user_takes();
                    sticks-=user;
                    turn=2;
                    break;
        }
   }
     
    printf("\n\n  ========================( "); 
    if(sticks==1&&turn==1) printf("Lost this Match ! Just Try Again"); 
      else                 printf("You Won ! Computer Lost");
    
    printf(" )==========================\n\n");  
    return(0);
}
