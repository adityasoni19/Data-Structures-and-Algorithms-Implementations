#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

int max(int a,int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

int *add(int A[], int B[], int m, int n)
{
    int size = max(m, n);
    int *sum = (int *)malloc(size*sizeof(int));

    for (int i = 0; i < m; i++)
        sum[i] = A[i];
    for (int i = 0; i < n; i++)
        sum[i] += B[i];

    return sum;
}

int *subtract(int A[], int B[], int m, int n)
{
    int size = max(m, n);
    int *sum = (int *)malloc(size*sizeof(int));

    for (int i = 0; i < m; i++)
        sum[i] = A[i];
    for (int i = 0; i < n; i++)
        sum[i] -= B[i];

    return sum;
}

int *divide_and_conquer(int a[], int b[], int d){
    
    if(d==1){
        int *ret = (int *)malloc(3*sizeof(int));
        ret[0] = a[0]*b[0];
        ret[1] = (a[0]*b[1] + b[0]*a[1]);
        ret[2] = a[1]*b[1];
        return ret;
    }
    if(d==2){
        int *ret = (int *)malloc(5*sizeof(int));
        ret[0] = a[0] * b[0];
        ret[1] = a[0] * b[1] + a[1] * b[0];
        ret[2] = a[0] * b[2] + a[1] * b[1] + a[2] * b[0];
        ret[3] = a[1] * b[2] + a[2] * b[1];
        ret[4] = a[2] * b[2];
        return ret;
    }
    int n= d+1;
    int len1 = n/2, len2 = n - n/2;
    int a0[len1], a1[len2];
    for(int i=0; i<n/2; i++){
        a0[i] = a[i];
    }
    for(int i=n/2; i<n; i++){
        a1[i-len1] = a[i];
    }

    int b0[len1], b1[len2];
    for(int i=0; i<n/2; i++){
        b0[i] = b[i];
    }
    for(int i=n/2; i<n; i++){
        b1[i-len1] = b[i];
    }
    
    int deg1 = len1-1;
    int deg2 = len2-1;

    int *U = divide_and_conquer(a0, b0, deg1);
    int *Z = divide_and_conquer(a1, b1, deg2);
    int *sum_a = add(a0, a1, len1, len2); 
    
    int *sum_b = add(b0, b1, len1, len2);

    int deg3 = max(len1, len2) - 1;
    
    int *Y = divide_and_conquer(sum_a, sum_b, deg3);
    int *yu = subtract(Y, U, (2*deg3)+1, (2*deg1)+1);
    int *Mid = subtract(yu, Z, max((2*deg3)+1, (2*deg1)+1), 2*deg2+1);
    
    int *ans = (int *)malloc((2*n-1)*sizeof(int));
    for(int i=0; i<2*n-1; i++){
        ans[i]=0;
    }

    int t = ceil(n/2);
    for(int i=0; i<(2*deg1)+1; i++){
        ans[i] += U[i];
    }
    for(int i=0; i<max(max((2*deg3)+1, (2*deg1)+1), 2*deg2+1); i++){
        ans[i+t] += Mid[i];
    }
    for(int i=0; i<(2*deg2)+1; i++){
        ans[i+2*t] += Z[i];
    }
    return ans;
}


void solve()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for (int i = 0; i < n+1; i++) {
        scanf("%d",&a[i]);
    }
    int b[n+1];
    for (int i = 0; i < n+1; i++) {
        scanf("%d",&b[i]);
    }
    int *c = divide_and_conquer(a, b, n);
    
    for (int i = 0; i<2*n+1; i++) {
        printf("%d ",c[i]);
    }
}

int main()
{
    solve();
    return 0;
}