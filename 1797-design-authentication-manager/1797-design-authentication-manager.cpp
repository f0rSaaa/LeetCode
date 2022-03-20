class AuthenticationManager {
public:
    
    int ttl;
    unordered_map<string, int>mpp;
    
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mpp[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mpp.find(tokenId) !=mpp.end() && currentTime-mpp[tokenId] < ttl)
            mpp[tokenId] = currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for(auto it:mpp){
            if(currentTime-it.second < ttl)
                res++;
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */