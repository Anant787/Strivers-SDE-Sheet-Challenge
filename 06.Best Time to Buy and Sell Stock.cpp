#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int max_profit = 0;
    int min_prices = INT_MAX;

    for(int i=0;i<prices.size();i++)
    {
        min_prices = min(min_prices,prices[i]);
        max_profit = max(max_profit,prices[i] -  min_prices);
    }
    return max_profit;
}
