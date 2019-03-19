//
// Created by marvinle on 2019/3/19 8:26 PM.
//


// class Solution {
// public:
//        邻接矩阵
//     bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
//         int graph[numCourses][numCourses];
//         // 爆栈
//         memset(graph, 0, numCourses * numCourses * sizeof(int));
//         // 前置课程数量
//         int pre[numCourses];
//         memset(pre, 0, sizeof(int) * numCourses);
//         //  扫描一遍建图
//         for(auto it: prerequisites){
//             graph[it.second][it.first] = 1;
//             pre[it.first]++;
//         }
//         // 无前置了的课程
//         queue<int> q;
//         for(int i = 0; i < numCourses; i++){
//             if(pre[i] == 0){
//                 q.push(i);
//             }
//         }
//         int cnt = 0; // 计数
//         while(!q.empty()){
//             int course = q.front();
//             cnt++;
//             q.pop();
//             // 将所有前置课程包含course的减一
//             for(int i = 0; i < numCourses; i++){
//                 if(graph[course][i] == 1){
//                     pre[i]--;
//                     if(pre[i] == 0){
//                         q.push(i);
//                     }
//                 }
//             }
//         }
//         return cnt == numCourses;
//     }
// };

// class Solution {
// // public:
//     // 邻接表
//     bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
//        vector<Node*> graph(numCourses);
//        for(int i = 0; i < numCourses; i++){
//            graph[i] = new Node();
//        }
//         // 初始化
//         for(auto it : prerequisites){
//             graph[it.first]->pre = graph[it.first]->pre+1;
//             graph[it.second]->next.push_back(it.first);
//         }
//         queue<int> q;
//         // 找出没有前置的
//         for(int i =  0;  i < numCourses; i++){
//             if(graph[i]->pre == 0){
//                 q.push(i);
//             }
//         }
//         int cnt = 0; // 计数，当前成功弹出的课程
//         while(!q.empty()){
//             int course = q.front();
//             q.pop();
//             cnt++;
//             // 减少所有前置包含course的课程前置数量
//             int size  = graph[course]->next.size();

//             for(int i = 0; i < size; i++){
//                 int nex = graph[course]->next[i];
//                 graph[nex]->pre  = graph[nex]->pre-1;
//                 if(graph[nex]->pre == 0){
//                     q.push(i);
//                 }
//             }
//         }
//         return cnt == numCourses;
//     }
// private:
//     struct Node {
//         Node() : pre(0){}

//         int pre;   // 前置
//         vector<int> next;  // 被依赖
//     };
// };


// 别人的代码，感觉和我上面第二种几乎一模一样，可就是我那个过不了...
class Solution {
public:
    //拓扑排序，判断有无环,三步走
    bool canFinish(int num, vector<pair<int, int>>& pre) {
        vector<int> indegree(num,0);
        for(int i=0;i<pre.size();i++){
            auto now = pre[i];
            indegree[now.first]++;                 //step1
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0){                       //step2
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cnt++;
            for(int i=0;i<pre.size();i++){
                auto now = pre[i];
                if(now.second==front){
                    indegree[now.first]--;
                    if(indegree[now.first]==0){   //step3
                        q.push(now.first);
                    }
                }
            }
        }
        return cnt==num;
    }
};
