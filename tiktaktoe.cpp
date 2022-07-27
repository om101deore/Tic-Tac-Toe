//github: @om101deore
//linkedin: @Om Deore

#include <iostream>
using namespace std;

class Turn{
    public:
    char symbol; 
    static bool win;

    Turn(char x){
        symbol = x;         
    }    
};

//used to end running game
bool Turn::win=false;

//used to run
class Board{
    private:
    char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //address of the places
    
    public:
    //printing board
    void display(){ 
        cout<<arr[0][0]<<" | "<<arr[0][1]<<" | "<<arr[0][2]<<endl;
        cout<<"----------"<<endl;
        cout<<arr[1][0]<<" | "<<arr[1][1]<<" | "<<arr[1][2]<<endl;
        cout<<"----------"<<endl;
        cout<<arr[2][0]<<" | "<<arr[2][1]<<" | "<<arr[2][2]<<endl<<endl;
    }

    //replaces number with desired character
    void placemove(char symbol){
        
        char inp;
        
        cout<<symbol<<" turn:";
        cin>>inp;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if (inp==arr[i][j]){
                    arr[i][j]=symbol;
                    }
                }
            }            
        }      
    

    //checks if the winning conditions are met
    void iswon(char symbol){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(arr[i][0]==symbol && arr[i][1]==symbol && arr[i][2]==symbol){
                Turn::win=true;
            }
            
            else if(arr[0][j]==symbol && arr[1][j]==symbol && arr[2][j]==symbol){
                Turn::win=true;
            }

            else if(arr[0][0]==symbol && arr[1][1]==symbol && arr[2][2]==symbol){
                Turn::win=true;
            }
            
            else if(arr[0][2]==symbol && arr[1][1]==symbol && arr[2][0]==symbol){
                Turn::win=true;
            
            }}}
    } 


     
};




int main(){
    
    Turn xplayer('X');
    Turn oplayer('O');
    Board board;

    int tie=0;

    cout<<"###########################################################"<<endl;
    cout<<"-----------------------TIK-TAK-TOE-------------------------"<<endl;
    cout<<"###########################################################"<<endl;


    cout<<"Input the integer for the place you want to mark your symbol."<<endl;

    while(tie<=9)
    {   
        //for O player
        board.display();
        board.placemove(oplayer.symbol); 
        board.iswon(oplayer.symbol);

        if(Turn::win==true){
            board.display();
            cout<<"Player O won"<<endl;
            break;
        }
        tie++;

        //for when all places are filled and no one wins
        if (tie==9){
        board.display();
        cout<<"The game tied, better luck next time!"<<endl;
        break;
        }

        //for X player
        board.display();
        board.placemove(xplayer.symbol); 
        board.iswon(xplayer.symbol);

        if(Turn::win==true){
            board.display();
            cout<<"Player X won"<<endl;
            break;
        }
        tie++;
    }

    

    return 0;
}