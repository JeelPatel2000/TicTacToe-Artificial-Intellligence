/*
       Tic-Tac-Toe Game Based on Artificial Intelligence

       Hello this is the tic-tac-toe game which works on AI system

       Developed By :- Jeel Patel

*/

#include <iostream.h>
#include <conio.h>
#include <process.h>

//using namespace std;

//*************************************//
// Functions to be used in the program //
//*************************************//

void display(char [3][3]);    // To display the game board                                       // Done
int get_best_move_for_ai(char [3][3],char); // To get the bes possible move for AI
int check_winner(char [3][3],char); // To find the winner										// Done
int verify_input(char [3][3],int); // To verify the user input									// Done
void get_user_input(char [3][3],char player);  // To get input from user						// Done
int convert(int,int);		// To convert row and coloumn into a single digit					// Done
void place_move(char [3][3],int,char);  // To place the move 									// Done
int get_score(char [3][3],char);																// Done
void exchange_player(char &player);																// Done



//******** Main Function *********//
int main()
{

	char box[3][3],player='x';
	int move,ctr=0,score=-99,i,j;

	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	box[i][j]=' ';

	display(box);

	do
	{
		get_user_input(box,player);
		display(box);
		score=get_score(box,player);
		if(score!=-99)
		  break;
		exchange_player(player);
		move=get_best_move_for_ai(box,player);
		place_move(box,move,player);
		display(box);
		score=get_score(box,player);
		if(score!=-99)
		  break;
		exchange_player(player);
		ctr++;
	}while(ctr<9);

	score=check_winner(box,player);

	if(score==1)
	 cout<<"\n\nHuman wins !";
	else if(score==2)
		cout<<"\n\nAI wins !";
	else cout<<"Game Ties !";

	getch();

	char choice;
	cout<<"\nWant to play again (Y/N) : ";
	cin>>choice;
	if(choice=='y'||choice=='Y')
	  main();

	return 0;
}


// Function to Display the game board
void display(char box[3][3])
{
 system("cls");
 int i,j;

  for(j=0;j<3;j++)
  {
     cout<<"-------------\n";
     for(i=0;i<3;i++)
     {
       cout<<"| "<<box[j][i]<<" ";
     }
     cout<<"|\n";
  }

	cout<<"-------------\n";

}


// Function to Verify the user input
int verify_input(char box[3][3],int num)
{
  int c,r;           //   Note here the number index will start from 0 till 8
  c=(num-1)%3;       //   so we have to do (num-1)
  r=(num-1)/3;

  if(box[r][c]!=' ')
   return 0;
  else return 1;

}


// Function to take input from user
void get_user_input(char box[3][3],char player)
{
int number;

	do{
		 cout<<"\n\nHuman your Turn , Enter your choice : ";
		 cin>>number;
	}while(verify_input(box,number)==0);

	place_move(box,number,player);
}


// Function for finding the winner
int check_winner(char box[3][3],char player)
{
int i;
char opponent;

	if(player=='x')
	   opponent='o';
	else opponent='x';

	// checking the winner in the vertical lines

	for(i=0;i<3;i++)
	{
	 if(box[0][i]==box[1][i]&&box[1][i]==box[2][i])
	 {
		if(box[0][i]=='x')
		  return 1;
		else if(box[0][i]=='o')
		  return 2;
	 }
	}

	// checking the winner in the horizontal lines

	for(i=0;i<3;i++)
	{
	 if(box[i][0]==box[i][1]&&box[i][1]==box[i][2])
	 {
		if(box[i][0]=='x')
		  return 1;
		else if(box[i][0]=='o')
		  return 2;
	 }

	}

	// checking the winner diagonally

	if(box[0][0]==box[1][1]&&box[1][1]==box[2][2])
	{
		if(box[0][0]=='x')
	  return 1;
	else if(box[0][0]=='o')
		return 2;

	}
	if(box[0][2]==box[1][1]&&box[1][1]==box[2][0])
	{
		if(box[0][2]=='x')
	  return 1;
	else if(box[0][2]=='o')
		return 2;
	}

	for(i=0;i<3;i++)
	{
	 for(int j=0;j<3;j++)
	  if(box[i][j]==' ')
	  {
	   return -99;
	  }
	}

  return 0;  // Returns 0 if no cell of the box is left empty----therefore the game is tie!!
}



// Function to convert row and coloumn numbr into a single digit
int convert(int row,int coloumn)
{
  int number;

  number=(row*3)+(coloumn%3)+1;

  return number;
}



//********Function to place the move ************//
void place_move(char box[3][3],int move,char player)
{
  int c,r;           //   Note here the number index will start from 0 till 8
  c=(move-1)%3;       //   so we have to do (num-1)
  r=(move-1)/3;

  box[r][c]=player;  // Placing the move

}



//*********** Function which calculates and returns the score ***********//
int get_score(char box[3][3],char player)
{
  int i=0,j=0;
  char opponent;

  if(player=='x')
  {
   opponent='o';
  }
  else opponent='x';


  for(i=0;i<3;i++)
  {
    if(box[i][0]==box[i][1]&&box[i][1]==box[i][2])
    {
	if(box[i][0]==player)
	 return	10;
	else if(box[i][0]==opponent)
	 return -10;
    }
  }

  for(i=0;i<3;i++)
  {
    if(box[0][i]==box[1][i]&&box[1][i]==box[2][i])
    {
	if(box[0][i]==player)
	 return	10;
	else if(box[0][i]==opponent)
	 return -10;
    }
  }


   if(box[0][0]==box[1][1]&&box[1][1]==box[2][2])
   {
	     if(box[0][0]==player)
		 return	10;
	else if(box[0][0]==opponent)
	    return -10;
   }

   if(box[0][2]==box[1][1]&&box[1][1]==box[2][0])
   {
	if(box[0][2]==player)
		 return	10;
	else if(box[0][2]==opponent)
		return -10;
   }

   for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    {
     if(box[i][j]==' ')
      return -99;
    }
   }

 return 0;
}



