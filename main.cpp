//
// Created by Naveen on 19-12-2021.
//




// include header files
#include <iostream>
#include <bits/stdc++.h>
#include "shannons.cpp"
using namespace std;

// Driver code
int main()
{
    int n, i, j, index;
    float total = 0;
    string ch;
    node temp;
    char s[100];
    shannons obj;

//    cout << "Enter the radix: \n";
//    cin>>index;

    // Input number of symbols
    cout << "Enter number of symbols:\n ";
    cin>>n;
//    cout << n << endl;

    // Input symbols
    for (i = 0; i < n; i++) {
        cout << "Enter symbol " << i + 1 << " : ";
        cin>>s[i];

        // Insert the symbol to node
        p[i].sym += s[i];
    }

    // Input probability of symbols
    float x[n];
    for (i = 0; i < n; i++) {
        cout << "\nEnter probability of " << p[i].sym << " : ";
        cin>>x[i];
        // Insert the value to node
        p[i].probability = x[i];
        total = total + p[i].probability;

        // checking max probability
        if (total > 1) {
            cout << "Invalid. Enter new values";
            total = total - p[i].probability;
            i--;
        }
    }

    p[i].probability = 1 - total;

    // Sorting the symbols based on their probability
    obj.sortByProbability(n, p);

    for (i = 0; i < n; i++) {
        p[i].top = -1;
    }
    // Find the shannon code
    obj.shannon(0,n - 1, p); // h is number of symbols-1
double entropy = obj.calcEntropy(n, p);
    obj.calcEntropy(n, p);
double len=obj.calcLength(n, p);
    obj.calcEfficiency(n, p);
    // Display the codes
    obj.display(n, p);
    return 0;
}