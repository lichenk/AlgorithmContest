/*
Li Chen Koh's solution to Google Code Jam Round 2 2018 Problem D
This is adapted from my original submission during the contest.


Full problem statement:
https://codejam.withgoogle.com/2018/challenges/0000000000007706/dashboard/00000000000459f4


Problem summary:

You are given a 2D grid of black and white cells G_0 of dimensions up to 20x20.
Given G_i, you can produce G_i+1 by replacing each white cell with a 2x2 grid
of white cells, and each black cell with a 2x2 grid of black cells.
A pattern is a four-connected subset of cells in G_0. (In other words: A
pattern consists of a single group of cells connected by shared edges (shared
corners do not count as connections), plus their colors. A pattern might
contain internal gaps (as long as the pattern's cells are a single connected
group); such gaps are not considered part of the pattern.)
A pattern P is present in G_i if and only if you can translate P by a 2D
integer vector such that it overlays a region in G_i, and each cell in
P has the same color as the unique cell in G_i that it overlaps with.
You want to find the largest pattern that is present in at least 10^100 of the
infinite set of grids {G_0, G_1, G_2, ...}.


Solution:
Once the starting grid G_0 is transformed a sufficient number (5) times, the
pattern must match some transformed 2x2 subgrid of the original starting grid.

Thus, we just need to try every 2x2 subgrid in the G_0, blow it up by expanding
each cell, and then try every possible translation with a 2D integer vector,
and then overlay it on the starting grid again. We then want to find the
largest four-connected subset where the colors match.
*/

#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
const int MAXN=21;
string startingGrid[MAXN];
int numberOfRows, numberOfColumns;
bitset<MAXN> match[MAXN];
bitset<MAXN> seen[MAXN];

int deltaX[] = {1, 0, -1, 0};
int deltaY[] = {0, 1, 0, -1};

// We use the notation where the x-coordinate refers to the row number, and
// the y-coordinate refers to the column number.

// Returns true iff the input cell coordinates is a valid cell in the grid.
bool valid(int x, int y) {
	return (0 <= x && x < numberOfRows) && (0 <= y && y < numberOfColumns);
}

// Counts the number of valid matching cells that are reachable from cell
// located at row x and column y.
int dfs(int x, int y) {
	if (seen[x][y] || match[x][y]==false) return 0;
	int ans=1;
	seen[x][y]=true;
	for (int direction = 0; direction < 4; direction++) {
		int newX=x+deltaX[direction], newY=y+deltaY[direction];
		if (valid(newX, newY)) {
			ans+=dfs(newX, newY);
		}
	}
	return ans;
}

void solve(int testCaseNumber) {
	cin >> numberOfRows >> numberOfColumns;
	for (int x = 0; x < numberOfRows; x++) cin>>startingGrid[x];
	// Generate all possible 2x2 subgrids of the starting grid.
	set<string> twoByTwoSubgrids;
	for (int x=-1;x<=numberOfRows;x++) for (int y=-1;y<=numberOfColumns;y++) {
		string s;
		s.resize(4);
		for (int i = 0; i < 4; i++) {
			s[i] = '.';
		}
		for (int pos = 0; pos < 4; pos++) {
			/*
			We basically lay out the 2x2 grid as:
			01
			23
			Thus (pos & 1) gives exactly the x-displacement, and (pos >> 1) gives the y-displacement.
			*/
			int newX = x + (pos & 1);
			int newY = y + (pos >> 1);
			if (valid(newX, newY)) {
				s[k]=startingGrid[newX][newY];
			}
		}
		twoByTwoSubgrids.insert(s);
	}
	int answer = 0;
	for (const string &twoByTwoSubgrid: twoByTwoSubgrids) {
		for (int boundaryX = -1; boundaryX <= numberOfRows; boundaryX++) {
			for (int boundaryY = -1; boundaryY <= numberOfColumns; boundaryY++) {
				// Reset global state for DFS
				for (int x = 0; x < numberOfRows; x++) {
					match[x].reset();
					seen[x].reset();
				}
				for (int x = 0; x < numberOfRows; x++) {
					for (int y = 0; y < numberOfColumns; y++) {
						int twoByTwoSubgridIdx=((y>boundaryY)?2:0)|((x>boundaryX)?1:0);
						// match[x][y] is true if and only if the 2x2 subgrid transforms
						// into startingGrid with boundary lines at boundaryX and boundaryY.
						match[x][y] = (startingGrid[x][y] == twoByTwoSubgrid[twoByTwoSubgridIdx]);
					}
				}
				for (int x = 0; x < numberOfRows; x++) {
					for (int y = 0; y < numberOfColumns; y++) {
						if (match[x][y]&&(!seen[x][y])) {
							answer = max(answer, dfs(x,y));
						}
					}
				}
			}
		}
	}
	printf("Case #%d: %d\n",testCaseNumber, answer);
}

int main() 
{
  int numberOfTests; cin>>numberOfTests;
  for (int testCaseNumber = 1; testCaseNumber <= numberOfTests;testCaseNumber++) {
    solve(testCaseNumber);
  }
}
