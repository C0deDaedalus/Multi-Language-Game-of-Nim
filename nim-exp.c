
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
              // statement/expression inside If() or else-if() are conditions.
              // In C Language, expressions evaluating to zero ie. 0 are considered as FALSE.
              // & expressions evaluating to any non-zero number is considered as TRUE.
            
              // So, if(0) , if(1+4-5) , if(NULL) are considered to be FALSE.
              // &   if(1) , if(3-2) , if(" ") , if(' ') , if(pi=3.14) are considered as TRUE. 
              // Assignment statements, Empty character & Empty String as a condition considered as TRUE.
    {
       // Statements to be executed when x is greater than y.
       
       printf("\n\t\t\tYou cannot pick sticks more than left ones\n\n");
       // printf function just prints statements on the STDOUT.
       // prototype & definition for scanf() & printf() functions can be found in stdio.h header file.
       // To view this file in Linux ---> /usr/include/stdio.h
       
       // Syntax --->  printf("format_specifier1,format_specifier2,.....",variable_or_expn1,variable_or_expn2,.....);
       // Format_specifier = %[flags][width][.precision][length]specifier
       // Understanding complete format is intermediate level task. Try it Yourself.
       
       // If successful, the total number of characters written is returned. On failure, a negative number is returned.       
       
       return(1);   // If x>y is true, then only return 1.
    }
    else if(x>4||x<1)  // else if part is executed if x>y OR x<1 is TRUE. Double pipe stands for Logical OR operation.
    {
       // statements to be executed when If condition goes FALSE and else-if condition goes TRUE.
        
       printf("\n\t\t\tYou can pick minimum 1 and maximum 4 sticks\n\n");
       // \n & \t are Escape Sequences.
       // Escape Sequence are sequence of characters that are translated by compiler to some specific charactes.
       // \ (backslash) itself is called Escape Character, & thus every escape sequence starts with a \ (backslash).
       // Every Escape Sequence corresponds to a HEX value in ASCII.
       // \n is used to print statements to " next line "
       // \t is used to print statements after a " tab space "
       
       return(1);
    }
    
   return(0);
   // function check_sticks(...) at the end returns 0. An integer value as decribed in function definition.
   // Usually return(0) means successful termination.
   // whereas anything else say return(1) or return(-1) represents Abnormal Termination.
} 

                  // void type stands for nothing to return or return something that has type unknown.
                  // Thus this function executes statements defined in it, but returns nothing at all.
void user_takes() // A function for how many matchsticks is picked by user.
{
    printf("\t\t\t\t\t\t    User Takes :   ");
     scanf("%3d",&user); // Tells program to take user input & store it in variable user
   
   // scanf() function is used to take STDIN = standard Input from User.
   // It's prototype & definition ;is defined in stdio.h header file.
   // syntax of scanf is - scanf("format_specifier1,format_specifier2,.....",&variable1,&variable2,.....");
   
   // Character & is called "Ampersand" and " &user " means at the memory Address named "user".
   // So, scanf("%3d",&user); means
   // take user input as an integer, convert it to 3-digit format & store in a memory location named as user.
   
   // No need for return(0) statement as return type of function is void. Have a look again.
}

int main()    // main() function = function called at program startup.
              // Execution starts from here and main() calls other function in program.
              // Return type is either int or void. See this - https://www.youtube.com/watch?v=c-9cdd3v3Tc   
{
   // In order to define a variable we need a data type & a storage class. Storage classes defines :
   // Where the variable would be stored - in memory or CPU registers.
   // What will be initial value of the variable.
   // What is scope of the variable - local or global (in which functions value of variable would be available.)
   // What is lifetime of the variable - how long would variable exist.
   // In C we have 4 storage classes - auto, static, register, extern.
   
   //  CLASS    |   STORAGE   |   INITIAL VALUE   |      SCOPE       |           LIFETIME
   // ----------|-------------|-------------------|------------------|----------------------------------------------
   //  auto     |   Memory    |   Garbage Value   |  LOCAL to Block  |   Till control is in the block.
   //  static   |   Memory    |     Zero = 0      |  LOCAL to Block  |   Value persists between different function calls.
   //  register |   CPU Reg.  |   Garbage Value   |  LOCAL to Block  |   Till control is in the block.
   //  extern   |   Memory    |     Zero = 0      |      GLOBAL      |   Till the termination of Program.
   //-----------|-------------|-------------------|------------------|----------------------------------------------

   // In C, variable has by-default "auto" storage class.
   // Variables defined inside main() are LOCAL untill storage class is defined to be "extern".
   
    int x;       // x is declared to be integer variable.
    char op;     // op is declared to be a character variable.
   
    printf("\n  ================================== Game of Nim =======================================\n\n");
    printf("\t\t\t\t Enter number of Sticks : ");   // Just printing the statements.
    
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
