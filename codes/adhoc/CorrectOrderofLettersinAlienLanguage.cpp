#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
	int numberOfNodes;
	list<int> *edges;

	void helper(int node, vector<bool>& visited, stack<int> &st) {
        visited[node] = true;
        for (auto adjacent = edges[node].begin(); adjacent != edges[node].end(); ++adjacent) {
            if (!visited[*adjacent])
                helper(*adjacent, visited, st);
        }
        st.push(node);
    }

public:
	Graph(int numberOfNodes) {
        this->numberOfNodes = numberOfNodes;
        edges = new list<int>[numberOfNodes];
    }

	void addEdge(int source, int destination) {
        edges[source].push_back(destination);
    }

	vector<char> topologicalSort() {
        stack<int> st;
        vector<bool> visited(numberOfNodes, false);

        for (int node=0; node<numberOfNodes; node++) {
            if (!visited[node])
                helper(node, visited, st);
        }

        vector<char> order;
        while (st.empty() == false) {
            order.push_back((char) ('a' + st.top()));
            st.pop();
        }
        return order;
    }
};

vector<char> findOrder(vector<string>& words, int numberOfWords, int numberOfLetters) {
	Graph graph(numberOfLetters);
	for (int i=0; i<numberOfWords-1; i++) {
		string word1 = words[i];
        string word2 = words[i+1];
        int limit = min(word1.length(), word2.length());
		for (int j=0; j<limit; j++) {
			if (word1[j] != word2[j]) {
				graph.addEdge(word1[j]-'a', word2[j]-'a');
				break;
			}
		}
	}
	return graph.topologicalSort();
}

int main() {
    int numberOfLetters;
    cout << "Enter Number of Letters in the Language:" << endl;
    cin >> numberOfLetters;

    int numberOfWords;
    cout << "Enter Number of Words:" << endl;
    cin >> numberOfWords;

    vector<string> words(numberOfWords);
    cout << "Enter " << numberOfWords << " Words: (In separate lines)";
    for(string &word : words) 
        cin >> word;

    vector<char> order;
    order = findOrder(words, numberOfWords, numberOfLetters);
    cout << "Correct Order" << endl;
    for(char c : order) 
        cout << c << " ";
    cout << endl;

	return 0;
}