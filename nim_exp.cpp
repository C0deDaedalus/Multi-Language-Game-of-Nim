/*
Lines beginning with a hash sign (#) are directives for the preprocessor. 
They are not regular code lines with expressions but indications for the 
compiler's preprocessor.In this case the directive #include <iostream> 
tells the preprocessor to include the iostream standard file. This specific 
file (iostream) includes the declarations of the basic standard input-output 
library in C++, and it is included because its functionality is going to be used 
later in the program.
*/

#include <iostream>

/*cstdlib is the header of the general purpose standard
library of C++ programming language which includes functions involving memory
allocation, process control, conversions and others.Here we are inculding it to 
utilize the rand() and srand() functions */ 

#include <cstdlib>

/*
This header file contains definitions of functions to get and manipulate date and time information.
*/

#include <ctime>

/*namespace is a container for a set of identifiers,in simple words it is a
group which can have functions  and data which we can use in our program.Here
std is an abbreviation of standard. std is the standard namespace. cout, cin and a lot
of other things are defined in it. (This means that one way to call them is by
using std::cout and std::cin.) */

using namespace std;

/*
class is one of the basic concept of OOP(object oriented programming) and one of the most allluring feature of c++.
It is a user defined data type and allows you to create a data type which which can store different type of data 
elements like int ,float etc.There are mainly two members of class : data member and member functions which are responsible 
for manipulation of these data members. 
*/

class Nim
{
	//data members which are private
	int tot_marbles;
	int left_marbles;
	char player;


	//public is an access specifier which specifies decides how the members of class will be treated outside the class
	//by default all the members of class are treated as private i.e. members of class can not be accessed from outside the class
	//protected is another access specifier which holds same properties as a private but while inheritance it allows the 
	//protected members to be inherited in child class  
	public:
		/*parameterized constructor :constructor is a special function which accepts parameters whose name is same as that of class and it is 
		  responsible for initializing the data members of class for an object 
		  
		*/
		  //signature of member functions

		Nim(int t,char c);
		void comp_move();
		void next_turn();
		void user_move();
};

//constructor definition
Nim :: Nim(int t,char c)
{
	tot_marbles=t;
	left_marbles=t;
	player=c;
}

//definition of member function outside the class
void Nim :: comp_move()
{
	int rand_num,marbles_to_be_chosen;
	/*
	srand() gives to the rand() function a new "seed", which is a starting point
    (usually random numbers are calculated by taking the previous number (or the seed))

    You could also pass another different seed from time(0), for example:
            srand(3); 
    Numbers would be generated according to the seed 3, hence numbers would be the same every time
    time(0) returns the number of seconds since the UNIX epoch.
	Because every time you make your program start, the number of second will be different (because the time passes)
    and therefore also the seed and, consequently, the random numbers generated will be different every time
    unless you start the program at the same time every time, which is improbable.

	*/
	srand(time(0));
	/* 
    (?:) is a ternary operator.As you can see in the above syntax,
	ternary operator includes three parts. First part (before ?) includes
	conditional expression that returns boolean value true or false. Second part
	(after ? and before :) contains a statement which will be returned if the
	conditional expression in the first part evalutes to true. The third part
	includes another statement which will be returned if the conditional
	expression returns false.     */
	marbles_to_be_chosen=(left_marbles>5?(rand()%4)+1:left_marbles-1);
	if(left_marbles>1)
	cout<<"\t\t\t\tMarbles left :"<<left_marbles;
 	if(left_marbles<10)
 	{cout<<"\t";}
 	cout<<"\t\tComputer Picks :"<<marbles_to_be_chosen;
	left_marbles=left_marbles-marbles_to_be_chosen;
	player='u';
	//cout<<"calling from comp move";
	next_turn();//invoking one member function from another member function which is called nesting of member functions
}

//definition of member function outside the class
void Nim :: user_move()
{	int user_input;
	if(left_marbles>1)
	  cout<<"\n\t\t\t\tMarbles left :"<<left_marbles;
	if(left_marbles<10)
 	{cout<<"\t";}	
	cout<<"\t\tUser Picks :";
	cin>>user_input;
	if(user_input>0 && user_input<5 && user_input<=left_marbles)
	{
	  left_marbles=left_marbles-user_input;
    }
	else
	{
	  cout<<"\t\t\t\tInput is not as per conditions,Please re-enter";	
	  user_move();
	}
	player='c';
	//cout<<"calling from user move";
	next_turn();//invoking one member function from another member function which is called nesting of member functions
}

//definition of member function outside the class
void Nim :: next_turn()
{
	if(left_marbles>1)
	{
		if(player=='c'||player=='C')
		{
			//"COMPUTER'S TURN"
			comp_move();
		}
		else
		{
			//"USER'S TURN"
			user_move();
		}
	}
	else
	{
		if(left_marbles==1)
		{	if(player=='c'||player=='C')
			{
				cout<<"\n\t\t\t\t\t\tCONGRATS!YOU WIN!!";
			}
			else
			{
				cout<<"\n\t\t\t\t\t\tYOU LOST!";
			}
		}
		else
		{
			if(left_marbles==0)
			{	if(player=='u'||player=='U')
				{
					cout<<"\n\t\t\t\t\t\tCONGRATS!YOU WIN!!";
				}
				else
				{
					cout<<"\n\t\t\t\tYOU LOST!";
				}
			}
		}
		
	}	
}

int main()
{
	char first_player,option='y';
	int total;
	cout<<"\t\t\t\t********************************WELCOME TO THE GAME OF NIM************************************"<<endl;
	cout<<"\t\t\t\tInstructions:\n\t\t\t\t\t1)Choose marbles inbetween 1 and 4.\n\t\t\t\t\t2)They should be less than available no. of marbles."<<endl;
	cout<<"\n\t\t\t\t                            ****BEGIN THE GAME.GOOD LUCK!****"<<endl;
	/*     
    The do...while loop is a variant of the while loop with one
	important difference. The body of do...while loop is executed once before the
	test expression is checked.The codes inside the body of loop is executed at
	least once. Then, only the test expression is checked.     
	*/    
	do
	{		
		do
		{
			cout<<"\t\t\t\tEnter the total no. of marbles (min:10)";
			cin>>total;
			if (total<10)
				cout<<"\t\t\t\tPlease enter marbles>=10 for fair game"<<endl;
		}while(total<10);
		cout<<endl<<"\t\t\t\tEnter the first player(Computer->c,User->u)";
		cin>>first_player;
		/*
		Here,we are creating a variable of class type that means each variable of class type gets a copy of 
		data members of the class and can set value of those data members by calling  member functions which
	    are responsible for the manipulation of data members.This variable of class type is called as an object 
	    of class or an instance of class.
		*/
		while(first_player!='c' && first_player!='u')
		{
			cout<<"\t\t\t\tPlease enter c(computer) or u(user) for choosing first player";
			cout<<endl<<"\t\t\t\tEnter the first player(Computer->c,User->u)";
			cin>>first_player;
		}
		Nim n(total,first_player);
		n.next_turn();
		//invoking the member function of class with the help of an object (n) and dot operator(.).
		cout<<endl<<"\t\t\t\tDo you want to play again(for yes press y ,for exit press any char)";
		cin>>option;
		
	} while (option=='y'||option=='Y');
	return 0;
}
