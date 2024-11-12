class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        int mx = 0, mf = 0;
        for(char task : tasks)  {
            mp[task]++;
            if(mx == mp[task])
                mf++;
            else if(mx < mp[task]) {
                mx = mp[task];
                mf = 1;
            }
        }
        int part = mx - 1;
        int emptySlots = part * (n - (mf - 1));
        int availableTasks = tasks.size() - (mx * mf);
        int ideals = max(0, emptySlots - availableTasks);
        return tasks.size() + ideals;
    }
};
