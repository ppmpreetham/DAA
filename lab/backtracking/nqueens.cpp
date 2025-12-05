#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, int n){
    // col
    for(int i = 0; i < n; i++)
        if (board[i][col] == "Q") return false;

    // upper-left
    for(int i = row - 1; j = col - 1; i>=0 && j>=0; i--; j--)
        if (board[i][j] == "Q") return false;

    // upper-right
    for(int i = row-1; j = 0; i>=0 && j<=n-1; i--; j++)
        if (board[i][j] == "Q") return false;

    return false;
}

void backtrack(int row, vector<string>&board, vector<vector<string>>& res, int n){
    if (row == n) { // base case
        res.push_back(board);
        return;
    }

    for(int col = 0; col < n; col ++){ // choices -> all boxes in a row
        if (!isSafe) continue; // constraint
        board[row][col] = "Q" // make choice
        backtrack(row + 1, board, res, n);
        board[row][col] = "" // undo choice
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    backtrack(0, board, res, n);
    return res;
}

int main() {
    int n = 4;
    auto res = solveNQueens(n);
    for (auto& board : res) {
        for (auto& row : board) cout << row << "\n";
        cout << "\n";
    }
}
