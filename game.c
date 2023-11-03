#include<stdio.h>
#include<stdbool.h>
#include<string.h>


void output();
int ans_check();

char move_positions[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int total_move_cnt = 0;
bool move_done[20];

int main(){
    output();

    int player = 1;


    //main code
    while(1){

        //take input;
         char move_ind_char[100];

         printf("Please Enter Player %d Move: ", player);
         scanf("%s", move_ind_char);


        //filter valid input
        if(strlen(move_ind_char) > 1){
            printf("Invalid Position. Please Choose Position Between 1 to 9\n");
            continue;
        }

        if(move_ind_char[0] < '1' || move_ind_char[0] > '9'){
            printf("Invalid Position. Please Choose Position Between 1 to 9\n");
            continue;
        }


        int move_ind = move_ind_char[0] - '0';



        //check if the move is already given
        if(move_done[move_ind]){
            printf("This move is alrady given. Try another move\n");
            continue;
        }
        else{
            move_done[move_ind] = true;
        }
        //replace positions with input value
         if(player == 1){
            move_positions[move_ind] = 'X';
         }
         else{
            move_positions[move_ind] = 'O';
         }



        // turn the move to other player
        if(player == 2){
            player--;
        }
        else{
            player++;
        }
        output();

        int check = ans_check();


        // Print the result of the game;
        if(check == 1){
            printf("Congratulations to Player 1. You've won the game :) \n");
        }
        else if(check == 0){
            printf("Congratulations to Player 2. You've won the game :) \n");
        }
        else if(check == -1){
            printf("Match Draw. Play again to win\n");
        }


        // finish the game
        if(check != 2){
            break;;
        }



    }


}

//function for check ans. 1 == player 1 win ;; 0 == player 2 win ;; -1 == Draw ;; 2 == continue playing ;
int ans_check(){
    total_move_cnt++;

    if(move_positions[1] == move_positions[2] && move_positions[2] == move_positions[3]){
        if(move_positions[1] == 'X'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(move_positions[4] == move_positions[5] && move_positions[5] == move_positions[6]){
        if(move_positions[4] == 'X'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(move_positions[7] == move_positions[8] && move_positions[8] == move_positions[9]){
        if(move_positions[7] == 'X'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(move_positions[1] == move_positions[4] && move_positions[4] == move_positions[7]){
        if(move_positions[1] == 'X'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(move_positions[2] == move_positions[5] && move_positions[5] == move_positions[8]){
        if(move_positions[2] == 'X'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(move_positions[3] == move_positions[6] && move_positions[6] == move_positions[9]){
        if(move_positions[3] == 'X'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(move_positions[1] == move_positions[5] && move_positions[5] == move_positions[9]){
        if(move_positions[1] == 'X'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(move_positions[3] == move_positions[5] && move_positions[5] == move_positions[7]){
        if(move_positions[3] == 'X'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(total_move_cnt == 9){
        return -1;
    }
    else{
        return 2;
    }
}


// output file
void output(){
    printf("\n\n");
    printf("===Tic-Tak-Toe===\n");
    printf("=====Muhimin=====\n\n");
    printf("  %c  |  %c  |  %c  \n", move_positions[1], move_positions[2], move_positions[3]);
    printf("----------------\n");
    printf("  %c  |  %c  |  %c  \n", move_positions[4], move_positions[5], move_positions[6]);
    printf("----------------\n");
    printf("  %c  |  %c  |  %c  \n\n", move_positions[7], move_positions[8], move_positions[9]);
}
