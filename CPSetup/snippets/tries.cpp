struct node {
   node *child[26];
   int prefix;
   int cnt;
   string end;
   node() {
      prefix = 0;
      cnt = 0;
      for (int i = 0; i < 26; i++) {
         child[i] = nullptr;
      }
   }
};

struct tries {
   node *root;
   tries() { root = new node; }
   void insert(string s) {
      node *cur = root;
      const int n = s.size();
      for (int i = 0; i < n; i++) {
         cur->prefix++;
         int x = s[i] - 'a';
         if (cur->child[x] == nullptr) {
            cur->child[x] = new node;
         }
         cur = cur->child[x];
      }
      cur->cnt++;
      cur->end = s;
   }

}