#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;

long long mypower(long long p,long long y){
    if(y==0){
        return 1;
    }
    long long res=mypower(p,y/2);
    res*=res;
    res%=mod;
    if(y&1==1){
        res=1ll*res*p;
        res%=mod;
    }
    return res;
}

int main(){
    vector<long long>fact(5e5),revfact(5e5);
    fact[0]=1;
    fact[1]=1;
    revfact[0]=revfact[1]=mypower(1,mod-2);
    for(long long i=2;i<=4e5+8;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
        revfact[i]=mypower(fact[i],mod-2);
        revfact[i]%=mod;
    }
    long long n;
    cin>>n;
    n++;
    vector<long long>all(n);
    for(long long i=0;i<n;i++){
        cin>>all[i];
    }
    all.push_back(0);
    long long result=1;
    for(long long i=1;i<=n;i++){
        long long now=0;
        if(all[i]!=0){
            now+=fact[i+all[i]-1]*revfact[i]%mod*revfact[all[i]-1];
        }
        now%=mod;
        for(long long j=all[i];j<all[i-1];j++){
            now+=fact[i-1+j]*revfact[i-1]%mod*revfact[j];
            now%=mod;
        }
        result+=now;
        result%=mod;
    }
    result--;
    cout<<result<<endl;
}
