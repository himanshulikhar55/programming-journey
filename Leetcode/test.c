bool isPossible(int mid , vector<int> & stalls , int n , int k){

    int cowsAllocated = 1;

    int lastCow = stalls[0];

    for(int i = 1 ; i < n ; i++){

        if( stalls[i] - lastCow >= mid){

            lastCow = stalls[i];

            cowsAllocated++;

        }

    }

    if(cowsAllocated >= k) return true;

    else return false;

}

 

int aggressiveCows(vector<int> &stalls, int k)

{

    //    Write your code here.

    int n = stalls.size();

    sort(stalls.begin() , stalls.end());

    int low = 1;

    int ans = -1;

    int high = stalls[n-1] - stalls[0];

    while(low<=high){

        int mid = low + (high-low)/2;

        if(isPossible(mid  ,stalls , n , k)){

            ans = mid;

            low = mid+1;

        } 

        else{

            high = mid-1;

        }

    }

    return ans;

}