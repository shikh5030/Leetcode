int lengthOfLongestSubstring(char* s) {
    if(s[0]=='\0')
        return 0;
    int len = strlen(s);
    int visit[256];
    for(int i=0;i<256;i++)
        visit[i] = -1;
    int start = 0, end = 1;
    int ans = 0;
    visit[s[start]] = 0;
    ans++;
    int cur_len = 1;
    while(start<len && end<len)
    {
        int pos = (int)s[end];
        if(visit[pos] == -1 || end-visit[pos]>cur_len)  // if some char is unvisited or not part of the current substring
        {
            cur_len++;
        }
        else 
        {
            start = visit[pos]+1;
            cur_len = end-start+1;
        }
        for(int i=97;i<104;i++)
            printf("%d ",visit[i]);
        printf("\n%d %d %d\n",start,end,cur_len);
        visit[pos] = end;
        if(ans<cur_len)
            ans = cur_len;
        end++;
    }
    return ans;
}