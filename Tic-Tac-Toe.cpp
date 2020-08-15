#include<bits/stdc++.h>
using namespace std;
//Winning Conditions of the Boards (0-8) are the positions of the boards
int win[8][3]={{0,1,2}//First Row
              ,{3,4,5}//Second Row
              ,{6,7,8}//Third Row
              ,{0,3,6}//First Column
              ,{1,4,7}//Second Column
              ,{2,5,8}//Third Column
              ,{0,4,8}//Left Diagonal
              ,{2,4,6}};//Right Diagonal
bool ifvalid(char tic[9],char ch)// Check of each character i.e. 'X' or 'O'
{
    for(int i=0;i<8;i++)
    {
        if(tic[win[i][0]]==ch and tic[win[i][1]]==ch and tic[win[i][2]] == ch)
        {
            //if it matches the 3-pointer 
            //i.e. it lines up in row,column or diagonally
            return true;
        }
    }
    return false;//Otherwise
}
char validity(char tic[9])
{
    int Oc=0;//"O"  Counter
    int Xc=0;// "X" Counter
    int i;
    for(i=0;i<9;i++)
    {
        if(tic[i] == 'X')
        {
            Xc+=1;//Increment the X-Counter
        }
        else if(tic[i] == 'O')
        {
            Oc+=1;//Increment the O-Counter
        }
    }
    cout<<Xc<<" "<<Oc<<endl;
    if(Oc > Xc)
    {
        return 'I';
    }
    if(ifvalid(tic,'O')==true and Xc==Oc)//If Player 2 Wins and other valid condition
    {
        if(ifvalid(tic,'X')==true)//Player 1 too wins
        {
                return 'I';//Invalid Inputs as both cannot win at the same time
                
        }
        return 'O';//So We Confirm that 'O' wins
    }
    if(ifvalid(tic,'X')==true and Xc==Oc+1)//Player 1 wins and the other valid condition
    {
        if(ifvalid(tic,'O')==true)//Player 2 wins too
           return 'I';//Both Players cannot win at the same time so invalid inputs
        return 'X';//We confirm that 'X' wins
    }
    return 'D';//No Player wins i.e results in a draw
}
int main()
{
    int t,i;
    char k;
    char tic[9];
    string s1,s2;
    cout<<"Enter First Player's Name"<<endl;//Player 1
    cin>>s1;
    cout<<"Enter Second Players's Name"<<endl;//Player 2
    cin>>s2;
    cout<<"Enter Xs and Os in Order"<<endl;//Inputs of the Grid
    for(i=0;i<9;i++)
    {
        cin>>tic[i];//Input
    }
    k=validity(tic);
    if(k == 'X')
    {
        cout<<s1<<" wins!!!!"<<endl;//player 1 wins
    }
    else if(k== 'O')
    {
        cout<<s2<<" wins!!!!"<<endl;//player 2 wins
    }
    else if(k == 'D')
    {
        cout<<"Its a Draw :)"<<endl;//Draw
    }
    else if(k == 'I')
    {
        cout<<"Exception :Input Format is Wrong"<<endl;//Invalid
    }
    return 0;
}