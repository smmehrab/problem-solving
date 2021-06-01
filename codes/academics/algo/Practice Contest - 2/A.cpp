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

bool isDifferByOneLetter(string& s1, string& s2){
	int difCount = 0;
	int len = s1.length();

	for (int i = 0; i < len; i++){
		if (s1[i]!=s2[i])
            difCount++;
		if (difCount > 1)
            return false;
	}

	return difCount == 1 ? true : false;
}

int transformationCount(string& src, string& dest, set<string> &dictionary){
	queue<pair<string, int> > q;
    map<string,bool> visited;
	map<string,int> transformations;
    set<string>::iterator i;

	if(src == dest)
        return 0;

    for(i=dictionary.begin(); i!=dictionary.end(); i++){
        transformations[*i] = 0;
        visited[*i] = false;
    }

    visited[src]=true;
	q.push(make_pair(src, 0));

	while (!q.empty()){
		pair<string, int> current = q.front();
		q.pop();

		for(i=dictionary.begin(); i!=dictionary.end(); i++){
			string temp = *i;
			if (!visited[temp] && isDifferByOneLetter(current.first, temp)){
				visited[temp]=true;
				if(transformations[temp] < current.second+1){
                    transformations[temp] = current.second+1;
                    q.push(make_pair(temp, current.second+1));
				}
			}
		}
	}

	return transformations[dest];
}

void reset(set<string> &dictionary){
    dictionary.clear();
}

int main(){
    int test;
    string word, query, src, dest;
	set<string> dictionary;

	cin >> test;
	while(test--){
        reset(dictionary);
        while(cin >> word && word!="*"){
            dictionary.insert(word);
        }

        cin.ignore();
        while(getline(cin, query) && query != ""){
            stringstream ss(query);
            ss >> src >> dest;
            cout << src << " " << dest << " " << transformationCount(src, dest, dictionary) << endl;
        }

        if(test) puts("");
	}
	return 0;
}
