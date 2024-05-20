#include<iostream>
using namespace std;
char board[8][8];

//Rook1 Knight1 bishop1 king queen bishop2 knight2 rook2
const int indexRook1 = 0;
const int indexKnight1 = 1;
const int indexBishop1 = 2;
const int indexKing = 3;
const int indexQueen = 4;
const int indexBishop2 = 5;
const int indexKnight2 = 6;
const int indexRook2 = 7;

int white_p[8][2]={{7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6},{7,7}};
int black_p[8][2]={{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7}};


int xK = 0, yk = 0, xQ = 0, yQ = 0, xR1 = 0, yR1 = 0, xN1 = 0, yN1 = 0, xB1 = 0, yB1 = 0, xR2 = 0, yR2 = 0, xN2 = 0, yN2 = 0, xB2 = 0, yB2 = 0;
int k1 = 3, k2 = 0;

void clearPossibilities() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == '.') {
                board[i][j] = '-';
            }
        }
    }
}

void initialize()
{

    for(int i = 0; i < 8; i++)//board
    {
        for(int j = 0; j < 8; j++)
        {
            board[i][j]='-';
        }
    }

    board[0][0] ='r';
    board[0][1] ='n';
    board[0][2] ='b';
    board[0][3] ='k';
    board[0][4] ='q';
    board[0][5] ='b';
    board[0][6] ='k';
    board[0][7] ='r';

    board[7][0] ='R';
    board[7][1] ='N';
    board[7][2] ='B';
    board[7][3] ='K';
    board[7][4] ='Q';
    board[7][5] ='B';
    board[7][6] ='K';
    board[7][7] ='R';

}

void display(){
    system("clear");
    cout << endl;
    char column = 'a';
    cout << "    ";
    for (int i=0;i<8;i++){
        cout << " " << column++; 
    }
    cout << endl << "    -----------------";
    cout << endl;

    for(int i=0; i<8; i++)
    {
        cout << "  " << i+1 << "|";
        for(int j=0; j<8; j++)
        {
            cout << " " << board[i][j];
            if (j == 8-1){
                cout << " | " << i+1;
            }
        }
        cout << endl;
    }

    column = 'a';
    cout << "    -----------------" << endl;
    cout << "    ";
    for (int i=0;i<8;i++){
        cout << " " << column++; 
    }
    cout << endl << endl;
}

void Rook1(int player)
{
    if (player == 1)
    {
        int x = white_p[indexRook1][0];
        int y = white_p[indexRook1][1];
        int temp1 = 1;
        while ((board[x + temp1][y] == '-') && ((x + temp1) < 8))
        {
            board[x + temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y] == '-') && ((x - temp1) >= 0))
        {
            board[x - temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y + temp1] == '-') && ((y + temp1) < 8))
        {
            board[x][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y - temp1] == '-') && ((y - temp1) >= 0))
        {
            board[x][y - temp1] = '.';
            temp1++;
        }
    }
    else
    {
        int x = black_p[indexRook1][0];
        int y = black_p[indexRook1][1];
        int temp1 = 1;
        while ((board[x + temp1][y] == '-') && ((x + temp1) < 8))
        {
            board[x + temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y] == '-') && ((x - temp1) >= 0))
        {
            board[x - temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y + temp1] == '-') && ((y + temp1) < 8))
        {
            board[x][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y - temp1] == '-') && ((y - temp1) >= 0))
        {
            board[x][y - temp1] = '.';
            temp1++;
        }
    }
    display();
}

void moveRook1(int player) {
    int row = 0, col = 0;
    cout << "enter the move you want to play " << endl;
    cin >> row >> col;
    while (board[row][col] != '.') {
        cout << "invalid input, try again " << endl;
        cin >> row >> col;
    }
    board[row][col] = 'R';
    board[xR1][yR1] = '-';
    clearPossibilities();
    xR1 = row;
    yR1 = col;
    if (player == 1) {
        white_p[indexRook1][0] = xR1;
        white_p[indexRook1][1] = yR1;
    }
    else {
        black_p[indexRook1][0] = xR1;
        black_p[indexRook1][1] = yR1;
    }
}

