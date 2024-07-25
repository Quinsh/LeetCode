#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define btoe(x) (x).begin(), (x).end()
#define pb push_back

const int INF = 1e9;
const int MOD = 1e9 + 7;

/**
 * DATE: 2024.07.22
 * INTUITION: a configuration of "unique" 1-9 number for each row and column can be recorded in a map<int, set<>>,
 * for each 3x3 squares, it can be recorded in map<int, map<int, set<>>> so that when we do map[1][1], this is a 3x3 grid set.
 * We just iteratively fill the numbers and backtrack.
 * 
 * TC: O(9!^9)
 * SC: Θ(9*9), O(board size)
 * 
 * TOIMPROVE: why my algorithm is so slow? lol
 */
// Function to print the current state of the Sudoku board
void clearTerminal() {
    std::system("clear");
}

void printCurrentBoard(const vector<vector<char>>& board) {
    clearTerminal(); // Clear the terminal before printing the board

    std::this_thread::sleep_for(std::chrono::milliseconds(5)); // Delay before printing the board

    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            cout << "+-------+-------+-------+" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                cout << "| ";
            }
            cout << board[i][j] << ' ';
            if (j == 8) {
                cout << "|";
            }
        }
        cout << endl;
        if (i == 8) {
            cout << "+-------+-------+-------+" << endl;
        }
    }
}


class Solution {
private:
    map<int, set<char>> rowset, colset;
    map<int, map<int, set<char>>> grid;
    vector<vector<char>> ans;
    bool found = false;  // Flag to indicate whether a solution has been found
    long long cnt = 0;

public:
    void solveSudoku(vector<vector<char>>& board) {
        // Record the current state of the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    rowset[i].insert(board[i][j]);
                    colset[j].insert(board[i][j]);
                    int gridrow = i / 3, gridcol = j / 3;
                    grid[gridrow][gridcol].insert(board[i][j]);
                }
            }
        }
        // Start backtracking
        solve(board, 0);
        board = ans;
    }

    void solve(vector<vector<char>>& board, int p) {
        cnt++;
        printCurrentBoard(board);

        int row = p / 9;
        int col = p % 9;

        if (p == 81) {  // Solution found
            ans = board;
            found = true;
            cout << "Answer Found. Total recursion: " + to_string(cnt) << endl;
            return;
        }

        if (board[row][col] != '.') {  // Skip pre-filled cells
            solve(board, p + 1);
            return;
        }

        for (int i = 0; i < 9; i++) {
            char c = '1' + i;
            if (isRight(row, col, c)) {
                insert(row, col, c);
                board[row][col] = c;
                
                solve(board, p + 1);

                if (found) return;  // Early termination within the loop

                erase(row, col, c);
                board[row][col] = '.';
            }
        }
    }

    bool isRight(int row, int col, char x) {
        // Check if the character is already present in the row, column, or grid
        if (rowset[row].find(x) != rowset[row].end())
            return false;
        if (colset[col].find(x) != colset[col].end())
            return false;
        int gridrow = row / 3, gridcol = col / 3;
        if (grid[gridrow][gridcol].find(x) != grid[gridrow][gridcol].end())
            return false;

        return true;
    }

    void insert(int i, int j, char x) {
        rowset[i].insert(x);
        colset[j].insert(x);
        int gridrow = i / 3, gridcol = j / 3;
        grid[gridrow][gridcol].insert(x);
    }

    void erase(int i, int j, char x) {
        rowset[i].erase(x);
        colset[j].erase(x);
        int gridrow = i / 3, gridcol = j / 3;
        grid[gridrow][gridcol].erase(x);
    }
};

// Example usage
int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    Solution sol;
    sol.solveSudoku(board);
    
    return 0;
}