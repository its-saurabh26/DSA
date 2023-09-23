string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> mp;
    for(int i= 0;i<n;i++){
        // count of frequency 
        mp[a1[i]]++;
    }
    
    for(int i = 0; i<m; i++){
        
    if(mp[a2[i]] == 0){
        return "No";
    }
    else{
        
        // reducing the count 
        mp[a2[i]]--;
    }
        
    }
    return "Yes";
    
}
