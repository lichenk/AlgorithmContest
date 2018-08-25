/*
Li Chen Koh's solution to Google Code Jam 2017 Round 2 Problem A "Fresh Chocolate"
This is adapted from my original submission during the live contest.

Full problem statement:
https://code.google.com/codejam/contest/5314486/dashboard#s=p0

Problem summary:
You have infinitely many packs that contain P pieces of chocolate.

There are N groups of people who are visiting on N distinct days. Group i
has a specific number of people, specified in the input as G_i.

You may choose which day each group visits. There are N! choices
in total.

When each group visits, you must give each person 1 piece of chocolate.
If there are leftover pieces from one group, they must be used with the next
tour group before opening up any new packs.

You would like to maximize the number of groups such that everyone in the group
receives chocolate from packs that were opened on the same day as their visit.

Limits: 1 <= N, G_i <=100. 1 <= P <= 4.

Solution:

We realize that a group of size S is basically the same as a group of size
S + P.

This allows us to use dynamic programming/recursion.

Define f(vector<int> C, int l) as the maximum answer such that we have C[S]
groups such that their group size is congruent to S modulo P, and we have l
 leftovers pieces.

Our recursion step is simply the following:
Let us remove a group with size congruent to S modulo P.
Then our leftover pieces must decrease by S modulo P.
If we have 0 leftover pieces, then we are giving fresh chocolate to this
group, so we increment the result by 1.

Runtime is O((P^3)*(n^P)).
Memory usage is O((P^2)*(n^P)).
*/
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

// Preallocate DP array so we can use it across all test cases. Otherwise,
// memory allocation is very slow.
const int MAXP = 4;
const int MAXN = 101;
// dpTable[leftoverPieces][groupCountId] is the maximum number of groups
// that have a freshly opened pack, if you have leftoverPieces chocolates
// leftover, and you have a configuration of groups that has id groupCountId
int dpTable[MAXP][MAXN*MAXN*MAXN*MAXN];

// Converts a vector of groupCounts to a unique integer ID that is between
// 0 and MAXN^4 - 1. We use this to index into dpTable.
int getGroupCountId(const vector<int> &groupCounts) {
  int groupCountId = 0;
  for (const int groupCount: groupCounts) {
    groupCountId *= MAXN;
    groupCountId += groupCount;
  }
  return groupCountId;
}

// Given the following parameters:
// groupCounts[S] is the number of groups such that their group size is
// congruent to S modulo P.
// leftoverPieces is the number of leftover chocolates we have
// piecesPerPack is the number of chocolate pieces in each pack
// This function returns the maximum number of groups such that everyone in
// the group received a freshly opened pack on the same day.
int getMaximumNumberOfGroupsWithFreshPacks(
  const vector<int> &groupCounts,
  const int leftoverPieces,
  const int piecesPerPack
) {
  // If we've computed this before, then we can return the memoized value.
  int groupCountId = getGroupCountId(groupCounts);
  if (dpTable[leftoverPieces][groupCountId] != -1) {
    return dpTable[leftoverPieces][groupCountId];
  }

  // Recursion step
  int numberOfGroups = 0;
  for (int sizeModuloP = 0; sizeModuloP < piecesPerPack; sizeModuloP++) {
    numberOfGroups += groupCounts[sizeModuloP];
  }
  int maximumGroupsWithFreshPacks = 0;
  if (numberOfGroups > 0) {
    for (int sizeModuloP = 0; sizeModuloP < piecesPerPack; sizeModuloP++) {
      if (groupCounts[sizeModuloP] > 0) {
        // The vector<int> allocation here is expensive. My original contest
        // submission actually passes 4 integers instead of a vector<int>.
        vector<int> newGroupCounts = groupCounts;
        newGroupCounts[sizeModuloP]--;
        maximumGroupsWithFreshPacks = max(
          maximumGroupsWithFreshPacks,
          getMaximumNumberOfGroupsWithFreshPacks(
            newGroupCounts,
            (leftoverPieces + piecesPerPack - sizeModuloP) % piecesPerPack,
            piecesPerPack
          )
        );
      }
    }
  }

  // Did we open new packs for everyone in this group?
  if (leftoverPieces == 0) maximumGroupsWithFreshPacks++;
  // Save value to DP table.
  dpTable[leftoverPieces][groupCountId] = maximumGroupsWithFreshPacks;
  return maximumGroupsWithFreshPacks;
}

int main()
{
  int numberOfTests; scanf("%d", &numberOfTests);
  for (int testNumber = 1; testNumber <= numberOfTests; testNumber++) {
    int numberOfGroups, piecesPerPack;
    scanf("%d%d", &numberOfGroups, &piecesPerPack);
    vector<int> groupCounts(4, 0);
    for (int groupIndex = 0; groupIndex < numberOfGroups; groupIndex++) {
      int numberOfPeopleInGroup;
      scanf("%d",&numberOfPeopleInGroup);
      groupCounts[numberOfPeopleInGroup % piecesPerPack]++;
    }
    for (int pieces = 0; pieces < piecesPerPack; pieces++) {
      // Fill dpTable with 0xff bytes, which is equal to -1 casted as int.
      // memset is very fast as it uses SSE instructions.
      memset(dpTable[pieces], -1, sizeof dpTable[pieces]);
    }
    int ans = getMaximumNumberOfGroupsWithFreshPacks(
      groupCounts, 0, piecesPerPack);
    printf("Case #%d: %d\n", testNumber, ans);
  }
}
