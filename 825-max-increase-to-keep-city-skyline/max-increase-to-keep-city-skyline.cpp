class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row(grid.size(),INT_MIN);
        vector<int> column(grid.size(),INT_MIN);
        int result = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
                row[i] = max(row[i],grid[i][j]);
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
                column[i] = max(column[i],grid[j][i]);
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                result += min(row[i],column[j]) - grid[i][j];
            }
        }
        return result;
    }
};