void Rook2(int player)
{
    if (player == 1)
    {
        int x = white_p[indexRook2][0];
        int y = white_p[indexRook2][1];
        int temp1 = 1;
        while ((board[x + temp1][y] == '-') && ((x + temp1) < 8))
        {
            board[x + temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y] == '-') && ((x - temp1) >= 0))
        {
            board[x - temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y + temp1] == '-') && ((y + temp1) < 8))
        {
            board[x][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y - temp1] == '-') && ((y - temp1) >= 0))
        {
            board[x][y - temp1] = '.';
            temp1++;
        }
    }
    else
    {
        int x = black_p[indexRook2][0];
        int y = black_p[indexRook2][1];
        int temp1 = 1;
        while ((board[x + temp1][y] == '-') && ((x + temp1) < 8))
        {
            board[x + temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y] == '-') && ((x - temp1) >= 0))
        {
            board[x - temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y + temp1] == '-') && ((y + temp1) < 8))
        {
            board[x][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y - temp1] == '-') && ((y - temp1) >= 0))
        {
            board[x][y - temp1] = '.';
            temp1++;
        }
    }
    display();
}
void moveRook2(int player) {
    int row = 0, col = 0;
    cout << "enter the move you want to play " << endl;
    cin >> row >> col;
    while (board[row][col] != '.') {
        cout << "invalid input, try again " << endl;
        cin >> row >> col;
    }
    board[row][col] = 'R';
    board[xR2][yR2] = '-';
    clearPossibilities();
    xR1 = row;
    yR1 = col;
    if (player == 1) {
        white_p[indexRook2][0] = xR2;
        white_p[indexRook2][1] = yR2;
    }
    else {
        black_p[indexRook2][0] = xR2;
        black_p[indexRook2][1] = yR2;
    }
}

void Bishop1(int player)
{
    if (player == 1)
    {
        int x = white_p[indexBishop1][0];
        int y = white_p[indexBishop1][1];
        // int x =4, y=4;
        int temp1 = 1;
        while ((board[x + temp1][y + temp1] == '-') && ((x + temp1) < 8) && ((y + temp1) < 8))
        {
            board[x + temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y - temp1] == '-') && ((x - temp1) >= 0) && ((y - temp1) >= 0))
        {
            board[x - temp1][y - temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y + temp1] == '-') && ((y + temp1) < 8) && ((x - temp1) >= 0))
        {
            board[x - temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x + temp1][y - temp1] == '-') && ((y - temp1) >= 0) && ((x + temp1) < 8))
        {
            board[x + temp1][y - temp1] = '.';
            temp1++;
        }
    }
    else{
        int x = black_p[indexBishop1][0];
        int y = black_p[indexBishop1][1];
        // int x =4, y=4;
        int temp1 = 1;
        while ((board[x + temp1][y + temp1] == '-') && ((x + temp1) < 8) && ((y + temp1) < 8))
        {
            board[x + temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y - temp1] == '-') && ((x - temp1) >= 0) && ((y - temp1) >= 0))
        {
            board[x - temp1][y - temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y + temp1] == '-') && ((y + temp1) < 8) && ((x - temp1) >= 0))
        {
            board[x - temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x + temp1][y - temp1] == '-') && ((y - temp1) >= 0) && ((x + temp1) < 8))
        {
            board[x + temp1][y - temp1] = '.';
            temp1++;
        }
    }
    display();
}
void moveBishop1(int player) {
    int row = 0, col = 0;
    cout << "enter the move you want to play " << endl;
    cin >> row >> col;
    while (board[row][col] != '.') {
        cout << "invalid input, try again " << endl;
        cin >> row >> col;
    }
    board[row][col] = 'B';
    board[xB1][yB1] = '-';
    clearPossibilities();
    xB1 = row;
    yB1 = col;
    if (player == 1) {
        white_p[indexBishop1][0] = xB1;
        white_p[indexBishop1][1] = yB1;
    }
    else {
        black_p[indexBishop1][0] = xB1;
        black_p[indexBishop1][1] = yB1;
    }

}

