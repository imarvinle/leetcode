//
// Created by marvinle on 2018/10/15.
//

#include <map>
#include <vector>
using namespace std;



class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> map1,map2;
        vector<int> ret;
        for(vector<int>::const_iterator iter = nums1.cbegin(); iter != nums1.cend(); iter++){
            if(map1.count(*iter)){
                map1[*iter] = map1[*iter]+1;
            } else {
                map1.insert(pair<int,int>(*iter,1));
            }
        }
        
        for(vector<int>::const_iterator iter = nums2.cbegin(); iter != nums2.cend(); iter++){
            if(map2.count(*iter)){
                map2[*iter] = map2[*iter]+1;
            } else {
                map2.insert(pair<int,int>(*iter,1));
            }
        }

        for(map<int, int>::iterator iter = map1.begin(); iter != map1.end(); iter++){
            if(map2.count(iter->first)){
                int n = min(map2[iter->first],iter->second);
                vector<int> temp(n,iter->first);
                ret.insert(ret.end(),temp.begin(), temp.end());
            }
        }


    }


};