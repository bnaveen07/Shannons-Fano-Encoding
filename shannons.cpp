//
// Created by Naveen on 20-12-2021.
//

//#include "shannons.h"
#include<array>
using namespace std;

// declare structure node
struct node {
    // for storing symbol
    std::string sym;
    // for storing probability
    float probability;
    int arr[20];
    int top; // for storing top of stack i.e, code
} p[20]; // array of nodes to store symbols and their probabilities



//class shannonsForRadix3;

class shannons {
    double length=0;
public:
    // Function to sort the symbols based on their probability or frequency
    void sortByProbability(int n, node p[]) {
        //sort the symbols based on their probability in ascending order
        int i, j;
        node temp;
        for (j = 1; j <= n - 1; j++) {
            for (i = 0; i < n - 1; i++) {
                if ((p[i].probability) > (p[i + 1].probability)) {
                    temp.probability = p[i].probability;
                    p[i].probability = p[i + 1].probability;
                    p[i + 1].probability = temp.probability;
                }
            }
        }
    }
    // function to find shannon code
    void shannon(int l, int h, node p[]) {
        float pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0;
        int i, k, j;
        if ((l + 1) == h || l == h || l > h) {
            //checks if length is 1 or 2 and assigns 0 and 1 to the symbols
            if (l == h || l > h){
                p[h].arr[++(p[h].top)] = 0;//assigns 0 to the symbol if length is 1
                cout << p[h].sym << " "<< p[h].arr[p[h].top] << endl;
                return;

            }
            p[h].arr[++(p[h].top)] = 0; //assigns 0 to the symbol if length is 2 to the highest probability symbol
            cout << p[h].sym << " "<< p[h].arr[p[h].top] << endl;

            p[l].arr[++(p[l].top)] = 1; //assigns 1 to the symbol if length is 2 to the lowest probability symbol
            cout << p[l].sym << " "<< p[l].arr[p[l].top] << endl;

            return;
        }
        else {
            for (i = l; i <= h - 1; i++){
                //Sum of all probabilities expect the last one i.e, the highest probability
                pack1 = pack1 + p[i].probability;
            }
            pack2 = pack2 + p[h].probability;//Last Probability
            diff1 = pack1 - pack2; //Difference between the Sum of all probabilities and last probability i.e, Alpha
            if (diff1 < 0){ //If difference is negative
                diff1 = diff1 * -1;
            }
            j = 2;
            while (j != h - l + 1) {
                //Loop to find the number of bits required
                k = h - j;
                pack1 = pack2 = 0;
                for (i = l; i <= k; i++) //Sum of all probabilities
                    pack1 = pack1 + p[i].probability;
                for (i = h; i > k; i--)
                    pack2 = pack2 + p[i].probability;
                diff2 = pack1 - pack2;
                if (diff2 < 0) //If difference is negative
                    diff2 = diff2 * -1; //Make it positive  to compare with the previous difference
                if (diff2 >= diff1) //If difference is greater than previous difference
                    break;
                diff1 = diff2; //Assign the difference to previous difference
                j++; //Increment the number of bits
            }
            k++;
            for (i = l; i <= k; i++){
                p[i].arr[++(p[i].top)] = 1;
                cout << p[i].sym << " "<< p[i].arr[p[i].top] << endl;
            } //Assign 1 to the symbols with the lowest probability
            for (i = k + 1; i <= h; i++){\
                p[i].arr[++(p[i].top)] = 0;
                cout << p[i].sym << " "<< p[i].arr[p[i].top] << endl;
            } //Assign 0 to the symbols with the highest probability
            // Invoke shannon function //
            shannon(l, k, p); //Recursive call to the function to assign the symbols with the lowest probability
            shannon(k + 1, h, p); //Recursive call to the function to assign the symbols with the highest probability
        }
    }
    // Function to calculate the entropy
    double calcEntropy(int n, node p[]) {
        double entropy = 0;
        for (int i = 0; i < n; i++) {
            //Calculate the entropy
            entropy = entropy + (p[i].probability * log(p[i].probability));
        }
        return -entropy;
    }
    double calcEfficiency(int n, node p[]) {
        double entropyVal = calcEntropy(n, p);
        cout << "Entropy = " << entropyVal <<"bits/symbol" << endl;
        double lengthVal = calcLength(n, p);
        cout << "Length = " << lengthVal<<"bits/symbol" << endl;
        double efficiency = entropyVal / lengthVal;
        cout << "Efficiency = " << (efficiency)*100 << endl;
    }

