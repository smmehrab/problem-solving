#include<bits/stdc++.h>
using namespace std;
 
int main() {
    long long int testCases, n, q, a[100005], k, ans[100005];
    vector<pair<long long int,long long int> > queries;
	
    cin>>testCases;
	while(testCases--) {
		queries.clear();

		cin >> n >> q;
		for(int i=1; i<n+1; i++) cin >> a[i];
		for(int i=0; i<q; i++) cin >> k, queries.push_back({k, i});
		
		sort(a+1, a+1+n);
		sort(queries.begin(), queries.end());
		
        long long int current=0, prev=0, presum=0;
		for(int i=1;;i++) {
			k = queries[current].first;
			while(a[i]<k && i<n+1) {
				presum += (k-a[i]);
				i++;
			}
			
            i--;
			
            while(presum>prev) {
				prev++;
				presum -= (k-a[prev]);
			}

			ans[queries[current].second] = n-prev;
			if(current == q-1) break;
			presum += (i-prev) * (queries[current+1].first-k);
			current++; 
		}

		for(int i=0; i<q; i++) cout << ans[i] << endl;
	}
    return 0;
}