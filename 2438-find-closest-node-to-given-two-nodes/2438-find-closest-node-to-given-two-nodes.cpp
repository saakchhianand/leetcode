class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> dist1(n, -1), dist2(n, -1);
        
        // Traverse from node1
        dfs(edges, node1, dist1);
        // Traverse from node2
        dfs(edges, node2, dist2);

        int minDist = INT_MAX;
        int result = -1;
        
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist || (maxDist == minDist && i < result)) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }
        
        return result;
    }

private:
    void dfs(const vector<int>& edges, int start, vector<int>& dist) {
        int d = 0;
        while (start != -1 && dist[start] == -1) {
            dist[start] = d++;
            start = edges[start];
        }
    }
};
