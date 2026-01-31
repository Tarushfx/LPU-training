#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for (auto temp : v)
    {
        cout << temp << " ";
    }
    cout << endl;
}
void print_set(set<int> s)
{
    for (auto x : s)
        cout << x << " ";
    cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> v = {1, 2, 3, 4};
    cout << "First element: " << *v.begin() << endl;
    auto x = v.end();

    v.push_back(5);
    cout << "After push_back(5): ";
    print(v);

    v.pop_back();
    cout << "After pop_back(): ";
    print(v);
    // O(n)
    v.erase(v.begin() + 1);
    print(v);

    vector<vector<int>> vv(3, vector<int>(5, -1));
    for (vector<int> temp : vv)
        cout << temp.size() << " ";
    cout << endl;

    set<int> s;
    s.insert(5);
    s.insert(4);
    s.insert(-1);
    cout << "Print set\n";
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << " Values less than *itr " << distance(s.begin(), itr) << endl;
    }
    print_set(s);
    set<int, greater<int>> desc;
    desc.insert(1);
    desc.insert(4);
    desc.insert(10);
    desc.insert(6);

    map<int, vector<int>> mp;
    mp[1] = {1, 2, 3, 4};
    mp[2] == vector<int>(); // makes and extra value
    for (auto x : mp)
    {
        cout << "key: " << x.first << " " << "value: ";
        for (auto y : x.second)
            cout << y << " ";
        cout << endl;
    }
    mp[1].pop_back(); // removes 4
    cout << (mp.find(3) != mp.end()) << endl;
    vector<int> arr = {1, 2, 234, 12, 23464, 0, -1};
    sort(arr.begin() + 2, arr.end() - 1);
    print(arr);
    // priority_queue<int, vector<int>, greater<int>> minheap;
}
// https://www.geeksforgeeks.org/problems/vector-insertion/1
vector<int> fillVector(int arr[], int n)
{
    // your code here
    // vector<int> v;
    // for(int i=0;i<n;i++){
    //     v.push_back(arr[i]);
    // }
    // return v;
    return vector<int>(arr, arr + n);
}
// https://www.geeksforgeeks.org/problems/front-to-back/1
// Complete this function. it1 points to vector.begin(), it2 points to vector.end()
void iter(vector<int>::iterator it1, vector<int>::iterator it2)
{
    // Your code here. Use iterator to print all the elements
    for (vector<int>::iterator x = it1; x != it2; x++)
        cout << *x << " ";
    cout << endl;
}
// https://www.geeksforgeeks.org/problems/back-to-front/1
/*Function to print vector in reverse order
 * using iterator
 * it1 : arr.rbegin(), reverse iterator
 * it2 : arr.rend(), reverse iterator
 */
void reverseIterator(vector<int>::reverse_iterator it1,
                     vector<int>::reverse_iterator it2)
{

    // Your code here
    for (vector<int>::reverse_iterator x = it1; x != it2; x++)
        cout << *x << " ";

    cout << endl;
}
// https://www.geeksforgeeks.org/problems/vector-sum/1
int sumMe(vector<int> arr, int n)
{

    // Your code here
    // int sum=0;
    // for(auto x: arr)
    // sum+=x;
    // return sum;
    return std::accumulate(arr.begin(), arr.end(), 0);
    // Use accumulate function
}
// https://www.geeksforgeeks.org/problems/sort-and-reverse-vector/1
vector<int> sortVector(vector<int> v)
{
    // Your code here. Use library function
    sort(v.begin(), v.end());
    return v;
}

vector<int> reverseVector(vector<int> v)
{
    // Your code here. Use library function
    reverse(v.begin(), v.end());
    return v;
}

// https://www.geeksforgeeks.org/problems/vector-erase-and-clear/1
// User function Template for C++

void eraseAt(vector<int> &arr, int pos)
{
    arr.erase(arr.begin() + pos);
}

void eraseInRange(vector<int> &arr, int start, int end)
{
    arr.erase(arr.begin() + start, arr.begin() + end);
}

void clearAll(vector<int> &arr)
{
    arr.clear();
}
// https://www.geeksforgeeks.org/problems/find-the-frequency/1

