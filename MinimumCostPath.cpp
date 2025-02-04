//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        
        int n = grid.size();
        
        // Min-heap to store {cost, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Distance matrix initialized with large value (INF)
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Directions for moving in 4 directions (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Start from top-left corner
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int currCost = top[0];
            int r = top[1];
            int c = top[2];
            
            // If we reached bottom-right, return cost
            if (r == n - 1 && c == n - 1) {
                return currCost;
            }

            // Explore all 4 directions
            for (auto dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // Check valid move
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newCost = currCost + grid[nr][nc];

                    // If a cheaper path is found, update and push to heap
                    if (newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, nr, nc});
                    }
                }
            }
        }

        return -1; // Should never reach here
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
