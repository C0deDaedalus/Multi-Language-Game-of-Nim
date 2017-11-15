#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Nim
{
	
	int tot_marbles;
	int left_marbles;
	char player;

	public:
		Nim(int t,char c);
		void comp_move();
		void next_turn();
		void user_move();
};

Nim :: Nim(int t,char c)
{
	tot_marbles=t;
	left_marbles=t;
	player=c;
}

void Nim :: comp_move()
{
	int rand_num,marbles_to_be_chosen;
	srand(time(0));
	marbles_to_be_chosen=(left_marbles>5?(rand()%4)+1:left_marbles-1);
	if(left_marbles>1)
	cout<<"\t\t\t\tMarbles left :"<<left_marbles;
 	if(left_marbles<10)
 	{cout<<"\t";}
 	cout<<"\t\tComputer Picks :"<<marbles_to_be_chosen;
	left_marbles=left_marbles-marbles_to_be_chosen;
	player='u';
	//cout<<"calling from comp move";
	next_turn();

}

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
	next_turn();
}

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
		while(first_player!='c' && first_player!='u')
		{
			cout<<"\t\t\t\tPlease enter c(computer) or u(user) for choosing first player";
			cout<<endl<<"\t\t\t\tEnter the first player(Computer->c,User->u)";
			cin>>first_player;
		}
		Nim n(total,first_player);
		n.next_turn();
		cout<<endl<<"\t\t\t\tDo you want to play again(for yes press y ,for exit press any char)";
		cin>>option;
		
	} while (option=='y'||option=='Y');
	return 0;
}
