// Program - Single Heap Game of Nim
// Coded BY - Kanhaiya Mishra,17 Oct 2017

import java.util.Scanner;
import java.lang.Math;
class Game
{
	public boolean check(int x, int y,int z)
	{
		if(x>y)
			{ 
			if(z==1)
				System.out.println("Please enter number less than available sticks");
			return false;
			}
		else if(x<y && (x==1||x==2||x==3||x==4))
			{return true;}
		else
			if(z==1)
				System.out.println("Please enter a valid number between 1,2,3,4");
			return false;
	}
	public boolean check(int x)
	{
		if(x<10)
			{System.out.println("Select atleast 10 Sticks for a fair Play :");
			return false;}
		else
			{return true;}
		
	}
	public void run()
	{
		int sticks=0,turn=0,value;
		Scanner input = new Scanner(System.in);
		System.out.println("Welcome to the Game of Nim");
		System.out.println("Enter the number of Sticks(Greater than or equal to 10 please)");
		
		while(true)
		{
			sticks = input.nextInt();
			if(check(sticks))
			{
				while(true)
				{
				System.out.println("Press 1 to play First or 2 for Computer :");
				turn=input.nextInt();
				if(turn==1|| turn==2)
					break;
				}
				break;
			}
			
		}
		while(sticks>1)
		{
			switch (turn)
			{
			case 1:
				System.out.println("Enter no of sticks to be removed... They should either be 1,2,3 or 4");
				value=input.nextInt();
				if(check(value,sticks,1))
				{
					sticks=sticks-value;
					System.out.println("Remaining sticks "+ sticks );
					turn=2;
				}
				
				break;
			case 2:
				value=(int) (1 + (Math.random() * (4 - 1)));
				if(check(value,sticks,2))
				{
					System.out.print("Computer chooses: ");
					System.out.println(value);
					sticks=sticks-value;
					System.out.println("Remaining sticks "+ sticks );
					turn=1;
				}
				break;
			default:
				break;
			}
			
			}
		if(sticks==1 && turn==1) 
			System.out.println("Lost this Match ! Just Try Again"); 
	      else
	    	  System.out.println("You Won ! Computer Lost");
		
	}		
}


class Nim {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Game game = new Game();
		game.run();
	}

}
