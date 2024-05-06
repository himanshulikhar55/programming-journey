#include<bits/stdc++.h>
using namespace std;
/*
    You are given the schedule of 'N' meetings with their start time 'Start[i]' and end time 'End[i]'.

    You have only 1 meeting room. So, you need to return the maximum number of meetings you can organize.

    Note:
    The start time of one chosen meeting can’t be equal to the end time of the other chosen meeting.

    For example:
    'N' = 3, Start = [1, 3, 6], End = [4, 8, 7].
    You can organize a maximum of 2 meetings. Meeting number 1 from 1 to 4, Meeting number 3 from 6 to 7.

    Constraints:

    1 <= 'N' <= 10^5
    0 <= 'Start[i]' < 'End[i]' <= 10^9
*/
bool sortMeets(pair<int, int> time1, pair<int, int> time2){
    if(time1.second != time2.second)
        return time1.second < time2.second;
    return time1.first < time2.first;
}
int maximumMeetings(vector<int> &start, vector<int> &end) {
    int len = start.size();
    vector<pair<int, int>> timing = vector<pair<int, int>>(len);
    for(int i=0;i<len;i++)
        timing[i] = {start[i], end[i]};
    sort(timing.begin(), timing.end(), sortMeets);
    for(int i=0;i<len;i++){
        cout << timing[i].first << ' ' << timing[i].second << '\n';
    }
    int ans = 1, lastMeetEnd = timing[0].second;
    for(int i=1;i<len;i++){
        if(timing[i].first > lastMeetEnd){
            lastMeetEnd = timing[i].second;
            ans++;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> start = vector<int>(n);
    vector<int> end = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> start[i];
    for(int i=0;i<n;i++)
        cin >> end[i];
    cout << "The max number of meeting that can be held are: " << maximumMeetings(start, end) << '\n';
    return 0;
}