//Hangman game made by Szocs Andras as a student project

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 
#include <ctime>
#include <Windows.h>
#include "Strings.h"
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

//Functions prototypes
void gotoXY (int x, int y);
string difficulty (vector <string> hard ,vector <string> medium, vector <string> easy,int &y,int &y1,int &y2);
void check(string riddle,char guess,char *griddle, int &x, int &y, int &count,int &x2,int y2);
void buildhm(int &x, int &y,int count);


int main(){
    //Coordinates 
    int x {4}; int y{6}; 
    int x1{22}; int y1{13};
    int x2{18}; int y2{14};
    
    int count {0}; 
    string riddle {};
    char guess {};
    
    cout<<"This is a hangman game made by Szocs Andras, have fun!"<<endl;
    
    //defing the riddle word with the function difficulty
    riddle = difficulty(hard ,medium, easy,y,y1,y2);
    
    //creating a blank char array for checking if the word  was guessed
    char *griddle = new char [riddle.size()];
   
   //Display the elements of the game
for(auto str : strhangman){
cout<<str<<endl;}
cout<<"    ";
cout<<endl<<"Word to guess : ";
for(int i {0}; i < riddle.size() ; i++){
    cout<<"_ ";
}
cout<<endl;
cout<<"Type your next guess :  "<<endl;
cout<<"Wrong characters : ";

//Check for user guessing characters in a loop and update the word and the hangman
do{
cin.clear();
cin.ignore();
gotoXY(x1,y1);
cin>>guess;
guess = tolower(guess); 
check(riddle,guess,griddle,x,y,count,x2,y2); }while(count != 7 && riddle != griddle);

//Display the result of the attempt to resolve the riddle
if(riddle == griddle){
    gotoXY(0,15);
    cout<<"Congratulations you won the game !"<<endl;} 
else{
      gotoXY(0,15);
      cout<<"The word was : "<<riddle<<"."<<endl;
      cout<<"The hangman has died, try one more time !"<<endl;}
    return 0;
}

//Move the cursor
void gotoXY (int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}

//Set the difficulty of the riddle word using vector and rand function
string difficulty (vector <string> hard ,vector <string> medium, vector <string> easy,int &y,int &y1,int &y2){
    int difficulty {}; int v {};
    srand((int)time(0));
    v = (rand() % 10);
	cout<<"Plese chose dificulty."<<endl
           <<"Press 1 for easy, 2 for medium or 3 for hard : ";
    do{
    cin>>difficulty;
    if(difficulty == 1){
        cout<<"You choose easy difficulty."<<endl;
        return easy.at(v);}
    else if(difficulty == 2){
         cout<<"You choose medium difficulty."<<endl;
         return medium.at(v);}
    else if(difficulty == 3){
         cout<<"You choose hard difficulty."<<endl;
         return hard.at(v);}
    else{
        cerr<<"Not a valid choise please enter 1,2 or 3."<<endl;
        y += 2; y1 += 2; y2 +=2;
        cin.clear();
        cin.ignore();}
    }while(difficulty != 1 && difficulty != 2 && difficulty != 3 ); 
}

//check the imput character of the user
void check(string riddle, char guess,char *griddle, int &x, int &y,int &count,int &x2,int y2){
    int check {0}; 
    for(int i {0}; i < riddle.size() + 1; i++){
        if(riddle[i] == guess){
            griddle[i]  = riddle [i];
            gotoXY((x+12)+ (i*2),y+6);
              cout<<guess;
                 check++;}}
        if(check == 0){
            buildhm(x,y,count);
            count++;
            gotoXY(x2,y2);
            cout<<guess<<",";
            x2+=2;
        }
}

//update the hangman for wrong characters
void buildhm(int &x ,int &y,int count){
    char sp {};
    switch(count){
        case 0 :
        {gotoXY(x,y);
        cout<<"0";
        break;}
        
        case 1 :
       { gotoXY(x-1,y+1);
        cout<<"/";
       break;}
        
        case 2 :
        {gotoXY(x,y+1);
        cout<<"|";
        break;}
        
        case 3 :
       { gotoXY(x+1,y+1);
        cout<<"\\";
       break;}
        
        case 4 :
       { gotoXY(x, y+2);
        cout<<"|";
       break;}
        
        case 5 :
        {gotoXY(x-1,y+3);
        cout<<"/";
        break;}
        
        default :
       { gotoXY(x+1, y+3);
        cout<<"\\";}
    }
}