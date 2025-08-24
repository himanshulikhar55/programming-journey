#include<bits/stdc++.h>


/*
This gives TLE. Intuition is that we recursively for the first set of ones, calc the area.
The we try to form new ones and find the area. It is a recursive soln.
*/
/*
struct PairHash {
    size_t operator()(const std::pair<int,int>& p) const noexcept {
        // Simple mixing of the two ints into one hash
        return ((size_t)p.first << 32) ^ (size_t)p.second;
    }
};

int calcMinSum(std::unordered_set<std::pair<int, int>, PairHash> ones, int k) {
    if(ones.empty())
        return 0;
    int left=INT_MAX, right=INT_MIN, up=INT_MAX, down=INT_MIN;
    for(std::pair<int,int> p : ones) {
        left = std::min(left, p.second);
        right = std::max(right, p.second);
        up = std::min(up, p.first);
        down = std::max(down, p.first);
    }
    int area = (right-left+1) * (down-up+1);
    if(k == 1)
        return area;
    for(int x=up;x<down;x++) {
        std::unordered_set<std::pair<int, int>, PairHash> newOnes;
        std::unordered_set<std::pair<int, int>, PairHash> remOnes;
        for(std::pair<int, int> p : ones) {
            if(p.first <= x)
                newOnes.insert(p);
            else
                remOnes.insert(p);
        }
        area = std::min(area, std::min(calcMinSum(newOnes, 1) + calcMinSum(remOnes, k-1),
                            calcMinSum(newOnes, k-1) + calcMinSum(remOnes, 1)));
    }
    for(int y=left;y<right;y++) {
        std::unordered_set<std::pair<int, int>, PairHash> newOnes;
        std::unordered_set<std::pair<int, int>, PairHash> remOnes;
        for(std::pair<int, int> p : ones) {
            if(p.second <= y)
                newOnes.insert(p);
            else
                remOnes.insert(p);
        }
        area = std::min(area, std::min(calcMinSum(newOnes, 1) + calcMinSum(remOnes, k-1),
                            calcMinSum(newOnes, k-1) + calcMinSum(remOnes, 1)));
    }
    // cout << area << ' ';
    return area;
}

int minimumSum(std::vector<std::vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    std::unordered_set<std::pair<int, int>, PairHash> ones;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(grid[i][j])
                ones.insert(std::make_pair(i,j));
        }
    }
    return calcMinSum(ones, 3);
}
*/

int findArea(std::vector<std::vector<int>>& grid, int start_i, int end_i, int start_j, int end_j) {
    int start_row=INT_MAX, end_col=INT_MIN, start_col=INT_MAX, end_row=INT_MIN;
    bool found = false;
    for(int i=start_i;i<=end_i;i++) {
        for(int j=start_j;j<=end_j;j++) {
            if(grid[i][j]) {
                start_row = std::min(start_row, i);
                end_col = std::max(end_col, j);
                start_col = std::min(start_col, j);
                end_row = std::max(end_row, i);
                found = true;
            }
        }
    }
    if(found) {
        // std::cout << (end_row-start_row+1) * (end_col-start_col+1) << ' ';
        return (end_row-start_row+1) * (end_col-start_col+1);
    }
    return 0;
}

int minimumSum(std::vector<std::vector<int>>& grid) {
    int m=grid.size(), n = grid[0].size(), ans = INT_MAX, area1, area2, area3;
    /*
        -------------
        |    (1)    |
        |           |
        -------------
        | (2) | (3) |
        |     |     |
        -------------
    */
    for(int i=0;i<m;i++) {
        area1 = findArea(grid, 0, i, 0, n-1);
        for(int j=0;j<n;j++) {
            area2 = findArea(grid, i+1, m-1, 0, j);
            area3 = findArea(grid, i+1, m-1, j+1, n-1);
            ans = std::min(ans, area1+area2+area3);
        }
    }
    /*
        -------------
        | (2) | (3) |
        |     |     |
        -------------
        |    (1)    |
        |           |
        -------------
    */
    for(int i=m-1;i>=0;i--) {
        area1 = findArea(grid, i+1, m-1, 0, n-1);
        for(int j=0;j<n;j++) {
            area2 = findArea(grid, 0, i, 0, j);
            area3 = findArea(grid, 0, i, j+1, n-1);
            ans = std::min(ans, area1+area2+area3);
        }
    }
    /*
        -------------
        |     | (2) |
        |     |     |
          (1) -------
        |     |     |
        |     | (3) |
        -------------
    */
    for(int j=0;j<n;j++) {
       area1 = findArea(grid, 0, m-1, 0, j);
       for(int i=0;i<m;i++) {
            area2 = findArea(grid, 0, i, j+1, n-1);
            area3 = findArea(grid, i+1, m-1, j+1, n-1);
            ans = std::min(ans, area1+area2+area3);
        }
    }
    /*
        -------------
        |     |     |
        | (2) |     |
        ------- (1) |
        |     |     |
        | (3) |     |
        -------------
    */
    for(int j=n-1;j>=0;j--) {
       area1 = findArea(grid, 0, m-1, j+1, n-1);
       for(int i=0;i<m;i++) {
            area2 = findArea(grid, 0, i, 0, j);
            area3 = findArea(grid, i+1, m-1, 0, j);
            ans = std::min(ans, area1+area2+area3);
        }
    }
    /*
        -------------
        |    (1)    |
        -------------
        |    (2)    |
        -------------
        |    (3)    |
        -------------
    */
    for(int i=0;i<m;i++) {
        for(int j=i+1;j<m;j++) {
        area1 = findArea(grid, 0, i, 0, n-1);
            area2 = findArea(grid, i+1, j, 0, n-1);
            area3 = findArea(grid, j+1, m-1, 0, n-1);
            ans = std::min(ans, area1+area2+area3);
        }
    }
    /*
        -------------
        |   |   |   |
        |   |   |   |
        |(1)|(2)|(3)|
        |   |   |   |
        |   |   |   |
        -------------
    */ 
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
        area1 = findArea(grid, 0, m-1, 0, i);
            area2 = findArea(grid, 0, m-1, i+1, j);
            area3 = findArea(grid, 0, m-1, j+1, n-1);
            ans = std::min(ans, area1+area2+area3);
        }
    }
    return ans;
}

int main() {
    int m,n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> arr(m, std::vector<int>(n));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            std::cin >> arr[i][j];
        }
    }
    std::cout << minimumSum(arr) << std::endl;
}