void Bishop2(int player)
{
    if (player == 1)
    {
        int x = white_p[indexBishop2][0];
        int y = white_p[indexBishop2][1];
        // int x =4, y=4;
        int temp1 = 1;
        while ((board[x + temp1][y + temp1] == '-') && ((x + temp1) < 8) && ((y + temp1) < 8))
        {
            board[x + temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y - temp1] == '-') && ((x - temp1) >= 0) && ((y - temp1) >= 0))
        {
            board[x - temp1][y - temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y + temp1] == '-') && ((y + temp1) < 8) && ((x - temp1) >= 0))
        {
            board[x - temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x + temp1][y - temp1] == '-') && ((y - temp1) >= 0) && ((x + temp1) < 8))
        {
            board[x + temp1][y - temp1] = '.';
            temp1++;
        }
    }
    else{
        int x = black_p[indexBishop2][0];
        int y = black_p[indexBishop2][1];
        // int x =4, y=4;
        int temp1 = 1;
        while ((board[x + temp1][y + temp1] == '-') && ((x + temp1) < 8) && ((y + temp1) < 8))
        {
            board[x + temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y - temp1] == '-') && ((x - temp1) >= 0) && ((y - temp1) >= 0))
        {
            board[x - temp1][y - temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y + temp1] == '-') && ((y + temp1) < 8) && ((x - temp1) >= 0))
        {
            board[x - temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x + temp1][y - temp1] == '-') && ((y - temp1) >= 0) && ((x + temp1) < 8))
        {
            board[x + temp1][y - temp1] = '.';
            temp1++;
        }
    }
    display();
}
void moveBishop2(int player) {
    int row = 0, col = 0;
    cout << "enter the move you want to play " << endl;
    cin >> row >> col;
    while (board[row][col] != '.') {
        cout << "invalid input, try again " << endl;
        cin >> row >> col;
    }
    board[row][col] = 'B';
    board[xB2][yB2] = '-';
    clearPossibilities();
    xB2 = row;
    yB2 = col;
    if (player == 1) {
        white_p[indexBishop2][0] = xB2;
        white_p[indexBishop2][1] = yB2;
    }
    else {
        black_p[indexBishop2][0] = xB2;
        black_p[indexBishop2][1] = yB2;
    }
}

void queen(int player)
{
    if (player == 1)
    {
        int x = white_p[indexQueen][0];
        int y = white_p[indexQueen][1];
        int temp1 = 1;
        while ((board[x + temp1][y] == '-') && ((x + temp1) < 8))
        {
            board[x + temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y] == '-') && ((x - temp1) >= 0))
        {
            board[x - temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y + temp1] == '-') && ((y + temp1) < 8))
        {
            board[x][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y - temp1] == '-') && ((y - temp1) >= 0))
        {
            board[x][y - temp1] = '.';
            temp1++;
        }
         while ((board[x + temp1][y + temp1] == '-') && ((x + temp1) < 8) && ((y + temp1) < 8))
        {
            board[x + temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y - temp1] == '-') && ((x - temp1) >= 0) && ((y - temp1) >= 0))
        {
            board[x - temp1][y - temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y + temp1] == '-') && ((y + temp1) < 8) && ((x - temp1) >= 0))
        {
            board[x - temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x + temp1][y - temp1] == '-') && ((y - temp1) >= 0) && ((x + temp1) < 8))
        {
            board[x + temp1][y - temp1] = '.';
            temp1++;
        }
    }
    else
    {
        int x = black_p[indexQueen][0];
        int y = black_p[indexQueen][1];
        int temp1 = 1;
        while ((board[x + temp1][y] == '-') && ((x + temp1) < 8))
        {
            board[x + temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y] == '-') && ((x - temp1) >= 0))
        {
            board[x - temp1][y] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y + temp1] == '-') && ((y + temp1) < 8))
        {
            board[x][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x][y - temp1] == '-') && ((y - temp1) >= 0))
        {
            board[x][y - temp1] = '.';
            temp1++;
        }
         while ((board[x + temp1][y + temp1] == '-') && ((x + temp1) < 8) && ((y + temp1) < 8))
        {
            board[x + temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y - temp1] == '-') && ((x - temp1) >= 0) && ((y - temp1) >= 0))
        {
            board[x - temp1][y - temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x - temp1][y + temp1] == '-') && ((y + temp1) < 8) && ((x - temp1) >= 0))
        {
            board[x - temp1][y + temp1] = '.';
            temp1++;
        }
        temp1 = 1;
        while ((board[x + temp1][y - temp1] == '-') && ((y - temp1) >= 0) && ((x + temp1) < 8))
        {
            board[x + temp1][y - temp1] = '.';
            temp1++;
        }
    }
    
}
void moveQueen(int player) {
    int row = 0, col = 0;
    cout << "enter the move you want to play " << endl;
    cin >> row >> col;
    while (board[row][col] != '.') {
        cout << "invalid input, try again " << endl;
        cin >> row >> col;
    }
    board[row][col] = 'Q';
    board[xQ][yQ] = '-';
    clearPossibilities();
    xQ = row;
    yQ = col;
    if (player == 1) {
        white_p[indexQueen][0] = xQ;
        white_p[indexQueen][1] = yQ;
    }
    else {
        black_p[indexQueen][0] = xQ;
        black_p[indexQueen][1] = yQ;
    }
}

