//
// Created by YuXiao on 3/26/16.
//

#ifndef LEECODPROJECT_NINETYSIX_H
#define LEECODPROJECT_NINETYSIX_H
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n==1) {
            return 1;
        }
        if(n==2){
            return 2;
        }

        return count(n);
    }

    int count(int n){
        if (n==0 || n==1) {
            return 1;
        }
        if(n==2){
            return 2;
        }

        if (n%2==0) {
            int sum=0;
            for (int i=0; i<=(n/2-1); i++) {
                sum+=( count(i) * count(n-1-i));
            }
            return sum*2;
        }
        else{
            int sum=0;
            for (int i=0; i<=(n/2-1); i++) {
                sum+=( count(i) * count(n-1-i));
            }
            return sum*2+ count( (n-1)/2 ) * count( (n-1)/2 );
        }
    }
};
#endif //LEECODPROJECT_NINETYSIX_H
