vector<int> findOrder(int n,const vector<vector<int>>& e) {
       vector<int> gr[n];
       vector<int> pre(n, 0);
       for(auto &p:e)
       {
           pre[p[0]]++ ;
           // v is need before u;
           gr[p[1]].emplace_back(p[0]);
       }
       
       // If you need smallest order then used min Heap
       queue<int> q ;
       for(int i = 0 ; i < n ; i++)
       if(pre[i] == 0) q.push(i);

       vector<int> ans ;
       int u ;
       while(q.size())
       {
           u = q.front();
           q.pop();
            for(auto &v : gr[u])
            {
                pre[v]-- ;
                if(pre[v] == 0)
                q.push(v);
            }
            ans.push_back(u);
       }
       
       // If cycle present then
       if(ans.size() < n) return vector<int>(0);

       return ans ;
}