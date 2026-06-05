class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n+1, 1);
        vector<int> parent(n+1);

        for(int i=1;i<n+1;i++)
            parent[i] = i;

        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            // cout << "a: " <<a << " b: " << b << endl;
            // print_(parent, rank);
            // cout << endl<< endl;

            bool u = union_(a, b, rank, parent);
            if(!u){
                return {a, b};
            }
        }
        return {-1, -1};
    }
private:
    int find_(int n, vector<int>& parent){
        int p = parent[n];
        while(p!=parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool union_(int p1, int p2, vector<int>& rank, vector<int>& parent){
        p1 = find_(p1, parent);
        p2 = find_(p2, parent);
        if(p1==p2){
            return false;
        }
        else if(rank[p1]>rank[p2]){
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        else{
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }

    void print_(vector<int> parent, vector<int> rank){
        int n = rank.size() - 1;
        cout << "Parent array " << endl;
        for(int i=1;i<n+1;i++)
            cout << parent[i] << "\t";
        cout << endl;

        cout << "Rank array " << endl;
        for(int i=1;i<n+1;i++)
            cout << rank[i] << "\t";
        cout << endl;
    }

};
