class Solution {
public:
    int reverse(int x) 
    {
        int part = 0;
        int newn = 0;
        
        while(x != 0 )
        {
            if (newn > (INT_MAX-1) / 10 || newn < INT_MIN / 10) 
            {
                return 0; 
            }
            newn *= 10;
            part = x % 10;
            newn += part;
            x /= 10;
        }
        
        return newn;
    }
};