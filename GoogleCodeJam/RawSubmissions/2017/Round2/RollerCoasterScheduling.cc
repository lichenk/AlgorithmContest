/*
Li Chen Koh's solution to Google Code Jam Round 2 2017 Problem B
This is adapted from my original submission during the live contest.


Full Problem Statement:

https://code.google.com/codejam/contest/5314486/dashboard#s=p1&a=0


Problem Summary:

You have a roller coaster that has N seats numbered 1 through N from front to
back.
There are C customers and M tickets in total.
Each ticket is assigned to a customer and seat.
A customer may buy any number of tickets.
For each ticket, you may choose to replace its assigned seat number with a
smaller seat number. This is called a promotion.
To honor all the tickets, you may need to have multiple roller coaster rides.
You want to minimize the number of roller coaster rides required to honor all
tickets.
As a secondary objective, you want to minimize the number of promotions.


Constraints: 2 <= N, C <= 1000, 1 <= M <= 1000


Solution:

We have 2 lower bounds on the number of rides R:
(1) The number of tickets bought by a single customer must not exceed R
(2) The number of tickets with seat number less than or equal to k must not
exceed R * k
The number of promotions P has a simple lower bound too:
(3) The number of tickets assigned to a single seat must not exceed R by more
than P.
It turns out both of these lower bounds are tight, but the proof is relatively
complicated.

Runtime: O(N + C + M)
Memory usage: O(N + C)
*/

#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

// We are given the following parameters:
// The first parameter is vector<int> seatIdToNumberOfTickets:
// seatIdToNumberOfTickets[seatId] is the number of tickets assigned to the
// seat with seatId as its ID.
// The second paramter is vector<int> customerIdToNumberOfTickets:
// seatIdToNumberOfTickets[customerId] is the number of tickets assigned to
// customer with customerId as their ID.
// 
// This function computes the minimum number of rides needed to honor all
// seats as a primary objective, and minimizes the number of promotions as
// a secondary objective.
// The return value is a pair of integers: The first integer is the number
// of rides, and the second integer is the number of promotions.

pair<int,int> getMinimumRidesAndPromotions(
  const vector<int> &seatIdToNumberOfTickets,
  const vector<int> &customerIdToNumberOfTickets
) {
  int numberOfSeats = (int)seatIdToNumberOfTickets.size() - 1;
  int numberOfCustomers = (int)customerIdToNumberOfTickets.size() - 1;
  int ridesNeeded=0;
  for (int customerId = 1; customerId <= numberOfCustomers; customerId++) {
    ridesNeeded = max(ridesNeeded, customerIdToNumberOfTickets[customerId]);
  }
  int sumOfTicketsUpToSeatId = 0;
  for (int seatId = 1; seatId <= numberOfSeats; seatId++) {
    sumOfTicketsUpToSeatId += seatIdToNumberOfTickets[seatId];
    ridesNeeded = max(
      ridesNeeded,
      (sumOfTicketsUpToSeatId + seatId - 1) / seatId
    );
  }
  int promotionsNeeded=0;
  for (int seatId = 1; seatId <= numberOfSeats; seatId++) {
    promotionsNeeded += max(0, seatIdToNumberOfTickets[seatId] - ridesNeeded);
  }
  return make_pair(ridesNeeded, promotionsNeeded);
}

// We read the test case from standard input, and return a pair of vector<int>
// The first vector<int> is seatIdToNumberOfTickets:
// seatIdToNumberOfTickets[seatId] is the number of tickets assigned to the
// seat with seatId as its ID.
// The second vector<int> is customerIdToNumberOfTickets
// seatIdToNumberOfTickets[customerId] is the number of tickets assigned to
// customer with customerId as their ID.
pair<vector<int>, vector<int> > readInput() {
  int numberOfSeats, numberOfCustomers, numberOfTickets;
  scanf("%d%d%d", &numberOfSeats, &numberOfCustomers, &numberOfTickets);
  vector<int> seatIdToNumberOfTickets(numberOfSeats + 1, 0);
  vector<int> customerIdToNumberOfTickets(numberOfCustomers + 1, 0);
  for (int ticketId = 0; ticketId < numberOfTickets; ticketId++) {
    int seatId, customerId;
    scanf("%d%d", &seatId, &customerId);
    seatIdToNumberOfTickets[seatId]++;
    customerIdToNumberOfTickets[customerId]++;
  }
  return make_pair(seatIdToNumberOfTickets, customerIdToNumberOfTickets);
}

int main()
{
  int numberOfTests; scanf("%d",&numberOfTests);
  for (int testNumber=1;testNumber<=numberOfTests;testNumber++) {
    const pair<vector<int>, vector<int> > &input = readInput();
    pair<int,int> minimumRidesAndPromotions = getMinimumRidesAndPromotions(
      input.first, input.second);
    int ridesNeeded = minimumRidesAndPromotions.first;
    int promotionsNeeded = minimumRidesAndPromotions.second;
    printf("Case #%d: %d %d\n", testNumber, ridesNeeded, promotionsNeeded);
  }
}
