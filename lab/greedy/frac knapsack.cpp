// FRACTIONAL KNAPSACK
#include <iostream>
#include <algorithm>
#include <vector>

struct Item{int v, w;};

int main(){
    Item a[]={{60,10},{100,20},{120,30}};
    int n = a.length();
    sort(a, a+n, [](Item &a, Item &b){return (double)a.v/a.w > (double)b.v/b.w;});
    
    double sack = 0;
    int W = 50;
    for(auto &item: a){
        if (item.w < W) {sack += item.v; W -= item.v;}
        else{sack += item.v*(double)W/item.w; break;}
    }
    return 0;
}