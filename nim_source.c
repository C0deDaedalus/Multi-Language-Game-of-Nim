
// Program - Single Heap Game of Nim
// Coded BY - Amit Kumar, 22 May 2017

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sticks,user,comp,turn;

int check_sticks(int x,int y)
{
    if(x>y)
    {
        printf("\n\t\t\tYou cannot pick sticks more than left ones\n\n");   return(1);
    }
    else if(x>4||x<1)
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
    srand(time(NULL));
    
    int x; char op;
    printf("\n  ================================== Game of Nim =======================================\n\n");
    printf("\t\t\t\t Enter number of Sticks : ");
    //Please handle the exception let suppose someone enter the string value then you have to show a error massege 
    while(1)
    {
        if(scanf("%d",&x))
        {
            if(x>=10)    {   sticks=x;   break;   }
            else         {   printf("\t\tSelect atleast 10 Sticks for a fair Play : ");  }
        }
        else             {   printf("Invalid Input : Please enter a number\n");   }
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
                    comp=rand()%4+1;
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
                    comp=(sticks>6 && sticks<=10)?(sticks-6):(5-user);
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
