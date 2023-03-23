using namespace std;

int reverse(int x) {
        if(x == INT_MIN || x == INT_MAX || x < INT_MIN || x > INT_MAX){
            return 0;
        }
        bool is_neg = false;
        if(x < 0){
            x *= -1;
            is_neg = true;
        }
        int reverse = 0;
        while(x != 0){
            if(reverse > INT_MAX/10 || reverse < INT_MIN/10){
                return 0;
            }
            reverse = reverse * 10 + x %10;
            x/=10;
        }
        
        if(is_neg){
            return reverse * -1;
        }
        return reverse;
        
    }