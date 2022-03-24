class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(),people.rend());  //sort in reverse
        int i=0;
        int j=people.size()-1;
        while(i<=j){
            if(people[i]+people[j]<=limit) //sabse patla + sabse mota ek saath jaa sakte hai kya wo check kar rahe hai
                j--;
            ++i;
        }
        return i;
            
    }
};