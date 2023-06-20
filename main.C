#include <stdio.h>
#include <stdlib.h>

int r[2];               //r is the location (X, Y)
int t[2];               //Global Variables
int counter = 0;

void printBoard(char arr[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int u = 0; u < 4; u++) {
            printf("%c ", arr[i][u]);
        }
        printf("\n");
    }
}

int checkWin(char arr[4][4]) {
    // chekc row
    for (int i = 1; i < 4; i++) {
        if (arr[i][1] != ' ' && arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3]) {
            return 1;
        }
    }

    // check column
    for (int i = 1; i < 4; i++) {
        if (arr[1][i] != ' ' && arr[1][i] == arr[2][i] && arr[2][i] == arr[3][i]) {
            return 1;
        }
    }
    // diagno
    if (arr[1][1] != ' ' && arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3]) {
        return 1;
    }

    if (arr[1][3] != ' ' && arr[1][3] == arr[2][2] && arr[2][2] == arr[3][1]) {
        return 1;
    }
    return 0;
}

int findEmp(char arr[4][4]) {          //find a empty place on the board and store it in "t[]"
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (arr[i][j] == ' ') {
                t[0] = i;
                t[1] = j;
                return 0;
            }
        }
    }
    return 0;
}

int chkopt(char arr[4][4]) {    //check for opportunity

    for (int i = 1; i <= 3; i++) { // horizontal check for o
        if (arr[i][1] == ' ' && arr[i][2] == arr[i][3] && arr[i][2] == 'O') {
            r[0] = i;
            r[1] = 1;
            return 0;
        }
        if (arr[i][2] == ' ' && arr[i][1] == arr[i][3] && arr[i][1] == 'O') {
            r[0] = i;
            r[1] = 2;
            return 0;
        }
        if (arr[i][3] == ' ' && arr[i][1] == arr[i][2] && arr[i][1] == 'O') {
            r[0] = i;
            r[1] = 3;
            return 0;
        }
    }

    for (int i = 1; i <= 3; i++) { // vertical check for o
        if (arr[1][i] == ' ' && arr[2][i] == arr[3][i] && arr[2][i] == 'O') {
            r[0] = 1;
            r[1] = i;
            return 0;
        }
        if (arr[2][i] == ' ' && arr[1][i] == arr[3][i] && arr[1][i] == 'O') {
            r[0] = 2;
            r[1] = i;
            return 0;
        }
        if (arr[3][i] == ' ' && arr[1][i] == arr[2][i] && arr[1][i] == 'O') {
            r[0] = 3;
            r[1] = i;
            return 0;
        }
    }

    // diagnol check
    // left to right
    if (arr[1][1] == ' ' && arr[2][2] == arr[3][3] && arr[2][2] == 'O') {
        r[0] = 1;
        r[1] = 1;
        return 0;
    }
    if (arr[2][2] == ' ' && arr[1][1] == arr[3][3] && arr[1][1] == 'O') {
        r[0] = 2;
        r[1] = 2;
        return 0;
    }
    if (arr[3][3] == ' ' && arr[1][1] == arr[2][2] && arr[1][1] == 'O') {
        r[0] = 3;
        r[1] = 3;
        return 0;
    }

    // right to left
    if (arr[1][3] == ' ' && arr[2][2] == arr[3][1] && arr[2][2] == 'O') {
        r[0] = 1;
        r[1] = 3;
        return 0;
    }
    if (arr[2][2] == ' ' && arr[1][3] == arr[3][1] && arr[1][3] == 'O') {
        r[0] = 2;
        r[1] = 2;
        return 0;
    }
    if (arr[3][1] == ' ' && arr[1][3] == arr[2][2] && arr[1][3] == 'O') {
        r[0] = 3;
        r[1] = 1;
        return 0;
    }

    //-------------------------------------------------------------------------------------------------------

    for (int i = 1; i <= 3; i++) { // horizontal check
        if (arr[i][1] == ' ' && arr[i][2] == arr[i][3] && arr[i][2] != ' ') {
            r[0] = i;
            r[1] = 1;
            return 0;
        }
        if (arr[i][2] == ' ' && arr[i][1] == arr[i][3] && arr[i][1] != ' ') {
            r[0] = i;
            r[1] = 2;
            return 0;
        }
        if (arr[i][3] == ' ' && arr[i][1] == arr[i][2] && arr[i][1] != ' ') {
            r[0] = i;
            r[1] = 3;
            return 0;
        }
    }

    for (int i = 1; i <= 3; i++) { // vertical check
        if (arr[1][i] == ' ' && arr[2][i] == arr[3][i] && arr[2][i] != ' ') {
            r[0] = 1;
            r[1] = i;
            return 0;
        }
        if (arr[2][i] == ' ' && arr[1][i] == arr[3][i] && arr[1][i] != ' ') {
            r[0] = 2;
            r[1] = i;
            return 0;
        }
        if (arr[3][i] == ' ' && arr[1][i] == arr[2][i] && arr[1][i] != ' ') {
            r[0] = 3;
            r[1] = i;
            return 0;
        }
    }

    // diagnol check
    // left to right
    if (arr[1][1] == ' ' && arr[2][2] == arr[3][3] && arr[2][2] != ' ') {
        r[0] = 1;
        r[1] = 1;
        return 0;
    }
    if (arr[2][2] == ' ' && arr[1][1] == arr[3][3] && arr[1][1] != ' ') {
        r[0] = 2;
        r[1] = 2;
        return 0;
    }
    if (arr[3][3] == ' ' && arr[1][1] == arr[2][2] && arr[1][1] != ' ') {
        r[0] = 3;
        r[1] = 3;
        return 0;
    }

    // right to left
    if (arr[1][3] == ' ' && arr[2][2] == arr[3][1] && arr[2][2] != ' ') {
        r[0] = 1;
        r[1] = 3;
        return 0;
    }
    if (arr[2][2] == ' ' && arr[1][3] == arr[3][1] && arr[1][3] != ' ') {
        r[0] = 2;
        r[1] = 2;
        return 0;
    }
    if (arr[3][1] == ' ' && arr[1][3] == arr[2][2] && arr[1][3] != ' ') {
        r[0] = 3;
        r[1] = 1;
        return 0;
    }
    
    if (counter == 3 && arr[3][1] == 'X' && arr[2][2] == 'O' && arr[1][3] == 'X'){
        r[0] = 1;
        r[1] = 2;
        return 0;
    }
    else {
        findEmp(arr);
        //printf("findEmp debugggggggggggggggggggggggggggggggggggg\n\n\n\n");
        r[0] = t[0];
        r[1] = t[1];
        return 0;
    }
}

