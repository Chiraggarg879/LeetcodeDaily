// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/?envType=daily-question&envId=2026-07-09

class DisjointSet{
    public:
    int n;
    vector<int> parent;
    vector<int> sz;
    DisjointSet(int n){
        this->n = n;
        parent.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++) parent[i] = i;


    }

    //findparent
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    //unionbysize
    void unionBySize(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu != pv){
            //connect smaller to larger
            int szv = sz[pv];
            int szu = sz[pu];
            if(szu <= szv){
                sz[pv] = szu + szv;
                sz[pu] = 0;
                parent[pu] = pv;
            }else{
                sz[pu] = szu + szv;
                sz[pv] = 0;
                parent[pv] = pu;
            }


        }
    }
}; 



class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int k = queries.size();
        vector<bool > res(k);
        DisjointSet *ds = new DisjointSet(n);
        for(int i=1;i<n;i++){
            int diff = nums[i] - nums[i-1];
            if(diff <= maxDiff){
                ds->unionBySize(i,i-1);
            }
        }
        for(int i=0;i<k;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            int pu = ds->findParent(u);
            int pv = ds->findParent(v);
            if(pu == pv) res[i] = true;
            else res[i] = false;
        }
        return res;
    }
};