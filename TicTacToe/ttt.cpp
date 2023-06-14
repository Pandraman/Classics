#include <iostream>
#include <string.h>

using namespace std;

struct Grid {
    int data[3][3];
};
void draw(int[][3], char[]);
Grid select(int grid[][3], int player);


int main() {
    char idx[3] = {'-','X','O'};
    int grid[3][3]= {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    
    
        cout << "Player 1 symbol: " << endl;
        cin >> idx[1];
        cout << "Player 2 symbol: " << endl;
        cin >> idx[2];
    draw(grid, idx);

    

    int player = 1;
    int winner = 0;
    bool win = false;
    //          LOOP            //    

    do{
        select(grid, player);
        draw(grid, idx);

        if(player == 1){
            player = 2;
        }
        else if(player == 2){
            player = 1;
        }
    }
    while(!win);
    
    return 0;
}

void draw(int grid[][3], char idx[]) {
    cout << "   A  B  C" << endl;

    for (int i = 0; i < 3; i++) {
        cout << i+1 << "  ";
        for (int j = 0; j < 3; j++) {
            cout << idx[grid[i][j]] << "  ";
        
        }
        cout << endl;
    }
}



Grid select(int grid[3][3], int player) {
    cout << "player " << player << endl;
    cout << "Select Row (A B C)" << endl;
    bool free = false;
    int R;
    int C;
    while (!free) {
        bool check = false;
        int row = 0;
        int col = 0;
        char temp;
        cin >> temp;
        temp = toupper(temp);
        do{
            switch (temp)
            {
                case 'A':
                    row = 0;
                    check = true;
                    break;
                case 'B':
                    row = 1;
                    check = true;
                    break;
                case 'C':
                    row = 2;
                    check = true;
                    break;
                case 'X':
                    cin >> temp;
                    break;
                default:
                    cout << "invalid input" << endl;
                    temp = 'X';
                    break;
            }
        }
        while(check == false);
        while ( 0 > col or 2<col) {
            cout << "Select Column (1 2 3)";
            cin >> col;
            col -= 1;
            if(0 > col || 2 < col){
                cout << "invalid input" << endl;
            }
        }
        if (grid[col][row] == 0) {
            free = true;
            C = col;
            R = row;
        }
        else {
            cout << "invalid input" << endl;
            break;
        }
    }
    grid[C][R] = player;
    Grid G;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            G.data[i][j] = grid[i][j];
        }
    }
    return G;
}