/*
现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，
表示在选修课程 ai 前 必须 先选修 bi 。
例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。
如果不可能完成所有课程，返回 一个空数组 。
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0); 
        for(auto prerequisite:prerequisites){
            int ai = prerequisite[0];
            int bi = prerequisite[1];
            adjList[bi].push_back(ai);
            inDegree[ai]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int course = q.front();
            order.push_back(course);
            q.pop();
            for(auto nextCourse:adjList[course]){
                inDegree[nextCourse]--;
                if(inDegree[nextCourse]==0){
                    q.push(nextCourse);
                }
            }
        }
        if(order.size()!=numCourses) order.clear();
        return order;   
    }
};