class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        //approach : each row should have n-i-1 trailing zeroes and count the zeroes of each row and store it and for every row adjust it as first row have max trailing zero then another then another 

        int n = grid.size();
        int swaps=0;
        vector<int>trailingzero(n);
        // count no of trailing zero
        for(int i=0;i<n;i++)
        {
            int count =0;
            for(int j=n-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                    count++;
                
                else 
                    break;
            }
            trailingzero[i]=count;
        }

        //place rows at correct position
        for(int i=0;i<n;i++)
        {
            int req = n-i-1;
            int j=i;

            //find a row with enough trailing zeroes
            while(j<n && trailingzero[j]<req)
                j++;

            if(j==n)
                return -1;
            
            //bring row j to pos i by adjacent swapping
            while(j>i)
            {
                swap(trailingzero[j],trailingzero[j-1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};