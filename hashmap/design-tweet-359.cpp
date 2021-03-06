#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
//https://leetcode.com/problems/design-twitter/submissions/
using namespace std;

class Twitter {
    unordered_map<int, unordered_set<int>> following;    // follower, followee
    unordered_map<int, map<int, int>> tweets;            // userId, [sn, tweetId]
    long long sn;

public:
/** Initialize your data structure here. */
    Twitter() {
        sn = 0;
    }

/** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].insert(make_pair(sn++, tweetId));
    }

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int, int> top10;
        for (auto iter = following[userId].begin(); iter != following[userId].end(); ++iter) {
            int followee = *iter;
            for (auto iter = tweets[followee].begin(); iter != tweets[followee].end(); ++iter) {

                if (top10.size() > 0 && top10.begin()->first > iter->first && top10.size() > 10)
                    break;
                top10.insert(make_pair(iter->first, iter->second));
                if (top10.size() > 10)
                    top10.erase(top10.begin());
            }
        }

        for (auto iter = top10.rbegin(); iter != top10.rend(); ++iter)
            res.push_back(iter->second);

        return res;
    }

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */