//https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<map>
int maximumFrequency(vector<int> &arr, int n)
{
    int maxAns,maxfreq=0;
    unordered_map<int,int>count;
    for(int i =0; i<arr.size();i++){
        count[arr[i]]++;
        maxfreq= max(maxfreq,count[arr[i]]);
    }
    for(int i =0; i<arr.size();i++){
        if(maxfreq==count[arr[i]]){
            maxAns= arr[i];
            break;
        }
    }
    return maxAns;
}