void Knight1(int player)
{
    if (player == 1)
    {
        int x = white_p[indexKnight1][0];
        int y = white_p[indexKnight1][1];
        //int temp1 = 1;
        while ((board[x + 2][y+1] == '-') && ((x + 2) < 8)&& ((y+1)<8))
        {
            board[x + 2][y+1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 2][y-1] == '-') && ((x - 2) >= 0)&&((y - 1) >= 0))
        {
            board[x - 2][y-1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x-2][y + 1] == '-') && ((y + 1) < 8)&&((x - 2) >= 0))
        {
            board[x-2][y + 1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x+2][y - 1] == '-') && ((y - 1) >= 0)&&((x + 2) < 8))
        {
            board[x+2][y - 1] = '.';
            //temp1++;
        }
         while ((board[x - 1][y + 2] == '-') && ((x - 1) >= 0) && ((y + 2) < 8))        //?
        {
            board[x - 1][y + 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x + 1][y - 2] == '-') && ((x + 1) < 8) && ((y - 2) >= 0))
        {
            board[x + 1][y - 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 1][y + 2] == '-') && ((y + 2) < 8) && ((x - 1) >= 0))
        {
            board[x - 1][y + 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x + 1][y + 2] == '-') && ((y + 2) < 8) && ((x + 1) < 8))
        {
            board[x + 1][y + 2] = '.';
            //temp1++;
        }
    }
    else
    {
        {
        int x = black_p[indexKnight1][0];
        int y = black_p[indexKnight1][1];
        //int temp1 = 1;
        while ((board[x + 2][y+1] == '-') && ((x + 2) < 8)&& ((y+1)<8))
        {
            board[x + 2][y+1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 2][y-1] == '-') && ((x - 2) >= 0)&&((y - 1) >= 0))
        {
            board[x - 2][y-1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x-2][y + 1] == '-') && ((y + 1) < 8)&&((x - 2) >= 0))
        {
            board[x-2][y + 1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x+2][y - 1] == '-') && ((y - 1) >= 0)&&((x + 2) < 8))
        {
            board[x+2][y - 1] = '.';
            //temp1++;
        }
         while ((board[x - 1][y + 2] == '-') && ((x - 1) >= 0) && ((y + 2) < 8))        //?
        {
            board[x - 1][y + 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x + 1][y - 2] == '-') && ((x + 1) < 8) && ((y - 2) >= 0))
        {
            board[x + 1][y - 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 1][y + 2] == '-') && ((y + 2) < 8) && ((x - 1) >= 0))
        {
            board[x - 1][y + 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x + 1][y + 2] == '-') && ((y + 2) < 8) && ((x + 1) < 8))
        {
            board[x + 1][y + 2] = '.';
            //temp1++;
        }
    }
    }
}
void moveKnight1(int player) {
    int row = 0;
    int col = 0;

    cout << "enter the move you want to play " << endl;
    cin >> row >> col;
    while (board[row][col] != '.') {
        cout << "invalid input, try again " << endl;
        cin >> row >> col;
    }
    board[row][col] = 'N';
    board[xN1][yN1] = '-';
   
       
    clearPossibilities();
    xN1 = row;
    yN1 = col;
    if (player == 1) {
        white_p[indexKnight1][0] = xN1;
        white_p[indexKnight1][1] = yN1;
    }
    else {
        black_p[indexKnight1][0] = xN1;
        black_p[indexKnight1][1] = yN1;
    }

}

