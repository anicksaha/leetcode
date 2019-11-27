// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        unordered_map<int, vector<pair<int, int>>> ADJ;
        
        for(auto& e:red_edges) {
            ADJ[e[0]].push_back({e[1],0});  
        } 
        
        for(auto& e:blue_edges) {
            ADJ[e[0]].push_back({e[1],1});
        }

        vector<vector<bool>> visited(n,vector(2,false));
        queue<tuple<int,int,int>> Q;
        vector<int> res(n, -1); 

        Q.push({0, -1, 0}); // {node, last_edge_color, dist}
        
        while(!Q.empty()){
            auto curr = Q.front();
            Q.pop();

            if(res[get<0>(curr)] == -1) {
                res[get<0>(curr)] = get<2>(curr);
            } 
            
            for(auto& j : ADJ[get<0>(curr)]) {
                if(j.second != get<1>(curr) && !visited[j.first][j.second]){
                    visited[j.first][j.second] = true;
                    Q.push({j.first, j.second, get<2>(curr) + 1});
                }
            }
        }
        
        return res;
    }
};