#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,t,n,size,cs;
    string s;

    cin >> t;

    for (cs = 1;cs <= t; cs++) {
        deque <int> dq;

        cin >> size >> n;
        cout << "Case " << cs << ":" << endl;

        for (i = 0; i < n; i++) {
            cin >> s;

            if(s == "pushLeft" || s == "pushRight") {
                cin >> j;

                if(dq.size() == size)
                    cout << "The queue is full" << endl;

                else if(s == "pushLeft") {
                        cout << "Pushed in left: " << j << endl;
                        dq.push_front(j);
                }

                else if(s == "pushRight") {
                    cout << "Pushed in right: " << j << endl;
                    dq.push_back(j);
                }
            }

            else if(s == "popLeft" || s == "popRight") {
                if(dq.size() == 0)
                    cout << "The queue is empty" << endl;

                else {
                    if(s == "popLeft") {
                        cout << "Popped from left: " << dq.front() << endl;
                        dq.pop_front();
                    }

                    if(s == "popRight") {
                        cout << "Popped from right: " << dq.back() << endl;
                        dq.pop_back();
                    }
                }
            }
        }
    }
}
