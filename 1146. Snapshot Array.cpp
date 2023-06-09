// approach 1 - storing the snapshot array for each snap - MLE

#include <bits/stdc++.h>
using namespace std;



class SnapshotArray {
public:
    int snapId;
    vector<int> arr;
    unordered_map<int,vector<int>> snapOfArr;
    SnapshotArray(int length) {
        this->snapId=0;
        for(int i=0;i<length;i++)
            arr.push_back(0);
    }
    
    void set(int index, int val) {
        this->arr[index]=val;
    }
    
    int snap() {
        snapOfArr[this->snapId]=arr;
        this->snapId++;
        return this->snapId-1;
    }
    
    int get(int index, int snap_id) {
        return snapOfArr[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */



// approach 2 - storing the snapshot array only when modified hence reducing the space - MLE

#include <bits/stdc++.h>
using namespace std;



class SnapshotArray {
public:
    int snapId;
    vector<int> arr;
    vector<int> snapOfArr[50001];
    vector<int> indicesModified;
    SnapshotArray(int length) {
        this->snapId=0;
        for(int i=0;i<length;i++)
            arr.push_back(0);
        indicesModified.push_back(0);
    }
    
    void set(int index, int val) {
        this->arr[index]=val;
        indicesModified.push_back(index);
    }
    
    int snap() {
        if(arr.empty())
            return snapId;

        if(snapId==0)
        {
            snapOfArr[snapId]=arr;
        }
        // {-1,x} -1 indicates that the snapshot arr for the current snap is same as snapshot arr of snap x        
        else if(snapOfArr[snapId-1][0]==-1)
        {
            if(snapOfArr[snapOfArr[snapId-1][1]][indicesModified.back()]==arr[indicesModified.back()])
                snapOfArr[snapId]={-1,snapOfArr[snapId-1][1]};
            else
                snapOfArr[snapId]=arr;
        }
        else
        {
            if(snapOfArr[snapId-1][indicesModified.back()]==arr[indicesModified.back()])
                snapOfArr[snapId]={-1,snapId-1};
            else
                snapOfArr[snapId]=arr;
        }
        snapId++;
        return snapId-1;
    }
    
    int get(int index, int snap_id) {
        if(snapOfArr[snap_id][0]==-1)
            return snapOfArr[snapOfArr[snapId][1]][index];
        return snapOfArr[snap_id][index];
    }
};


// approach 3

#include <bits/stdc++.h>
using namespace std;




class SnapshotArray {
public:
    vector<vector<pair<int,int>>> arr;
    int currSnapId;
    SnapshotArray(int length) {
        arr=vector<vector<pair<int,int>>>(length);
        currSnapId=0;
    }
    
    void set(int index, int val) {
        if(arr[index].empty() or arr[index].back().first!=currSnapId)
            arr[index].push_back(make_pair(currSnapId,val));
        
        arr[index].back().second=val;
    }
    
    int snap() {
        return currSnapId++;;
    }
    // if there is no snapId for this index then return the value of the prev snapId found for that index
    int get(int index, int snap_id) {
        int low=0,high=arr[index].size()-1;
        int res=-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[index][mid].first>snap_id)
                high=mid-1;
            else if(arr[index][mid].first<=snap_id)
            {
                res=arr[index][mid].second;
                low=mid+1;
            }
        }
        return res!=-1?res:0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
