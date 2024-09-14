#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> frequency(candyType.begin(), candyType.end());
        return min(frequency.size(), candyType.size() / 2);
    }
};