class Solution {
private:
    vector<int> getSubMaxNum(vector<int>& nums, int k)
    {
        int n = nums.size();
        int cnt = n - k;
        vector<int> res;
        for(auto& e : nums)
        {
            while(cnt > 0 && !res.empty() && e > res.back())
            {
                res.pop_back();
                --cnt;
            }
            res.push_back(e);
        }
        while(cnt > 0)
        {
            res.pop_back();
            --cnt;
        }
        return res;
    }

    bool cmp(vector<int>& nums1, int begin1, vector<int>& nums2, int begin2)
    {
        while(begin1 < nums1.size() && begin2 < nums2.size() && nums1[begin1] == nums2[begin2])
        {
            ++begin1;
            ++begin2;
        }
        if(begin1 == nums1.size() && begin2 == nums2.size()) {
            return true;
        } else if (begin1 == nums1.size()) {
            return false;
        } else if (begin2 == nums2.size()) {
            return true;
        }
        if(nums1[begin1] > nums2[begin2]) return true;
        if(nums1[begin1] < nums2[begin2]) return false;
        return true;
    }

    vector<int> Merge(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size() + nums2.size();
        vector<int> res(n, 0);
        int begin1 = 0, begin2 = 0, index = 0;
        while(begin1 < nums1.size() && begin2 < nums2.size())
        {
            if(nums1[begin1] > nums2[begin2]) res[index++] = nums1[begin1++];
            else if(nums1[begin1] < nums2[begin2]) res[index++] = nums2[begin2++];
            else if(nums1[begin1] == nums2[begin2])
            {
                if(cmp(nums1, begin1, nums2, begin2)) res[index++] = nums1[begin1++];
                else res[index++] = nums2[begin2++];
            }
        }
        while(begin1 < nums1.size()) res[index++] = nums1[begin1++];
        while(begin2 < nums2.size()) res[index++] = nums2[begin2++];
        return res;
    }

    vector<int> getMaxAns(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        for(int i = 0; i < n; ++i)
        {
            if(nums1[i] > nums2[i]) return nums1;
            else if(nums1[i] < nums2[i]) return nums2;
        }
        return nums1;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, -1);
        for(int i = 0; i <= k; ++i)
        {
            int j = k - i;
            if(i > nums1.size() || j > nums2.size()) continue;
            vector<int> v1 = getSubMaxNum(nums1, i);
            vector<int> v2 = getSubMaxNum(nums2, j);
            vector<int> tmp = Merge(v1, v2);
            res = getMaxAns(res, tmp);
        }
        return res;
    }
};