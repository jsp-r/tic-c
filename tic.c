#include <stdio.h>

int checkForWin(char arr[3][3], int x, int y);
void drawBoard(char arr[3][3]);
void markBoard(char arr[3][3], int x, int y, int player);


int main(void)
{
    char board[3][3] = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };


    int player = 0, turns = 0;
    int x = 0, y = 0;

    do
    {
        do
        {
            drawBoard(board);
            printf("Player %d's turn!\n", player + 1);
            printf("Select an x coordinate to place your piece: ");
            scanf("%d", &x);

            printf("Select a y coordinate to place your piece: ");
            scanf("%d", &y);
        }
        while (board[x][y] != '.' || (x > 2) || (y > 2));

        markBoard(board, x, y, player);
        player = (player + 1) % 2;
        turns++;
    }
    while (!checkForWin(board, x, y) && (turns != 9));

    if (checkForWin(board, x, y))
    {
        drawBoard(board);
        printf("Player %d wins!\n", ((player + 1) % 2));
    }
    else
    {
        printf("Draw!\n");
    }

}

void drawBoard(char arr[3][3])
{
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            printf("   0  1  2\n");
            continue;
        }
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                printf("%d  ", (i - 1));
            }
            else
            {
                printf("%c  ", arr[i - 1][j - 1]);
            }

        }
        printf("\n\n");
    }
}

void markBoard(char arr[3][3], int x, int y, int player)
{
    char piece = 'o';

    if (player)
    {
        piece = 'x';
    }

    arr[x][y] = piece;

}



int checkForWin(char arr[3][3], int x, int y)
{
    // check horizontal
    if ((arr[x][y] == arr[x][(y + 1) % 3]) && (arr[x][y] == arr[x][(y + 2) % 3]) && (arr[x][y] != '.'))
    {
        return 1;
    }

    // check vertical
    else if ((arr[x][y] == arr[(x + 1) % 3][y]) && (arr[x][y] == arr[(x + 2) % 3][y]) && (arr[x][y] != '.'))
    {
        return 1;
    }

    // check L-R diagonal
    else if ((arr[x][y] == arr[(x + 1) % 3][(y + 1) % 3]) && (arr[x][y] == arr[(x + 2) % 3][(y + 2) % 3]) && (arr[x][y] != '.'))
    {
        return 1;
    }

    // check R-L diagonal
    else if ((arr[x][y] == arr[(x + 1) % 3][(y - 1) % 3]) && (arr[x][y] == arr[(x + 2) % 3][(y - 2) % 3]) && (arr[x][y] != '.'))
    {
        return 1;
    }

    return 0;
}