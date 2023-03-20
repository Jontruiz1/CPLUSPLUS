#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<int> board){
    int k = 0;
    for(int i = 0; i < 3 ; ++i){
        for(int j = 0; j < 3; ++j, ++k){
            if(board[k] == 1){
                cout << "X ";
            }
            else if(board[k] == 2){
                cout << "O ";
            }
            else{
                cout << "_ ";
            }
        }
        cout << endl;
    }
}

int processChoice(const vector<int>& board, int player){
    int choice;
    do{
        cout << "Enter a VALID number choice, 1-9 to place your character in that spot: ";
        cin >> choice;

    } while((choice < 1 || choice > 9) && board[choice] != player);

    return choice;
}

bool checkRows(const vector<int>& board, int compare){
    for(int i = 0; i < 3; ++i){
        if(board[i*3] == compare && board[i*3] == board[i*3+1] && board[i*3+1] == board[i*3+2]) return true;
    }
    return false;
}

bool checkVerticals(const vector<int>& board, int compare){
    for(int i = 0; i < 3; ++i){
        if(board[i] == compare && board[i] == board[i+3] && board[i+3] == board[i+6]) return true;
    }
    return false;
}
bool checkDiagonals(const vector<int>& board, int compare){
    if(board[0] == compare && board[0] == board[4] && board[4] == board[8]) return true;
    if(board[2] == compare && board[2] == board[4] && board[4] == board[6]) return true;
    return false;
}

bool isWin(const vector<int>& board, int compare){
    return checkRows(board, compare) || checkDiagonals(board, compare) || checkVerticals(board, compare);
}

int computerEasy(vector<int>& board, int player){
    int index;
    do{
        index = rand() % 9;
    }while(board[index] == player);

    return index;
}

int main(){
    srand(time(NULL));
    vector<int> board(9);

    int play = 3;
    int choice;
    char playerChar = 'X';
    string winner = "";

    while(true){
        printBoard(board);
        if(playerChar == 'X'){
            choice = processChoice(board, 2);
            board[choice-1] = 1;
            play = !isWin(board, 1) ? 3 : 1;
            if(play == 1) break;
            choice = computerEasy(board, 1);
            board[choice] = 2;
            play = !isWin(board, 2) ? 3 : 2;
            if(play == 2) break;
        }
    }

    printBoard(board);
    cout << "Player " << play << " wins!";

    return 0;

}