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

#define LIMIT 100100
int numbers[LIMIT];

struct Node
{
    int maxN, minN;
}  tree[LIMIT*4];

void buildTree(int current, int start,int end)
{

    if(start==end)
    {
        tree[current].maxN=numbers[start];
        tree[current].minN=numbers[start];
        return;
    }

    int left = 2*current;
    int right = (2*current)+1;
    int mid=(start+end)/2;

    buildTree(left, start, mid);
    buildTree(right, mid+1, end);

    tree[current].maxN = max(tree[left].maxN, tree[right].maxN);
    tree[current].minN = min(tree[left].minN, tree[right].minN);
}

Node query(int current, int start, int end, int i, int j)
{
    if(j<start || i>end)
    {

        Node node;
        node.minN= INT_MAX;
        node.maxN= INT_MIN;
        return node;
    }

    if(start>=i && end<=j)
    {
        return tree[current];
    }

    int left=2*current;
    int right=(2*current)+1;
    int mid=(start+end)/2;

    Node leftTree = query(left, start, mid, i, j);
    Node rightTree = query(right, mid+1, end, i, j);

    Node node;
    node.maxN = max(leftTree.maxN, rightTree.maxN);
    node.minN = min(leftTree.minN, rightTree.minN);
    return node;
}

int main()
{
    int testCaseCount, testCase;
    int n, d, ans;
    Node node;

    scanf("%d", &testCaseCount);
    for(int testCase=1; testCase<=testCaseCount; testCase++)
    {
        scanf("%d %d", &n, &d);

        for(int i=1;i<=n;i++) {
            scanf("%d", &numbers[i]);
        }

        buildTree(1,1,n);

        ans=0;
        for(int i=1; i+d-1<=n; i++)
        {
           node = query(1,1,n,i,i+d-1);
           ans = max(ans, (node.maxN-node.minN));
        }

        printf("Case %d: %d\n", testCase, ans);
    }
}