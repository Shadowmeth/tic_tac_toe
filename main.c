#include <stdio.h>
#include <stdlib.h>

/*
 *  1 | 2 | 3
 *  4 | 5 | 6
 *  7 | 8 | 9
 *
 */

int isDraw(char *board) {
    char is_draw = 1;

    for (; *board != '\0'; board++) {
        if (*board >= '1' && *board <= '9')
            is_draw = 0;
    }

    return (int)is_draw;
}

void processInput(char *board, int input, char p_turn) {
    
    // This can be optimized to a single statement (lookup row major order and coloumn major order)
    char char_to_place = (p_turn == 1) ? 'O' : 'X';
    switch(input) {
        case 1:
            board[0] = char_to_place;
            break;

        case 2:
            board[4] = char_to_place;
            break;

        case 3:
            board[8] = char_to_place;
            break;

        case 4:
            board[10] = char_to_place;
            break;

        case 5:
            board[14] = char_to_place;
            break;

        case 6:
            board[18] = char_to_place;
            break;

        case 7:
            board[20] = char_to_place;
            break;

        case 8:
            board[24] = char_to_place;
            break;

        case 9:
            board[28] = char_to_place;
            break;

        default: 
            printf("Invalid number entered. Exiting!");
            exit(1);
    }

}

int isGameOver(char *board) {
    if      (((board[0] == 'O')  && (board[10] == 'O') && (board[20] == 'O'))  || /* Column 1 */
            ((board[4] == 'O')  && (board[14] == 'O') && (board[24] == 'O'))   || /* Column 2 */
            ((board[8] == 'O')  && (board[18] == 'O') && (board[28] == 'O'))   || /* Column 3 */
            ((board[0] == 'O')  && (board[4] == 'O')  && (board[8] == 'O'))    || /* Row 1 */
            ((board[10] == 'O') && (board[14] == 'O') && (board[18] == 'O'))   || /* Row 2 */
            ((board[20] == 'O') && (board[24] == 'O') && (board[28] == 'O'))   || /* Row 3 */
            ((board[0] == 'O')  && (board[14] == 'O') && (board[28] == 'O'))   || /* Diagonal 1 */
            ((board[8] == 'O')  && (board[14] == 'O') && (board[20] == 'O')))   /* Diagonal 2 */
    {
        printf("%s", board);
        printf("Player one wins!\n");
        return 1;
    } else if
        (((board[0] == 'X')  && (board[10] == 'X') && (board[20] == 'X'))  || /* Column 1 */
                ((board[4] == 'X')  && (board[14] == 'X') && (board[24] == 'X'))   || /* Column 2 */
                ((board[8] == 'X')  && (board[18] == 'X') && (board[28] == 'X'))   || /* Column 3 */
                ((board[0] == 'X')  && (board[4] == 'X')  && (board[8] == 'X'))    || /* Row 1 */
                ((board[10] == 'X') && (board[14] == 'X') && (board[18] == 'X'))   || /* Row 2 */
                ((board[20] == 'X') && (board[24] == 'X') && (board[28] == 'X'))   || /* Row 3 */
                ((board[0] == 'X')  && (board[14] == 'X') && (board[28] == 'X'))   || /* Diagonal 1 */
                ((board[8] == 'X')  && (board[14] == 'X') && (board[20] == 'X')))   /* Diagonal 2 */
    {
        printf("%s", board);
        printf("Player two wins!\n");
        return 1;
    } else if (isDraw(board)) {
        printf("Draw!\n");
        return 1;
    }

    return 0;
}

int main() {
    char board[] = "1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9\n\n";
    int inp;
    char p_turn = 1;

    printf("---------- WELCOME TO TIC TAC TOE BY SYED KUMAIL HUSSAIN SHERAZI ----------\n");
    printf("O for P1, X for P2\n\n");

    while(!isGameOver(board)) {
        printf("%s", board);
        printf("Player %s's turn: ", p_turn == 1 ? "one" : "two");
        scanf(" %d", &inp);    
        processInput(board, inp, p_turn);
        (p_turn == 1) ? p_turn++ : p_turn--;
        printf("\n");
    }

    return 0;
}
