const int N = 100010;
long long t[4 * N];

void build(int id, int l, int r, vector<int> &ar) {
   if (l == r) {
      t[id] = ar[l];
      return;
   }

   int mid = l + (r - l) / 2;
   build(2 * id, l, mid, ar);
   build(2 * id + 1, mid + 1, r, ar);
   // merge the two child to parent logic (for sum I add two)
   t[id] = t[2 * id] + t[2 * id + 1];
}

void update(int id, int l, int r, int pos, int val) {
   if (pos < l or pos > r) return;
   if (l == r) {
      t[id] = val;
      return;
   }

   int mid = l + (r - l) / 2;
   update(2 * id, l, mid, pos, val);
   update(2 * id + 1, mid + 1, r, pos, val);
   // merge logic
   t[id] = t[2 * id] + t[2 * id + 1];
}

int query(int id, int l, int r, int lq, int rq) {
   if (lq > r or rq < l) return 0;  // no range value, for sum I take as 0
   if (lq <= l and r <= rq) return t[id];  // whole range into answer;
   int mid = l + (r - l) / 2;
   return query(2 * id, l, mid, lq, rq) + query(2 * id + 1, mid + 1, r, lq, rq);
}