//********** Function to excange the players ************//
void exchange_player(char &player)
{
 if(player=='x')
  player='o';
 else player='x';
}



//********** Function to make AI play the game ************//
int get_best_move_for_ai(char box[3][3],char player)
{
   int i=0,j=0;

   if(box[1][1]==' ')
    return convert(1,1);

   for(i=0;i<3;i++)
   {
    if(box[i][2]==player&&box[i][1]==player&&box[i][0]==' ')
      return convert(i,0);
   }

   for(i=0;i<3;i++)
   {
    if(box[i][0]==player&&box[i][1]==player&&box[i][2]==' ')
      return convert(i,2);
   }

   for(i=0;i<3;i++)
   {
    if(box[i][2]==player&&box[i][0]==player&&box[i][1]==' ')
      return convert(i,1);
   }

   for(i=0;i<3;i++)
   {
    if(box[0][i]==player&&box[1][i]==player&&box[2][i]==' ')
      return convert(2,i);
   }

   for(i=0;i<3;i++)
   {
    if(box[2][i]==player&&box[1][i]==player&&box[0][i]==' ')
      return convert(0,i);
   }

   for(i=0;i<3;i++)
   {
    if(box[0][i]==player&&box[2][i]==player&&box[1][i]==' ')
      return convert(1,i);
   }

   if(box[0][0]==player&&box[1][1]==player&&box[2][2]==' ')
     return convert(2,2);
   if(box[2][2]==player&&box[1][1]==player&&box[1][1]==' ')
     return convert(1,1);
   if(box[0][2]==player&&box[1][1]==player&&box[2][0]==' ')
     return convert(2,0);
   if(box[2][0]==player&&box[1][1]==player&&box[0][2]==' ')
     return convert(0,2);

   if(box[0][0]==player&&box[2][2]==player&&box[1][1]==' ')
     return convert(1,1);
   if(box[0][2]==player&&box[2][0]==player&&box[1][1]==' ')
     return convert(1,1);
   //*************************************************************//
   //*-----------------------------------------------------------*//
   //*************************************************************//
   char opponent;

   if(player=='x')
    opponent='o';
   else opponent='x';

   if(box[1][1]==' ')
    return convert(1,1);

   for(i=0;i<3;i++)
   {
    if(box[i][2]==opponent&&box[i][1]==opponent&&box[i][0]==' ')
      return convert(i,0);
   }

   for(i=0;i<3;i++)
   {
    if(box[i][0]==opponent&&box[i][1]==opponent&&box[i][2]==' ')
      return convert(i,2);
   }

   for(i=0;i<3;i++)
   {
    if(box[i][2]==opponent&&box[i][0]==opponent&&box[i][1]==' ')
      return convert(i,1);
   }

   for(i=0;i<3;i++)
   {
    if(box[0][i]==opponent&&box[1][i]==opponent&&box[2][i]==' ')
      return convert(2,i);
   }

   for(i=0;i<3;i++)
   {
    if(box[2][i]==opponent&&box[1][i]==opponent&&box[0][i]==' ')
      return convert(0,i);
   }

   for(i=0;i<3;i++)
   {
    if(box[0][i]==opponent&&box[2][i]==opponent&&box[1][i]==' ')
      return convert(1,i);
   }

   if(box[0][0]==opponent&&box[1][1]==opponent&&box[2][2]==' ')
     return convert(2,2);
   if(box[2][2]==opponent&&box[1][1]==opponent&&box[1][1]==' ')
     return convert(1,1);
   if(box[0][2]==opponent&&box[1][1]==opponent&&box[2][0]==' ')
     return convert(2,0);
   if(box[2][0]==opponent&&box[1][1]==opponent&&box[0][2]==' ')
     return convert(0,2);

   if(box[0][0]==opponent&&box[2][2]==opponent&&box[1][1]==' ')
     return convert(1,1);
   if(box[0][2]==opponent&&box[2][0]==opponent&&box[1][1]==' ')
     return convert(1,1);



	int ctr=0,scoreSet[9],movesSet[9],move,init_score=-99,n=0,m=0,size=0;
	char temp_box[3][3],temp_player=player;

	// Initializing the score array by -100
	for(n=0;n<9;n++)
	{
	  scoreSet[n]=-99;
	}

	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	  temp_box[i][j]=box[i][j];

	for(i=0;i<3;i++)
	{

		for(j=0;j<3;j++)
		{

			temp_player=player;
			init_score=-99;

			if(temp_box[i][j]==' ')
			{
				temp_box[i][j]=temp_player;
				movesSet[size]=convert(i,j);
				exchange_player(temp_player);
				do
				{
					move=get_best_move_for_ai(temp_box,temp_player);
					place_move(temp_box,move,temp_player);
					init_score=get_score(temp_box,player);
					scoreSet[size]=init_score;
					exchange_player(temp_player);

				}while(init_score==-99&&ctr<9);

				size++;
				ctr=0;

				// Re-assigning the box to temp_box
				for(n=0;n<3;n++)
				for(m=0;m<3;m++)
				   temp_box[n][m]=box[n][m];
			}

		}

    }

		int best_score=scoreSet[0],best_move=movesSet[0];

		for(n=1;n<size;n++)
		{
			if(best_score<scoreSet[n])
			{
				best_move=movesSet[n];
				best_score=scoreSet[n];
			}

		}


	return best_move;

}





