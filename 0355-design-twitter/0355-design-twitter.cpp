class Twitter {
public:

    vector<pair<int,int>> st;
    unordered_map<int,set<int>> mpp;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        st.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> tweet;

        for(int i = st.size()-1; i >= 0 && tweet.size() < 10; i--) {

            int id = st[i].first;
            int tid = st[i].second;

            if(userId == id || mpp[userId].count(id)) {
                tweet.push_back(tid);
            }
        }

        return tweet;
    }
    
    void follow(int followerId, int followeeId) {
        mpp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mpp[followerId].erase(followeeId);
    }
};