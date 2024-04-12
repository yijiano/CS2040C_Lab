#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
// You can include/import any library/packages

using namespace std;

void partyGoing(string filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        cout << "File not found!" << endl;
        return;
    }

    int numStudents, numFriendships, you, firstGo;
    f >> numStudents >> numFriendships >> you >> firstGo;

    vector<vector<int>> adjList(numStudents + 1);
    vector<int> friendsCount(numStudents + 1, 0);
    vector<bool> going(numStudents + 1, false);  // Vector to track who decides to go

    // Read friendships and construct the adjacency list
    for (int i = 0; i < numFriendships; i++) {
        int a, b;
        f >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        friendsCount[a]++;
        friendsCount[b]++;
    }

    queue<int> q;
    vector<bool> visited(numStudents + 1, false);

    // Start with the first student who decides to go
    going[firstGo] = true;
    q.push(firstGo);
    visited[firstGo] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                // Count how many of this student's friends are going
                int goingCount = 0;
                for (int friendId : adjList[neighbor]) {
                    if (going[friendId]) {
                        goingCount++;
                    }
                }

                // If half or more friends are going, they decide to go
                if (goingCount >= (friendsCount[neighbor] + 1) / 2) {
                    going[neighbor] = true;
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    // Output the results
    cout << "For the file input of \"" << filename << "\"." << endl;
    if (going[you]) {
        cout << you << " will go for the party" << endl;
    }
    else {
        cout << you << " will not go for the party" << endl;
    }

    cout << "Classmate(s) who will go to the party is/are:" << endl;
    for (int i = 1; i <= numStudents; ++i) {
        if (going[i]) {
            cout << i << " ";
        }
    }
    cout << endl;  // Print new line for clarity/formatting
}