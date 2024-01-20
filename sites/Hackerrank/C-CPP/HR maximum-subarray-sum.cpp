#include<iostream>
using namespace std;

#define SIZE 1000000

struct data{
    long long lsum, msum, rsum, fsum;

    data(){
        lsum=0, msum=0, rsum=0, fsum=0;
    }
};

long long A[SIZE];
data tree[SIZE+SIZE+SIZE+SIZE];

void build(int node, int l, int r, int m){
    if (l == r){
        tree[node].lsum = A[l] % m;
        tree[node].msum = A[l] % m;
        tree[node].rsum = A[l] % m;
        tree[node].fsum = A[l] % m;
        return;
    }

    int mid = (l+r)/2, child1=node+node, child2=node+node+1;
    build(child1, l, mid, m); build(child2, mid+1, r, m);
    tree[node].lsum = max(tree[child1].lsum, (tree[child1].fsum + tree[child2].lsum) % m);
    tree[node].rsum = max(tree[child2].rsum, (tree[child1].rsum + tree[child2].fsum) % m);
    tree[node].msum = max(max(tree[child1].msum, tree[child2].msum),
                             (tree[child1].rsum + tree[child2].lsum) % m);
    tree[node].fsum = (tree[child1].fsum + tree[child2].fsum) % m;
}

data query(int node, int s, int e, int l, int r, int m){
    if (l <= s && r >= e) return tree[node];
    int mid = (s+e)/2, child1=node+node, child2=node+node+1;

    if (r <= mid) return query(child1, s, mid, l, r, m);
    if (l > mid) return query(child2, mid+1, e, l, r, m);

    data Left, Right, Merge;
    Left = query(child1, s, mid, l, r, m),
    Right = query(child2, mid+1, e, l, r, m);

    Merge.lsum = max(Left.lsum, (Left.fsum + Right.lsum) % m);
    Merge.rsum = max(Right.rsum, (Left.rsum + Right.fsum) % m);
    Merge.msum = max(max(Left.msum, Right.msum), (Left.rsum + Right.lsum) % m);
    Merge.fsum = (Left.fsum + Right.fsum) % m;
    return Merge;
}

int main(){
    int q; scanf("%d", &q);

    while (q--){
        int n; long long m; scanf("%d %lld", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
        build(1, 1, n, m);
        printf("%lld\n", query(1, 1, n, 1, n, m).msum);
    }

    return 0;
}
