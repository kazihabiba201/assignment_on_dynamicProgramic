#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// To calculate maximum profit
int maxProfit(const vector<int>& prices) {
    int maxProfit = 0; 

    for (size_t i = 1; i < prices.size(); ++i) {
        // If the price on day i is higher than the price on day i-1
        if (prices[i] > prices[i - 1]) {
            // Buy on day i-1 and sell on day i
            maxProfit += prices[i] - prices[i - 1];
        }
    }

    return maxProfit; 
}

int main() {
    string input;
    cout << "Input: prices = ";
    getline(cin, input); 

    // Remove the brackets
    input.erase(remove(input.begin(), input.end(), '['), input.end());
    input.erase(remove(input.begin(), input.end(), ']'), input.end());

    // Convert the input string to a vector of integers
    vector<int> prices;
    stringstream ss(input);
    string price;

    // Read each price and convert to integer
    while (getline(ss, price, ',')) {
  
        price.erase(remove(price.begin(), price.end(), ' '), price.end());
        if (!price.empty()) { 
            try {
                prices.push_back(stoi(price)); // Convert string to integer and add to the vector
            } catch (const invalid_argument&) {
                cerr << "Invalid price encountered: " << price << endl;
                return 1; // Exit if there's an invalid price
            }
        }
    }

    // maximum profit
    int profit = maxProfit(prices);
    
    cout << "Output: " << profit << endl;
    
    return 0;
}
//Time Complexity:O(n)
// Space Complexity: O(n)