class Solution
{
public:
    int findFrequency(vector<int> arr, int x)
    {
        // Your code here
        // return  std::count(arr.begin(), arr.end(), x);
        // int f=0;
        // for(auto temp: arr)
        //     if(temp==x) f++;

        // return f;
        // map<int, int> mp;
        // for(auto temp: arr)
        //     mp[temp]++;
        // return mp[x];

        vector<int> v(1e5 + 1, 0);
        for (auto temp : arr)
            v[temp]++;
        return v[x];
    }
};

// https://www.geeksforgeeks.org/problems/sort-vector-of-pairs/1

#define pii pair<int, int>
vector<pii> sortBySecond(vector<pii> v)
{
    // Your code here
    sort(v.begin(), v.end(), [](pii a, pii b)
         {
        if(a.second==b.second)
            return a.first>b.first;
        
        return a.second> b.second; });
    return v;
}

// https://www.geeksforgeeks.org/problems/increasing-roll-and-marks/1

// User function Template for C++
#define pii pair<int, int>
vector<pair<int, pair<int, int>>> increasing_List(vector<pair<int, pair<int, int>>> v)
{
    // Your code here
    sort(v.begin(), v.end(),
         [](pair<int, pii> a, pair<int, pii> b)
         {
             if (a.first == b.first)
             {
                 pii as = a.second;
                 pii bs = b.second;
                 if (as.first == bs.first)
                 {
                     return as.second < bs.second;
                 }
                 return as.first < bs.first;
             }
             return a.first < b.first;
         });
    return v;
}

// https://www.geeksforgeeks.org/problems/unordered-set-find-duplicate/1

vector<int> DuplicateMe(vector<int> &arr)
{
    // using map
    vector<int> ans;
    map<int, int> freq;

    for (auto x : arr)
        freq[x]++;
    for (auto x : arr)
        // if(freq[x]>1 && count(ans.begin(), ans.end(), x)==0)
        //     {
        //         ans.push_back(x);
        //         // freq[x]=0;
        //     }
        if (freq[x] > 1)
        {
            ans.push_back(x);
            // freq[x]=0;
            freq.erase(x);
        }

    return ans;

    // using set
    // set<int> seen, printed;
    // vector<int> ans;
    // for(auto x: arr){
    //     if(seen.find(x)!=seen.end()){
    //         //duplicate
    //         if(printed.find(x)!=printed.end()){
    //             // already printed
    //             continue;
    //         }
    //         // seeing second time , need to print;
    //         ans.push_back(x);
    //         printed.insert(x);
    //     }
    //     else{
    //         // first time seeing
    //         seen.insert(x);
    //     }
    // }
    // return ans;
}
// remove duplicates from sorted array
class Solution
{
public:
    int removeDuplicates(vector<int> &arr)
    {
        int unq = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == 0 || arr[i] != arr[i - 1])
                arr[unq++] = arr[i];
        }
        return unq;
    }
};
// 2sum
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // unordered_map<int, int> mp;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     int rem = target-nums[i];
        //     if(mp.find(rem)!=mp.end()){
        //         return {mp[rem], i};
        //     }
        //     mp[nums[i]]=i;
        // }
        // return {};
        int l = 0;
        int r = nums.size() - 1;
        map<int, int> mp;
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        while (l < r)
        {
            if (v[l].first + v[r].first == target)
            {
                return {v[l].second, v[r].second};
            }
            else if (v[l].first + v[r].first > target)
            {
                r--;
            }
            else
                l++;
        }
        return {};
    }
};
// 3sum
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = n - 1; i >= 2; i--)
        {
            if (i < n - 1 && nums[i] == nums[i + 1])
                continue;
            if (nums[i] < 0)
                continue;
            int l = 0, r = i - 1;
            while (l < r)
            {
                int curr = nums[l] + nums[r];
                if (curr == -nums[i])
                {
                    ans.push_back({nums[l], nums[r], nums[i]});
                    while (l < n - 1 && nums[l + 1] == nums[l])
                        l++;
                    while (r > 0 && nums[r - 1] == nums[r])
                        r--;

                    r--;
                }
                else if (curr > -nums[i])
                {
                    r--;
                }
                else
                    l++;
            }
        }
        return ans;
    }
};

// should not get accepted

class Solution
{
public:
    vector<int> countSmaller(vector<int> &arr)
    {
        vector<int> s;
        vector<int> ans;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
        {
            auto idx = lower_bound(s.begin(), s.end(), arr[i]) - s.begin();
            ans.push_back(idx);
            s.insert(s.begin() + idx, arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
