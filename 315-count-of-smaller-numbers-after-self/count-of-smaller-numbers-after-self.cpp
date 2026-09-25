class Solution {
public:
    vector<int> ans;
    vector<pair<int, int>> a;

    void mergeSort(int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(l, mid);
        mergeSort(mid + 1, r);

        vector<pair<int, int>> temp;

        int i = l;
        int j = mid + 1;
        int smaller = 0;

        while (i <= mid && j <= r) {

            if (a[j].first < a[i].first) {
                temp.push_back(a[j]);
                smaller++;
                j++;
            }
            else {
                ans[a[i].second] += smaller;
                temp.push_back(a[i]);
                i++;
            }
        }

        while (i <= mid) {
            ans[a[i].second] += smaller;
            temp.push_back(a[i]);
            i++;
        }

        while (j <= r) {
            temp.push_back(a[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            a[l + k] = temp[k];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        ans.resize(n, 0);

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        mergeSort(0, n - 1);

        return ans;
    }
};