void Knight2(int player)
{
    if (player == 1)
    {
        int x = white_p[indexKnight2][0];
        int y = white_p[indexKnight2][1];
        //int temp1 = 1;
        while ((board[x + 2][y+1] == '-') && ((x + 2) < 8)&& ((y+1)<8))
        {
            board[x + 2][y+1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 2][y-1] == '-') && ((x - 2) >= 0)&&((y - 1) >= 0))
        {
            board[x - 2][y-1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x-2][y + 1] == '-') && ((y + 1) < 8)&&((x - 2) >= 0))
        {
            board[x-2][y + 1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x+2][y - 1] == '-') && ((y - 1) >= 0)&&((x + 2) < 8))
        {
            board[x+2][y - 1] = '.';
            //temp1++;
        }
         while ((board[x - 1][y + 2] == '-') && ((x - 1) >= 0) && ((y + 2) < 8))        //?
        {
            board[x - 1][y + 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x + 1][y - 2] == '-') && ((x + 1) < 8) && ((y - 2) >= 0))
        {
            board[x + 1][y - 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 1][y + 2] == '-') && ((y + 2) < 8) && ((x - 1) >= 0))
        {
            board[x - 1][y + 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x + 1][y + 2] == '-') && ((y + 2) < 8) && ((x + 1) < 8))
        {
            board[x + 1][y + 2] = '.';
            //temp1++;
        }
    }
    else
    {
        {
        int x = black_p[indexKnight2][0];
        int y = black_p[indexKnight2][1];
        //int temp1 = 1;
        while ((board[x + 2][y+1] == '-') && ((x + 2) < 8)&& ((y+1)<8))
        {
            board[x + 2][y+1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 2][y-1] == '-') && ((x - 2) >= 0)&&((y - 1) >= 0))
        {
            board[x - 2][y-1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x-2][y + 1] == '-') && ((y + 1) < 8)&&((x - 2) >= 0))
        {
            board[x-2][y + 1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x+2][y - 1] == '-') && ((y - 1) >= 0)&&((x + 2) < 8))
        {
            board[x+2][y - 1] = '.';
            //temp1++;
        }
         while ((board[x - 1][y + 2] == '-') && ((x - 1) >= 0) && ((y + 2) < 8))        //?
        {
            board[x - 1][y + 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x + 1][y - 2] == '-') && ((x + 1) < 8) && ((y - 2) >= 0))
        {
            board[x + 1][y - 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 1][y + 2] == '-') && ((y + 2) < 8) && ((x - 1) >= 0))
        {
            board[x - 1][y + 2] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x + 1][y + 2] == '-') && ((y + 2) < 8) && ((x + 1) < 8))
        {
            board[x + 1][y + 2] = '.';
            //temp1++;
        }
    }
    }
}
void moveKnight2(int player) {
    int row = 0;
    int col = 0;

    cout << "enter the move you want to play " << endl;
    cin >> row >> col;
    while (board[row][col] != '.') {
        cout << "invalid input, try again " << endl;
        cin >> row >> col;
    }
    board[row][col] = 'N';
    board[xN2][yN2] = '-';


    clearPossibilities();
    xN2 = row;
    yN2 = col;
    if (player == 1) {
        white_p[indexKnight2][0] = xN2;
        white_p[indexKnight2][1] = yN2;
    }
    else {
        black_p[indexKnight2][0] = xN2;
        black_p[indexKnight2][1] = yN2;
    }
}

