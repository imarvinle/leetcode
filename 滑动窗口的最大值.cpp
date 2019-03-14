#include <vector>
#include <list>
using namespace std;

// leetcode.239 hard

class Solution {
public:

    // 关键点我不在滑动窗口list里面存储值，而是存储下标啊
    // 每个下标都会在窗口里去走一圈
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return vector<int>();
        vector<int> result;
        list<int> window;
        int size = nums.size();
        int  cur = 0;

        for(int i = 0; i < k ; i++) {
            while(!window.empty() && nums[i] >= nums[window.back()]){
                window.pop_back();
            }
            window.push_back(i);
        }

        result.push_back(nums[window.front()]);
        for(int i = k; i < size; i++) {

            if(window.size() >= k || window.front() <= (i-k)) {
                window.pop_front();
            }
            // 这里是 window.back，和最后一个比
            while(!window.empty() && nums[i] >= nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
            result.push_back(nums[window.front()]);
        }
        return result;
    }
};

int main () {
    vector<int> a{1,3,1,2,0,5};
    Solution solution;
    vector<int> result =  solution.maxSlidingWindow(a, 3);
}