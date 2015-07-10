vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int>::iterator a, b, c;
        if(nums.size() < 3) {
            return result;
        }
        for(a  = nums.begin(); a < nums.end() - 2; a++) {
            if(*a > 0) {
                break;
            }
            if(a > nums.begin() && *a == *(a - 1))
                continue;
            for(b = a + 1; b < nums.end() - 1; b++) {
                if(*a + *b > 0) {
                    break;
                }
                if(b > a + 1 && *b == *(b - 1))
                    continue;
                for(c = b + 1; c < nums.end(); c++) {
                    if(*a + *b + *c == 0) {
                        result.push_back({*a, *b, *c});
                        break;
                    }
                }
            }
        }
        return result;
    }