int main(void) {
    char board[4][4] = {
        {' ', '1', '2', '3'},
        {'1', ' ', ' ', ' '},
        {'2', ' ', ' ', ' '},
        {'3', ' ', ' ', ' '},
    };

    

    while (true) {
        int row;
        int col;
        int count = 0;
        printBoard(board);
        if (counter == 9) {
            printf("\n\n\nDraw!\n\n\n\n\n");
            break;
        }
        if (checkWin(board)) {
            if (counter % 2 == 0) {
                printf("\n\n\nO Win!!!\n\n\n\n\n");
            }
            else {
                printf("\n\n\nX Win!!!\n\n\n\n\n");
            }
            break;
        }

        // play
        if (counter % 2 == 0) {
            do {
                if (count == 0) {
                    printf("It is X's turn! \nEnter the row: ");
                    count++;
                }
                else {
                    printf("This position is taken, please enter row and column "
                        "again.\nEnter the row: ");
                }
                scanf_s("%d", &row);
                printf("\n");
                while (row > 3 || row < 1) {
                    printf("Input has to be between 1 and 3.\nEnter the row: ");
                    scanf_s("%d", &row);
                    printf("\n");
                }

                printf("Enter the column: "); // col
                scanf_s("%d", &col);
                printf("\n");
                while (col > 3 || col < 1) {
                    printf("Input has to be between 1 and 3.\nEnter the column: ");
                    scanf_s("%d", &col);
                    printf("\n");
                }
            } while (board[row][col] != ' ');

            board[row][col] = 'X';
        }

        // computer part

        else { // computer part
          // first round
            //printf("\n\ncounter = %d\n\n", counter);
            if (counter < 2) {
                if (board[1][2] != ' ')
                    board[3][2] = 'O';
                else if (board[2][1] != ' ')
                    board[2][3] = 'O';
                else if (board[2][3] != ' ')
                    board[2][1] = 'O';
                else if (board[3][2] != ' ')
                    board[1][2] = 'O';

                else if (board[2][2] == ' ')
                    board[2][2] = 'O';
                else {
                    board[1][1] = 'O';
                }
            }

            // later round.....
            else {
                chkopt(board);

                //printf("%d, %d\n\n", r[0], r[1]);
                board[r[0]][r[1]] = 'O';

            }
        }

        counter++;
        printf("\n");
        system("CLS");
    }

    return 0;
}
