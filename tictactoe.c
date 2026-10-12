#include<stdio.h>
#include<string.h>

// Compare the text [start] from file gets string function to start.
int stringCompare(char init_cmd[]){
    char cmd[] = "start";
    for(int i = 0; i < 5; i++){
        if(init_cmd[i] != cmd[i]){
            return 0;
        }
    }

    return init_cmd[5] == '\0' || init_cmd[5] == '\n';
}

void display_board(char tictactoe[3][3]){
    // invoked after inputs and display the updated array 
    printf("-----------------\n");
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            if(col == 1){
                printf("|  %c  |", tictactoe[row][col]);
            }else{
                printf("  %c  ", tictactoe[row][col]);
            }
        }
        printf("\n");
        printf("-----------------\n");
    }
}

// Check winner function
int check_winner(char tictactoe[3][3]){

    for(int row = 0; row < 3; row++){
        
        if(tictactoe[row][0] != '-' && tictactoe[row][0] == tictactoe[row][1] && tictactoe[row][1] == tictactoe[row][2]){
            return 1;
        }
    
    }

    for(int col = 0; col < 3; col++){
        
        if(tictactoe[0][col] != '-' && tictactoe[0][col] == tictactoe[1][col] && tictactoe[1][col] == tictactoe[2][col]){
            return 1;
        }
    
    }

    if(tictactoe[0][0] != '-' && tictactoe[0][0] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][2]){
        return 1;
    }

    if(tictactoe[0][2] != '-' && tictactoe[0][2] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][0]){
        return 1;
    }


    return 0;

}

int main(){

    char tictactoe[3][3] = {
        {'-', '-', '-'}, 
        {'-', '-', '-'}, 
        {'-', '-', '-'}
    };

    char init_game[7];
    char player_mark = 'X';
    int moves = 0;

    printf("Type [start] to begin $ ");
    fgets(init_game, sizeof(init_game), stdin); // Leaves a \n

    if(stringCompare(init_game)){
        // Game initiate when player inputs 'start' (all lower)

        printf("Welcome to Tic-Tac-Toe!\n");

        while(1){
            // Player Inputs (Row, Column)
            
            int in_row;
            int in_col;

            printf("Player %c Move\n", player_mark);

            printf("Select a row (1/2/3) -> ");
            scanf("%d", &in_row);
            printf("Select a column (1/2/3) -> ");
            scanf("%d", &in_col);

            if((in_row >= 1 && in_row <= 3) && (in_col >= 1 && in_col <= 3)){

                if(tictactoe[in_row - 1][in_col - 1] == '-'){
                    tictactoe[in_row - 1][in_col - 1] = player_mark;
                    moves++;
                }else{
                    printf("The place is occupied!\n");
                }
                
                display_board(tictactoe);

                if(check_winner(tictactoe)){
                    printf("Congratulations %c WINS!!!(^_^)\n ", player_mark);
                    break;
                }else if(moves == 9){
                    printf("GAME DRAW. (*-*)");
                    break;
                }

                player_mark = player_mark == 'X' ? 'O' : 'X';
                
            }else{
                printf("Row(1/2/3) and Column(1/2/3)\n");
            }  
        }
    }else{
        printf("Type [start] / No such Command / Not Now?");
    }

    return 0;
}