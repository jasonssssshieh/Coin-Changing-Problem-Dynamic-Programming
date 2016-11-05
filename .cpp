//
//  main.cpp
//  Coin Changing Problem
//
//  Created by Zijian Xie on 2016/11/5.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//
// You can choose as many coins as you can.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class CoinChanging{
private:
    vector<int> value;
    vector<int> index;
    vector<int> count;
    int target;
public:
    CoinChanging(vector<int>& values, int n){
        value = values;
        target = n;
    }
    
    int minizedCoins(){
        index.resize(target + 1,-1);
        count.resize(target + 1,INT_MAX);
        count[0] = 0;
        
        for(int i = 0; i < (int)value.size(); ++i){
            for(int j = 1; j <= target; ++j){//代表每一个target value，从1 开始到最后
                if(j < value[i]){
                    continue;
                }else{
                    if(count[j-value[i]] != INT_MAX){
                        if(count[j-value[i]] + 1 <= count[j]){
                            count[j] = count[j-value[i]] + 1;
                            index[j] = i;
                        }
                    }
                }
            }
        }
        cout<< "The min number of coins used to construct " << target << " is "<< count[target]<<endl;
        // find the coins that you used;
        int n = target;
        int k = index[n];
        vector<int> usedCoins;
        while(k != -1){
            usedCoins.push_back(value[k]);
            n = n - value[k];
            k = index[n];
        }
        cout<<"Used coins are: "<<endl;
        for(int i = 0; i < (int)usedCoins.size(); ++i){
            cout<< usedCoins[i]<<", ";
        }
        cout<<endl;
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> values = {7,2,3,6};
    int n = 13;
    
    CoinChanging* test = new CoinChanging(values, n);
    test->minizedCoins();
    return 0;
}