void King(int player)
{
    if (player == 1)
    {
        int x = white_p[indexKing][0];
        int y = white_p[indexKing][1];
        //int temp1 = 1;
        while ((board[x + 1][y+1] == '-') && ((x + 1) < 8)&& ((y+1)<8))
        {
            board[x + 1][y+1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 1][y-1] == '-') && ((x - 1) >= 0)&&((y - 1) >= 0))
        {
            board[x - 1][y-1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x-1][y + 1] == '-') && ((y + 1) < 8)&&((x - 1) >= 0))
        {
            board[x-1][y + 1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x+1][y - 1] == '-') && ((y - 1) >= 0)&&((x + 1) < 8))
        {
            board[x+1][y - 1] = '.';
            //temp1++;
        }
         while ((board[x][y + 1] == '-') && ((y + 1) < 8))        
        {
            board[x][y + 1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x][y - 1] == '-') &&((y - 1) >= 0))
        {
            board[x][y - 1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 1][y] == '-') &&((x - 1) >= 0))
        {
            board[x - 1][y] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x + 1][y] == '-') &&((x + 1) < 8))
        {
            board[x + 1][y] = '.';
            //temp1++;
        }
    }
    else
    {
        int x = black_p[indexKing][0];
        int y = black_p[indexKing][1];
        //int temp1 = 1;
        while ((board[x + 1][y+1] == '-') && ((x + 1) < 8)&& ((y+1)<8))
        {
            board[x + 1][y+1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 1][y-1] == '-') && ((x - 1) >= 0)&&((y - 1) >= 0))
        {
            board[x - 1][y-1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x-1][y + 1] == '-') && ((y + 1) < 8)&&((x - 1) >= 0))
        {
            board[x-1][y + 1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x+1][y - 1] == '-') && ((y - 1) >= 0)&&((x + 1) < 8))
        {
            board[x+1][y - 1] = '.';
            //temp1++;
        }
         while ((board[x][y + 1] == '-') && ((y + 1) < 8))        
        {
            board[x][y + 1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x][y - 1] == '-') &&((y - 1) >= 0))
        {
            board[x][y - 1] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x - 1][y] == '-') &&((x - 1) >= 0))
        {
            board[x - 1][y] = '.';
            //temp1++;
        }
        //temp1 = 1;
        while ((board[x + 1][y] == '-') &&((x + 1) < 8))
        {
            board[x + 1][y] = '.';
            //temp1++;
        }
    
    }
    
}
void moveKing(int player) {
    int horizontal=0;
    int vertical=0;
    
    cout << "enter the move you want to play " << endl;
    cin >> horizontal >> vertical;
    while (board[horizontal][vertical] != '.') {
        cout << "invalid input, try again " << endl;
        cin >> horizontal >> vertical;
    }
    board[horizontal][vertical] = 'K';
    board[xK][yk] = '-';
    clearPossibilities();
    xK = horizontal;
    yk = vertical;
    if (player == 1) {
        white_p[indexKing][0] = xK;
        white_p[indexKing][1] = yk;
    }
    else {
        black_p[indexKing][0] = xK;
        black_p[indexKing][1] = yk;
    }
}
void menu()
{  int choice;
   int count=0,p=2,temp=0;
    do
  { display();
    cout<<"It's Player"<<pow(p,temp)<<" turn"<<endl;
    cout<<"Press 0 to play Rook1"<<endl;
    cout<<"Press 1 to play Knight1"<<endl;
    cout<<"Press 2 to play Bishop1"<<endl;
    cout<<"Press 3 to play King"<<endl;
    cout<<"Press 4 to play Queen"<<endl;
    cout<<"Press 5 to play Bishop2"<<endl;
    cout<<"Press 6 to play Knight2"<<endl;
    cout<<"Press 7 to play Rook2"<<endl;
    cout<<"Press 8 to exit the game"<<endl;
    do
    {

       cin>>choice;
       if(choice>8||choice<0)
       cout<<"Enter valid number to play!";
    }while(choice>0&&choice>8);
    count++;
     if(count%2==0)
    temp=0;
    else
    temp=1;  
    switch(choice)
    {
        case 0:
            Rook1(pow(p,temp)) ; display(); moveRook1(pow(p,temp)); display(); break;;
            
        case 1:
            Knight1(pow(p,temp)); display(); moveRook1(pow(p,temp)); display(); break;
            
        case 2:
            Bishop1(pow(p,temp)); display(); moveRook1(pow(p,temp)); display(); break;
            
        case 3:
            King(pow(p,temp)); display(); moveRook1(pow(p,temp)); display(); break;
            
        case 4:
            queen(pow(p,temp)); display(); moveRook1(pow(p,temp)); display(); break;
            
        case 5:
            Bishop2(pow(p,temp)); display(); moveRook1(pow(p,temp)); display(); break;
            
        case 6:
            Knight2(pow(p,temp)); display(); moveRook1(pow(p,temp)); display(); break;
            
        case 7:
            Rook2(pow(p,temp)); display(); moveRook1(pow(p,temp)); display(); break;
            
        case 8: return;
        default: return;
            cout<<"Invalid input!";
            break;
    
    }
       
    


    

    

}while(choice!=8);
}


    

void start()
{
    initialize();
    menu();
}

int main()
{
    start();
    return 0;

}