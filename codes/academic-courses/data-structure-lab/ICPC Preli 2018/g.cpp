#include <bits/stdc++.h>

using namespace std;
vector<int> intersection(vector<int> &v1, vector<int> &v2)
{

    vector<int> v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

    return v3;
}

int main(){
    int i, n, m, j, x;
    vector<int> divs;
    vector<vector<int> > factors;
    vector<int> d;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        for(j=1; j<=x; j++){
            if(x%j==0)factors[i].push_back(j);
        }
    }
    cin>>m;
    for(i=0; i<m; i++){
        cin>>divs[i];
    }
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            auto v3 = intersection(factors[i], factors[j]);
            auto v = max_element(v3.begin(), v3.end());
            d.push_back(*v);
        }
    }
    for(i=0; i<divs.size(); i++){
        if(binary_search(d.begin(), d.end(), divs[i])){
            cout<<"Y"<<endl;
        }
        else{
            cout<<"N"<<endl;
        }
    }
    return 0;
}
