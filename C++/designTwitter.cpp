#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Twitter {
public:   
    struct Tweet
    {
        Tweet(int time, int id)
        {
            tweetTime = time;
            tweetId = id;
        }
        
        int tweetTime;
        int tweetId;

        bool operator<(const Tweet& other)
        {
            return this->tweetTime < other.tweetTime;
        }
    };
    
    std::unordered_map<int, std::unordered_set<int>> followerMap;
    std::unordered_map<int, std::vector<Tweet>> tweets;
    int time = 0;

    Twitter()
    {
        
    }
    
    void postTweet(int userId, int tweetId)
    {
        if (tweets[userId].size() == 10)
        {
            tweets[userId].erase(tweets[userId].begin());
        }
        
        tweets[userId].emplace_back(time++, tweetId);
    }
    
    std::vector<int> getNewsFeed(int userId)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        std::vector<Tweet> tweetList = tweets[userId];

        for (int followee : followerMap[userId])
        {
            tweetList.insert(tweetList.end(), tweets[followee].begin(), tweets[followee].end());
        }

        std::make_heap(tweetList.begin(), tweetList.end());

        std::vector<int> tweetsForFeed;

        while (tweetsForFeed.size() < 10 && !tweetList.empty())
        {
            tweetsForFeed.push_back(tweetList[0].tweetId);
            std::pop_heap(tweetList.begin(), tweetList.end());
            tweetList.pop_back();
        }

        return tweetsForFeed;
    }
    
    void follow(int followerId, int followeeId)
    {
        followerMap[followerId].insert(followeeId);   
    }
    
    void unfollow(int followerId, int followeeId)
    {
        std::unordered_set<int>& followerSet = followerMap[followerId];
        auto it = std::find(followerSet.begin(), followerSet.end(), followeeId);
        if (it == followerSet.end())
        {
            return;
        }
    
        followerSet.erase(it);    
    }
};