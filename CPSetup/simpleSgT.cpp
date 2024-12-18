struct sgn
{
   int mn;
   int ct;
   sgn(int mni = 1e9, int cti = 0)
   {
      mn = mni;
      ct = cti;
   }
   void merge(const sgn &l, const sgn &r)
   {
      if (l.mn == r.mn)
      {
         mn = l.mn;
         ct = l.ct + r.ct;
      }
      else
         *this = (l.mn < r.mn ? l : r);
   }
};

sgn t[400400];

void build(int i, int l, int r, const int ar[])
{
   // leave node assign
   if (l == r)
   {
      t[i] = sgn(ar[l], 1);
      return;
   }

   int mid = (l + r) / 2;
   build(2 * i, l, mid, ar);
   build(2 * i + 1, mid + 1, r, ar);
   t[i].merge(t[2 * i], t[2 * i + 1]);
}

void update(int i, int l, int r, int pos, int val)
{
   if (pos < l or pos > r)
      return;
   if (l == r)
   {
      t[i] = sgn(val, 1);
      return;
   }

   int mid = (l + r) / 2;
   update(2 * i, l, mid, pos, val);
   update(2 * i + 1, mid + 1, r, pos, val);
   t[i].merge(t[2 * i], t[2 * i + 1]);
}

sgn query(int i, int l, int r, int lq, int rq)
{
   if (lq > r or rq < l)
      return sgn();
   if (lq <= l and rq >= r)
      return t[i];

   int mid = (l + r) / 2;
   
   // if you did not find out the empty node value
   // if(rq <= mid)
   //    return query(2*i, l, mid, lq,rq);
   // if(lq > mid)
   //    return query(2*i+1, mid+1, r, lq, rq);

   sgn ans;
   ans.merge(query(2 * i, l, mid, lq, rq), query(2 * i + 1, mid + 1, r, lq, rq));
   return ans;
}
