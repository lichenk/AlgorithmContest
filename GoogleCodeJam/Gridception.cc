/*
Li Chen Koh's solution to Google Code Jam Round 2 2018 Problem D "Gridception"
This is adapted from my original submission during the live contest.


Full problem statement:
1. Go to https://codejam.withgoogle.com/2018/challenges
2. Click on "Round 2" problems
3. Click on "Gridception"


Problem summary:

You are given a 2D grid of black and white cells in the starting grid G_0 of
dimensions up to 20x20.

Given a grid G, you can expand it into a grid H by replacing each white cell in
G with a 2x2 grid of white cells, and each black cell in G with a 2x2 grid of
black cells. The resulting grid H has double the width and height of grid G.
We call H the expanded version of G.

We define G_1 as the expanded version of G_0, G_2 as the expanded version of
G_1, ..., and so on.

A pattern is a four-connected subset of cells in the starting grid G_0.
(In other words: A pattern consists of a single group of cells connected by
shared edges (shared corners do not count as connections), plus their colors.
A pattern might contain internal gaps (as long as the pattern's cells are a
single connected group); such gaps are not considered part of the pattern.)

A pattern P is present in a grid G if and only if:
(1) You overlay P on G such that each cell in P overlaps exactly one unique
cell in G, and,
(2) Each cell in P is the same color as the cell in G that it overlaps.

You want to find the size of the largest pattern that is present in at least 
a googol (10^100) of the infinite set of grids {G_1, G_2, G_3, ...}. The
pattern must also be present in the starting grid G_0.


Solution:
Once the starting grid G_0 is expanded a sufficient number (5) times, the
pattern must match some expanded 2x2 subgrid of the original starting grid.

Thus, we just need to try every 2x2 subgrid in the G_0, blow it up by expanding
each cell until the subgrid is twice as large as G_0.
We then try every possible way to overlay it on the starting grid by
performaing an integer geometric translation.
Finally, we find the largest four-connected subset where the colors match.

Runtime: O(S^3) where S is the size of the input grid.
Memory usage: O(S) where S is the size of the input grid.
*/

#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
const int MAXN=21;

// Global state for our depth-first search.
bitset<MAXN> match[MAXN];
bitset<MAXN> seen[MAXN];

// Describes the 4 cardinal directions: North, East, West and South.
// This is used in the depth-first search to simplify the neighbor-finding loop
const int deltaRow[] = {1, 0, -1, 0};
const int deltaColumn[] = {0, 1, 0, -1};

// We are given the following parameters: The input row and column, as well as
// the total number of rows and columns in the starting grid.
// This function returns true iff the input cell coordinates is within bounds.
bool withinBounds(int row, int column, int numberOfRows, int numberOfColumns) {
  return (
    (0 <= row && row < numberOfRows) &&
    (0 <= column && column < numberOfColumns)
  );
}

// We are given the following parameters: The input row and column, as well as
// the total number of rows and columns in the starting grid.
// This function returns the number of withinBounds matching cells that are
// reachable from cell located at the input row and column.
int dfs(int row, int column, int numberOfRows, int numberOfColumns) {
  if (seen[row][column] || match[row][column]==false) return 0;
  int ans=1;
  seen[row][column]=true;
  for (int direction = 0; direction < 4; direction++) {
    int newRow = row + deltaRow[direction];
    int newColumn = column + deltaColumn[direction];
    if (withinBounds(newRow, newColumn, numberOfRows, numberOfColumns)) {
      ans += dfs(newRow, newColumn, numberOfRows, numberOfColumns);
    }
  }
  return ans;
}

// Consider all grids which can be formed by expanding the input starting grid.
// This function returns the maximum pattern size such that the pattern matches
// at least a googol (10^100) these grids.
// Preconditions: The number of rows and columns must not be 0.
int getMaximumPatternSize(const vector<string> &startingGrid) {
  int numberOfRows = (int)startingGrid.size();
  assert(numberOfRows > 0);
  int numberOfColumns = (int)startingGrid[0].size();
  assert(numberOfColumns > 0);

  // Generate all possible 2x2 subgrids of the starting grid.
  set<string> twoByTwoSubgrids;
  for (int row = -1;row <= numberOfRows; row++) {
    for (int column = -1; column <= numberOfColumns; column++) {
      string twoByTwoSubgrid(4, '.');
      int position = 0;
      for (int newRow = row; newRow <= row+1; newRow++) {
        for (int newColumn = column; newColumn <= column + 1; newColumn++) {
          if (withinBounds(newRow, newColumn, numberOfRows, numberOfColumns)) {
            twoByTwoSubgrid[position] = startingGrid[newRow][newColumn];
          }
          position++;
        }
      }
      twoByTwoSubgrids.insert(twoByTwoSubgrid);
    }
  }

  int answer = 0;
  // Try every possible 2x2 subgrid
  for (const string &twoByTwoSubgrid: twoByTwoSubgrids) {
    // Try every possible geometric translation by 2D integer vectors
    for (int boundaryRow = -1; boundaryRow <= numberOfRows; boundaryRow++) {
      for (int boundaryColumn = -1; boundaryColumn <= numberOfColumns; \
        boundaryColumn++) {
        // Reset global state for DFS
        for (int row = 0; row < numberOfRows; row++) {
          match[row].reset();
          seen[row].reset();
        }

        // Initialize DFS graph
        for (int row = 0; row < numberOfRows; row++) {
          for (int column = 0; column < numberOfColumns; column++) {
            int position = 0;
            if (row > boundaryRow) {
              position += 1;
            }
            if (column > boundaryColumn) {
              position += 2;
            }
            // match[row][column] is true if and only if the expanded 2x2
            // subgrid matches startingGrid colors with boundary lines at
            // boundaryRow and boundaryColumn.
            match[row][column] = (
              startingGrid[row][column] == twoByTwoSubgrid[position]
            );
          }
        }

        // Perform DFS to find maximum connected component
        for (int row = 0; row < numberOfRows; row++) {
          for (int column = 0; column < numberOfColumns; column++) {
            if (match[row][column] && (!seen[row][column])) {
              answer = max(
                answer,
                dfs(row, column, numberOfRows, numberOfColumns)
              );
            }
          }
        }
      }
    }
  }
}

// Reads a test case data, which is the 2D starting grid.
vector<string> readStartingGrid() {
  int numberOfRows, numberOfColumns;
  cin >> numberOfRows >> numberOfColumns;
  vector<string> startingGrid(numberOfRows);
  for (int row = 0; row < numberOfRows; row++) {
    cin>>startingGrid[row];
  }
  return startingGrid;
}

int main()
{
  int numberOfTests; cin>>numberOfTests;
  for (int testNumber = 1; testNumber <= numberOfTests; testNumber++) {
    const vector<string> startingGrid = readStartingGrid();
    int maximumPatternSize = getMaximumPatternSize(startingGrid);
    printf("Case #%d: %d\n",testNumber, maximumPatternSize);
  }
}
