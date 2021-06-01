/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        queue<pair<TreeNode*, int>> toExplore;
        int answer = 0;

        toExplore.emplace(root, 1);
        while(!toExplore.empty()){
            if(toExplore.size()==1){
                toExplore.front().second=1;
            } 

            int numberOfNodesInCurrentLevel = toExplore.size(); 
            int minWeight = INT_MAX;
            int maxWeight = 0;

            for(int index = 0; index<numberOfNodesInCurrentLevel; index++){
                TreeNode* currentNode = toExplore.front().first;
                int currentWeight = toExplore.front().second;

                toExplore.pop();

                if(index==0) {
                    minWeight=currentWeight;
                }

                if(index==numberOfNodesInCurrentLevel-1) {
                    maxWeight=currentWeight;
                    answer = max(maxWeight-minWeight+1, answer);
                }

                if(currentNode->left){
                    toExplore.emplace(currentNode->left, (2*currentWeight));
                }

                if(currentNode->right){
                    toExplore.emplace(currentNode->right, (2*currentWeight)+1);
                }
            }
        }
        return answer;
    }
};