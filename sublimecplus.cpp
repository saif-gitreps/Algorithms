#include<bits/stdc++.h>
using namespace std;

class Board{
public:
	char board[10];
	void input(){
		for(int i=1;i<=9;i++){
			cin>>board[i];
		}
	}
	void display(){
		cout<<"-----------{BOARD}----------\n";
		cout<<"\n";
		for(int i=1;i<=9;i++){
			cout<<" [ "<<board[i]<<" ] ";
			cout<<" "<<i<<".";
			if(i%3==0){
				cout<<"\n";
				cout<<"\n";
			}
		}
		cout<<"-----------{BOARD}----------\n";
	}
	void Available(){
		cout<<"\n";
		for(int i=1;i<=9;i++){
			if(board[i]=='X' || board[i]=='O'){
				if(i==9){
					cout<<"[!]";
				}
				else{
					cout<<"[!]-";
				}
			}
			else{
				if(i==9){
					cout<<"["<<i<<"]";	
				}
				else{
					cout<<"["<<i<<"]-";
				}
			}
		}
		cout<<"\n";
		cout<<"-----------------------------------\n";
		cout<<"\n";
	}
};

class Judge : public Board{
public:
	char win_check(){
		//case 1 : same row.
		if(board[1]=='X' && board[2]=='X' && board[3]=='X'){return 'X';}
		if(board[1]=='O' && board[2]=='O' && board[3]=='O'){return 'O';}
		if(board[4]=='X' && board[5]=='X' && board[6]=='X'){return 'X';}
		if(board[4]=='O' && board[5]=='O' && board[6]=='O'){return 'O';}
		if(board[7]=='X' && board[8]=='X' && board[9]=='X'){return 'X';}		
		if(board[7]=='O' && board[8]=='O' && board[9]=='O'){return 'O';}
		//case 2 : same column.
		if(board[1]=='X' && board[4]=='X' && board[7]=='X'){return 'X';}
		if(board[1]=='O' && board[4]=='O' && board[7]=='O'){return 'O';}
		if(board[2]=='X' && board[5]=='X' && board[8]=='X'){return 'X';}
		if(board[2]=='O' && board[5]=='O' && board[8]=='O'){return 'O';}
		if(board[3]=='X' && board[6]=='X' && board[9]=='X'){return 'X';}		
		if(board[3]=='O' && board[6]=='O' && board[9]=='O'){return 'O';}
		
		//case 3 : the diagonals.
		if(board[1]=='X' && board[5]=='X' && board[9]=='X'){return 'X';}
		if(board[1]=='O' && board[5]=='O' && board[9]=='O'){return 'O';}
		if(board[3]=='X' && board[5]=='X' && board[7]=='X'){return 'X';}		
		if(board[3]=='O' && board[5]=='O' && board[7]=='O'){return 'O';}
		return 'N';
	}
	bool winner(){
		
		char win = win_check();
		
		if(win=='X' || win=='O'){
			return true;
		}
		return false;
	}

};

class Player : public Judge{
public:
	void player_chance(){
		
		char choice,defaul;

		while((true)){
			
			cout<<"CHOOSE X OR O: \n";
			
			cin>>choice;
			
			if(choice=='X'){
				defaul='O';
				break;
			}
			else if(choice=='O'){
				defaul='X';
				break;
			}
		}
		cout<<"PLAYER-1 GETS "<<choice<<" MEANWHILE PLAYER-2 GETS "<<defaul<<"\n";
		for(int i=1;i<=9;i++){
			display();
		
			int position;

			if(i%2!=0){
				cout<<"PLAYER |"<<choice<<"| CHOOSE AN AVAILABLE POSITON FROM BELOW.\n";
				
				Available();
				
				cin>>position;
				
				if(position<1 && position>9){
					cout<<"PLEASE ENTER A VALID POSITION\n";
					Available();
					i--;
					system("cls");
					continue;
				}
				if(board[position]=='X' || board[position]=='O'){
					cout<<"CURRENT POSITION IS TAKEN, CHOOSE ANOTHER.\n";
					Available();
					i--;
					system("cls");
					continue;
				}
				else{
					board[position] = choice;
				}
			}

			else{
				cout<<"PLAYER |"<<defaul<<"| CHOOSE AN AVAILABLE POSITON FROM BELOW.\n";
				
				Available();
				
				cin>>position;
				
				if(position<1 && position>9){
					Available();
					cout<<"PLEASE ENTER A VALID POSITION\n";
					i--;
					system("cls");
					continue;
				}
				if(board[position]=='X' || board[position]=='O'){
					cout<<"CURRENT POSITION IS TAKEN, CHOOSE ANOTHER.\n";
					Available();
					i--;
					system("cls");
					continue;
				}
				else{
					board[position] = defaul;
				}

			}
			if(winner()){
				
				cout<<"CONGRATS PLAYER "<<win_check()<<" WINS THE GAME!\n";
				
				display(); 
				
				break;
			}
			system("cls");
		}
	}
};

class TicTac: public Player{
public:
	void game_on(){
		
		int yes;
		
		while(true){
			cout<<"------------------------\n";
			cout<<"START A GAME OF TicTac ? \n";
			cout<<"ENTER 1 : YES\n";
			cout<<"ENTER 0 : NO\n";
			cout<<"------------------------\n";
			cin>>yes;
			if(!yes){ 
				cout<<"GG WELL PLAYED.\n";
				break;
			}
			
			player_chance();
		}
	}
};

int main(){
	TicTac s;
	s.game_on();

}