  double calcLength(int n, node p[]) {
        length =1;
      for (int i = 0; i <= n; i++) {
          length += p[i].top * p[i].probability;
      }
      return length;
  }
    // function to display shannon codes
    void display(int n, node p[]) {
        int i, j;
        cout << "\n\tSymbol\tProbability\tCode";
        for (i = n - 1; i >= 0; i--) {
            cout << "\n\t" << p[i].sym << "\t\t" << p[i].probability << "\t"; //print the symbols and their probabilities
            for (j = 0; j <= p[i].top; j++)
                cout << p[i].arr[j]; //print the shannon codes
        }
    }
};



class shannonsForRadix3  {
    void shannon(int l,int x, int h, node p[]) {
        float pack1 = 0, pack2 = 0,pack3=0, diff1 = 0, diff2 = 0,diff3=0;
        int i, k, j;


        if ((l + 1) == x || l == x || l > x) {
            //checks if length is 1 or 2 and assigns 0 and 1 to the symbols
            if (l == h || l > h){
                //p[h].arr[++(p[h].top)] = 0; //assigns 0 to the symbol if length is 1
                return;

            }

            p[0].arr[++(p[h].top)] = 0; //assigns 0 to the symbol if length is 2 to the highest probability symbol
            cout << p[h].arr[(p[h].top)] << endl;
            p[1].arr[++(p[l].top)] = 1; //assigns 1 to the symbol if length is 2 to the lowest probability symbol
            cout << p[l].arr[(p[l].top)] << endl;
            p[2].arr[++(p[1].top)] = 2; //assigns 0 to the symbol if length is 3 to the second highest probability symbol
            return;
        }
        else {
            for (i = l; i <= h - 1; i++){
                //Sum of all probabilities expect the last one i.e, the highest probability
                pack1 = pack1 + p[i].probability;
            }
            pack2 = pack2 + p[h].probability;//Last Probability
            diff1 = pack1 - pack2; //Difference between the Sum of all probabilities and last probability i.e, Alpha
            if (diff1 < 0){ //If difference is negative
                diff1 = diff1 * -1;
            }
            j = x;
            while (j != h - l + 1) {
                //Loop to find the number of bits required
                k = h - j;
                pack1 = pack2 = pack3 = 0;
                for (i = l; i <= k; i++) //Sum of all probabilities
                    pack1 = pack1 + p[i].probability;
                for (i = h; i > k; i--)
                    pack2 = pack2 + p[i].probability;
                diff2 = pack1 - pack2;
                if (diff2 < 0) //If difference is negative
                    diff2 = diff2 * -1; //Make it positive  to compare with the previous difference
                if (diff2 >= diff1) //If difference is greater than previous difference
                    break;
                diff1 = diff2; //Assign the difference to previous difference
                j++; //Increment the number of bits
            }
            k++;
            for (i = l; i <= k; i++) {//Assign 1 to the symbols with the lowest probability
                p[i].arr[++(p[i].top)] = 1;
                cout<<p[i].arr[(p[i].top)]<<endl;
            }
            for (i = k + 1; i <= h; i++) {//Assign 0 to the symbols with the highest probability
                p[i].arr[++(p[i].top)] = 0;
                cout << p[i].arr[++(p[i].top)] << endl;
            }

            // Invoke shannon function //
            shannon(l,x, k, p); //Recursive call to the function to assign the symbols with the lowest probability
            shannon(k + 1,x, h, p); //Recursive call to the function to assign the symbols with the highest probability
        }
    }
};