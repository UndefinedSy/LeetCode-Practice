/***********************************************************************
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.

Hind Hint 1:
This problem is equivalent to finding if a cycle exists in a directed graph. 
If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.

Hind Hint 2:
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.

Hind Hint 3:
Topological sort could also be done via BFS.

// If there exists any cycles, return -1
***********************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> genGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        return graph;
    }

    void printVis(int currPos, vector<int>& vis) {
        cout << currPos << ": ";
        for (int i : vis) {
            cout << i << ' ';
        }
        cout << endl;
    }

    bool dfs(int currPos, vector<int>& vis, vector<vector<int>>& graph) {
        //printVis(currPos, vis);
        if (vis[currPos] == 1) { // 1 means in current recursion process occured a cycle.
            return true;
        }
        if (vis[currPos] == 2) { // 2 means current recursion met a node had been searched and no cycle occured.
            return false;
        }
        vis[currPos] = 1;
        for (int i = 0; i < graph[currPos].size(); ++i) {
            if (dfs(graph[currPos][i], vis, graph)) {
                return true;
            }
        }
        vis[currPos] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph = genGraph(numCourses, prerequisites);
        vector<int> vis(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (dfs(i, vis, graph)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int numCourses = 2;
    pair<int, int> p1(1, 0);
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(p1);
    bool res = Solution().canFinish(numCourses, prerequisites);
    cout << (bool)res << endl;
    return 0;
}