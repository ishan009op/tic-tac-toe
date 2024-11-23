// Tic-Tac-Toe
#include <iostream>
using namespace std;
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

char turn = 'x';
int row, coloumn;
int count = 0;
bool draw = false;

void display_board()
{
    system("cls");
    cout << "\t \tTic-Tac-Toe" << endl;
    cout << "\tplayer 1[X]" << endl
         << "\tplayer 2[O]" << endl;

    cout << "\t\t\t" << "     |     |     " << endl;
    cout << "\t\t\t" << "  " << board[0][0] << "  |  " << board[0][1] << "  | " << board[0][2] << "   " << endl;
    cout << "\t\t\t" << "_____|_____|_____" << endl;
    cout << "\t\t\t" << "     |     |     " << endl;
    cout << "\t\t\t" << "  " << board[1][0] << "  |  " << board[1][1] << "  | " << board[1][2] << "   " << endl;
    cout << "\t\t\t" << "_____|_____|_____" << endl;
    cout << "\t\t\t" << "     |     |     " << endl;
    cout << "\t\t\t" << "  " << board[2][0] << "  |  " << board[2][1] << "  | " << board[2][2] << "   " << endl;
    cout << "\t\t\t" << "     |     |     " << endl;
};

void playerturn()
{
    int choice;
    if (turn == 'x')
    {
        cout << "\t\tplayer1[X] turn:";
    }
    if (turn == 'o')
    {

        cout << "\t\tplayer2[O] turn:";
    }

    cin >> choice;
    switch (choice)
    {
    case 1:
        row = 0;
        coloumn = 0;
        break;
    case 2:
        row = 0;
        coloumn = 1;
        break;
    case 3:
        row = 0;
        coloumn = 2;
        break;
    case 4:
        row = 1;
        coloumn = 0;
        break;
    case 5:
        row = 1;
        coloumn = 1;
        break;
    case 6:
        row = 1;
        coloumn = 2;
        break;
    case 7:
        row = 2;
        coloumn = 0;
        break;
    case 8:
        row = 2;
        coloumn = 1;
        break;
    case 9:
        row = 2;
        coloumn = 2;

        break;

    default:
        cout << "invalid options" << endl;
        break;
    }

    if (turn == 'x' && board[row][coloumn] != 'X' && board[row][coloumn] != 'O')
    {
        board[row][coloumn] = 'X';
        turn = 'o';
    }
    if (turn == 'o' && board[row][coloumn] != 'X' && board[row][coloumn] != 'O')
    {
        board[row][coloumn] = 'O';
        turn = 'x';
     }
    //else{
    //     cout<<"box is already filled"<<endl;
    //     playerturn();
    // }

    display_board();
}
bool gameover()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[1][i] == board[2][i]
        || board[0][0]==board[1][1] && board[1][1]==board[2][2] || board[0][2]==board[1][1] && board[1][1]==board[2][0])
        {

            return false;
        }
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }
    draw = true;
    return false;
};

int main()
{

    while (gameover())
    {
        display_board();
        playerturn();
        gameover();
    }

    if (turn == 'x' && draw == false)
    {
        cout << "player1 wins the game";
    }
    else if (turn == 'o' && draw == false)
    {
        cout << "player2 wins the game";
    }else{
        cout<<"game draw";
    }

    return 0;
}
