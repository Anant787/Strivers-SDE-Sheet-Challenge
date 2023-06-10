int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int cnt = 0,ans=0;
    int i=0,j=0;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            cnt++;
            i++;
        }else{
            cnt--;
            j++;
        }
        ans=max(ans,cnt);
    }
    return ans;
}
