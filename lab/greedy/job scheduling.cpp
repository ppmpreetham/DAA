// NOT FULLY DONE YET
// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Job {int id, dead, profit;};
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    vector<Job> jobs = {{1, 2, 19}, {2, 3, 27}, {3, 4, 25}, {4, 5, 15}};
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), cmp);
    int maxd = 0;

    for (auto job : jobs) maxd = max(maxd, job.dead);
    vector<int> slot(maxd + 1, -1);

    int profit = 0;
    for(auto &j: jobs)
        for(int d = j.dead; d>0; d--){
            if (slot == -1){
                slot[d] = j.id; 
                profit += j.profit; 
                break;
            }
        }
    return 0;
}