#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        uint16_t i = {0};
        uint16_t j = {1};

        for (int i = 0; i < nums.size(); i++){
            if (j < nums.size()){
                while (j < nums.size() && nums[i] == nums[j]){
                    j++;
                } 
                nums[i] = nums[j]              
            } else {
                break;
            }
        }

        return i;
    }
};

int main() {
   

    return 0;
}
