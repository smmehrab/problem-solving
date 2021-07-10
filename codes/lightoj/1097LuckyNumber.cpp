/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;

#define N 100100
int tree[4*N];

void update(int key, int valueToAdd){
    while(key<N) {
        tree[key] += valueToAdd;
        key += key & (-key);
    }
}

int query(int key) {
    int sum=0;
    while(key>0){
        sum += tree[key];
        key -= key & (-key);
    }
    return sum;
}

int kth(int x){
	int lo = 0, hi = N, mid;
	for(; hi - lo > 1 ;){
		mid = (lo + hi) >> 1;
		int k = query(mid);
		(k >= x) ? hi = mid : lo = mid;
	}
	return hi;
}

vector<int> preprocess() {
    vector<int> luckyNumbers;
    luckyNumbers.push_back(1);

    for(int number=1; number<N; number+=2) 
        update(number, 1);

	for(int i=2, num, del, val; i<N; i++){
		num = kth(i);
        luckyNumbers.push_back(num); 
		del = 0;
		for(int j = num; j < N; j += num){
			val = kth(j-del);
			update(val, -1);
			del++;
		}
	}

    return luckyNumbers;
}

int main() {
    int testCaseCount, n;
    vector<int> luckyNumbers = preprocess();
    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {
        cin >> n;
        cout << "Case " << testCase << ": " << luckyNumbers[n-1] << endl;
    }
    return 0;
}



// #include<bits/stdc++.h>

// #define pause           system("pause");
// #define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
// #define mod             1000000007
// #define inf             1<<30
// #define pb              push_back
// #define ppb             pop_back
// #define mp              make_pair
// #define F               first
// #define S               second
// #define sz(x)           ((int)x.size())
// #define sqr(x)          ( (x)* (x) )
// #define eps             1e-9
// #define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
// #define on(x,w)         x|(1<<w)
// #define check(x,w)      (x&(1<<w))
// #define all(x)          (x).begin(),(x).end()
// #define pf              printf
// #define pi              acos(-1.0)
// #define reset(x,v)      memset(x,v,sizeof(x));
// #define AND             &&
// #define OR              ||
// #define what_is(x)      cerr<<#x<<" is "<<x<<"\n";

// typedef long long ll;
// typedef unsigned long long llu;

// using namespace std;


// template<class T>
// inline T mod_v(T num)
// {
//     if(num>=0)
//         return num%mod;
//     else
//         return (num%mod+mod)%mod;
// }
// template<class T>
// inline T gcd(T a,T b)
// {
//     a=abs(a);
//     b=abs(b);

//     while(b)
//     {
//         a=a%b;
//         swap(a,b);
//     }

//     return a;
// }

// template<class T>
// T fast_pow(T n , T p)
// {
//     if(p==0) return 1;
//     if(p%2)
//     {
//         T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
//         return g;
//     }
//     else
//     {
//         T g=fast_pow(n,p/2);
//         g=mod_v( mod_v(g) * mod_v(g) ) ;
//         return g;
//     }
// }

// template<class T>
// inline T modInverse(T n)
// {
//     return fast_pow(n,mod-2);
// }

// template<class T>
// inline void debug(string S1,T S2,string S3)
// {
//     cout<<S1<<S2<<S3;
// }

// bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
// bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
// bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
// bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
// bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
// bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}


// template<class T>
// inline T in()
// {
//     register char c=0;
//     register T num=0;
//     bool n=false;
//     while(c<33)c=getchar();
//     while(c>33){
//         if(c=='-')
//             n=true;
//         else num=num*10+c-'0';
//         c=getchar();
//     }
//     return n?-num:num;
// }

// /******* ! Code start from here ! *******/

// int tree[4*1500000];
// int res[100005];

// void build(int nod,int l,int r)
// {
//     if(l==r)
//     {
//         if((l%2) )
//             tree[nod]=1;
//         else
//             tree[nod]=0;
//         return;
//     }

//     int mid=(l+r)>>1;
//     int left=2*nod;
//     int right=2*nod+1;

//     build(left,l,mid);
//     build(right,mid+1,r);

//     tree[nod]=tree[left]+tree[right];
// }

// int k,x;
// bool ok;

// void qu(int nod,int l,int r)
// {
//   //  printf("%d %d %d %d\n",nod,l,r,k);
//     if(l==r)
//     {
//         if(ok)
//             tree[nod]=0;
//         x=l;
//         return;
//     }

//     int mid=(l+r)>>1;
//     int left=2*nod;
//     int right=2*nod+1;

//     if(tree[left]>=k)
//         qu(left,l,mid);
//     else
//     {
//         k-=tree[left];
//         qu(right,mid+1,r);
//     }

//     tree[nod]=tree[left]+tree[right];
// }



// int main()
// {
//  //    std::ios_base::sync_with_stdio(false);

//     #ifndef ONLINE_JUDGE
//  //       freopen ( "in.txt", "r", stdin );
// //        freopen ( "out.txt", "w", stdout );
//     #endif

//     build(1,1,1500000);

//     res[1]=1;
//     for(int i=2;i<=100000;i++)
//     {
//         ok=false;
//         k=i;
//         qu(1,1,1500000);
//         res[i]=x;
//         int kok=x;
// //        printf("-> %d :",x);
//         for(int j=0;j<=1429431;j+=(kok-1) )
//         {
//             k=kok+j;
//             ok=true;
//             qu(1,1,1500000);//printf(" %d",x);
//         }
//    //     printf("\n");pause;
//     }

//     int t=in<int>(),tcase=1;
//     int n;

//     while(t--)
//     {
//         n=in<int>();

//         printf("Case %d: %d\n",tcase++,res[n] );
//     }


//     return 0;
// }
