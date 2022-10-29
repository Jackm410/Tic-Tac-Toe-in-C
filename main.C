#include <stdio.h>

void printBoard(char arr[4][4])
{
  for(int i = 0; i < 4; i ++)
    {
      for(int u = 0; u < 4; u ++)
        {
          printf("%c ", arr[i][u]);
        }
      printf("\n");
    }
}

int checkWin(char arr[4][4])
{
  //chekc row
  for(int i = 1; i < 4; i ++){
    if(arr[i][1] != ' ' && arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3]){
      return 1;
    }
  }
  
  //check column
  for(int i = 1; i < 4; i ++){
    if(arr[1][i] != ' ' && arr[1][i] == arr[2][i] && arr[2][i] == arr[3][i]){
      return 1;
    }
  }
  //diagno 
  if(arr[1][1] != ' ' && arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3]){
    return 1;
  }

  if(arr[1][3] != ' ' && arr[1][3] == arr[2][2] && arr[2][2] == arr[3][1]){
    return 1;
  }
  return 0;
}

int main(void) {
  char board[4][4] = {{' ', '1', '2', '3'}, {'1', ' ', ' ', ' '}, {'2', ' ', ' ', ' '}, {'3', ' ', ' ', ' '}, };
  
  int counter = 0;
  

  
  while(1){
    int row;
    int col;
    int count = 0;
    printBoard(board);
    if(counter == 9){
      printf("Draw!");
      break;
    }
    if(checkWin(board)){
      if(counter % 2 == 0){
        printf("O Win!!!");
      }
      else{
        printf("X Win!!!");
      }
      break;
    }

    //play
    if(counter % 2 == 0){
      do{
        if(count == 0){
          printf("It is X's turn! \nEnter the row: "); 
          count ++;
        }
        else{
          printf("This position is taken, please enter row and column again.\nEnter the row: ");
        }
        scanf("%d", &row);
        printf("\n");
        while(row > 3 || row < 1){
          printf("Input has to be between 1 and 3.\nEnter the row: ");
          scanf("%d", &row);
          printf("\n");
        }

        
        printf("Enter the column: ");                //col
        scanf("%d", &col);
        printf("\n");
        while(col > 3 || col < 1){
          printf("Input has to be between 1 and 3.\nEnter the column: ");
          scanf("%d", &col);
          printf("\n");
        }
      }
      while(board[row][col] != ' ');
      
      board[row][col] = 'X';
    }
    else{
      do{
        if(count == 0){
          printf("It is O's turn! \nEnter the row: "); 
          count ++;
        }
        else{
          printf("This position is taken, please enter row and column again.\nEnter the row: ");
        }      //row
        scanf("%d", &row);
        printf("\n");
        while(row > 3 || row < 1){
          printf("Input has to be between 1 and 3.\nEnter the row: ");
          scanf("%d", &row);
          printf("\n");
        }

        
        printf("Enter the column: ");                //col
        scanf("%d", &col);
        printf("\n");
        while(col > 3 || col < 1){
          printf("Input has to be between 1 and 3.\nEnter the column: ");
          scanf("%d", &col);
          printf("\n");
        }
      }
      while(board[row][col] != ' ');
      board[row][col] = 'O';
    }

    counter ++;
    printf("\n");
  }
  
  return 0;
}
