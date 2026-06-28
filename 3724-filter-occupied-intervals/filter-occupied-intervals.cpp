class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> ans;
        sort(occupiedIntervals.begin(),occupiedIntervals.end()); 

        for(auto it: occupiedIntervals){
            if(ans.empty() || ans.back()[1]+1<it[0]){
                ans.push_back(it);
            }
            else{
                ans.back()[1] = max(ans.back()[1],it[1]);
            }
        }
        vector<vector<int>> res;

        for (auto &it : ans) {
            if (it[1] < freeStart || it[0] > freeEnd) {
                res.push_back({it[0], it[1]});
            } else {
                if (it[0] < freeStart)
                    res.push_back({it[0], freeStart - 1});

                if (it[1] > freeEnd)
                    res.push_back({freeEnd + 1, it[1]});
            }
        }

        return res;
    }
};
