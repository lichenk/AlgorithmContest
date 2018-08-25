/*
Li Chen Koh's solution to Google Code Jam Round 3 2018 Problem A "Field Trip"
This is adapted from my original submission during the live contest.


Full problem statement:
1. Go to https://codejam.withgoogle.com/2018/challenges
2. Click on "Round 3" problems
3. Click on "Field Trip"

Problem summary:

The teacher is assigned the number ID 1, and the kids are numbered 2 through N.

Each person is at an integer point on a 2D grid.

An action taken by a person consists of either moving to one of the 8 cells
sharing at least one edge or corner with that person's current cell, or
choosing to remain in their current cell.

First, the teacher takes an action, as described above. It is up to the
teacher to decide where, if anywhere, to move.

Then, each kid takes an action, starting with kid 2, and so on up to kid N;
the i-th kid does not take their action until the (i-1)th person has taken
their action. The kids' actions are deterministic: the i-th kid must choose
the option that minimizes the center-to-center distance from their cell to
the cell of the (i-1)th person. This is never ambiguous; one of the 9 options
will uniquely minimize that distance.

Compute the minimum number of turns the teacher needs to gather everyone
into 1 cell.


Solution:

Let's solve a simpler version of this problem: If the teacher and kids are all
on a horizontal line, what is the minimum number of turns required? This is the
one-dimensional version of the original 2D problem.

Clearly, the answer cannot be less than the number of turns required for the
leftmost person and the rightmost person to reach each other.
It turns out that this lower bound is tight:
The teacher can move towards the midpoint between these leftmost person and
the rightmost person. The number of turns is the distance between these two
people divided by 2, rounded up if necessary.

This inspires our solution to the original problem. The teacher must move to
the midpoint of the lowest x-coordinate and the highest x-coordinate, and the
midpoint of the lowest y-coordinate and the highest y-coordinate. This solution
is optimal, since otherwise we would not have enough turns for either the
extremal points in x-coordinates to reach each other, or the extremal points in
y-coordinates to reach each other.


My solution takes O(N) runtime, and O(N) memory, where N is the number of people.
It could take O(1) memory if I combine my readPoints and getMinimumTurns function,
but I separated them out for clarity.
*/

#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

// This represents a 2D point with integer row and column coordinates.
class Point {
public:
  int row, column;
  Point() {
    row = 0;
    column = 0;
  }
  Point(int initialRow, int initialColumn) {
    row = initialRow;
    column = initialColumn;
  };
};


// Given a nonempty vector of 2D points representing the locations of the
// teacher and children, we return the minimum number of turns required for
// everyone to end up on the same point.
int getMinimumTurns(const vector<Point> &points) {
  int numberOfPoints = (int)points.size();
  assert(numberOfPoints >= 1);
  int lowestRow, highestRow, lowestColumn, highestColumn;
  for (int pointIndex = 0; pointIndex < numberOfPoints; pointIndex++) {
    int row = points[pointIndex].row, column = points[pointIndex].column;
    if (pointIndex == 0) {
      lowestRow = highestRow = row;
      lowestColumn = highestColumn = column;
    }
    else {
      lowestRow = min(lowestRow, row);
      highestRow = max(highestRow, row);
      lowestColumn = min(lowestColumn, column);
      highestColumn = max(highestColumn, column);     
    }
  }
  // Compute number of turns to reach the midpoint, rounded up.
  int minimumTurnsNeeded = (max(
    highestRow - lowestRow,
    highestColumn - lowestColumn
  ) + 1) / 2;
  return minimumTurnsNeeded;
}


// Reads the input for one test case from standard input.
// Returns a vector of 2D points represneting the locations of the teacher and children.
vector<Point> readPoints() {
  int numberOfPoints;
  cin >> numberOfPoints;
  vector<Point> points(numberOfPoints);
  for (int pointIndex = 0; pointIndex < numberOfPoints; pointIndex++) {
    int row, column;
    cin >> row >> column;
    points[pointIndex] = Point(row, column);
  }
  return points;
}

int main()
{
  int numberOfTests; cin>>numberOfTests;
  for (int testNumber = 1; testNumber <= numberOfTests; testNumber++) {
    const vector<Point> &points = readPoints();
    int minimumTurnsNeeded = getMinimumTurns(points);
    printf("Case #%d: %d\n", testNumber, minimumTurnsNeeded);
  }
}
