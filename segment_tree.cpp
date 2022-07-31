class NumArray {
public:
    int n;vector<int>seg;
    int build(int i,int l,int h,vector<int>&a)
    {
        if(l==h)
        {
            seg[i]=a[l];
            return seg[i];
        }
        int m=(l+h)/2;
        seg[i]=build(2*i+1,l,m,a)+build(2*i+2,m+1,h,a);
        return seg[i];
    }
    int sum(int i,int sl,int sr,int l,int r)
    {
        if(l<=sl && r>=sr)
            return seg[i];
        if(sr<l || sl>r)
            return 0;
        int m=(sl+sr)/2;
        return sum(2*i+1,sl,m,l,r)+sum(2*i+2,m+1,sr,l,r);
    }
    NumArray(vector<int>& a) {
        n=a.size();
        if(n==0)
            return;
        seg.resize(4*n);
        build(0,0,n-1,a);
    }
    void update_helper(int i,int l,int h,int pos,int val)
    {
        if(l==h)
        {
            seg[i]=val;
            return;
        }
        int m=(l+h)/2;
        if(pos<=m)
            update_helper(2*i+1,l,m,pos,val);
        else
            update_helper(2*i+2,m+1,h,pos,val);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    void update(int pos, int val) {
        update_helper(0,0,n-1,pos,val);
    }
    
    int sumRange(int left, int right) {
        return sum(0,0,n-1,left,right);
    }
};

// IP: ["NumArray","sumRange","update","sumRange"]
//     [[[1,3,5]],[0,2],[1,2],[0,2]]
// OP: [null,9,null,8]
