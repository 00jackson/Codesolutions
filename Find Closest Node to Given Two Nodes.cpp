// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

// You are also given two integers node1 and node2.

// Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

// Note that edges may contain cycles.


// solution:

 class Solution {
    public:
    void dfs(int i, int dist, vector<int>& e, vector<int>& memo) {
    while (i != -1 && memo[i] == -1) {
        memo[i] = dist++;
        i = e[i];
    }
}
int closestMeetingNode(vector<int>& e, int node1, int node2) {
    int res = -1, min_dist = INT_MAX;
    vector<int> m1(e.size(), -1), m2(e.size(), -1);
    dfs(node1, 0, e, m1);
    dfs(node2, 0, e, m2);
    for (int i = 0; i < e.size(); ++i)
        if (min(m1[i], m2[i]) >= 0 && max(m1[i], m2[i]) < min_dist) {
            min_dist = max(m1[i], m2[i]);
            res = i;
        }
    return res;
}
};
