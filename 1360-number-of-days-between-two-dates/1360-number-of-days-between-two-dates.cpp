class Solution {
    bool isLeapYear(int year){
        return (year %4  == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    int daysInMonths(int m, int year){
        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
            return 31;
        }
        if(m==2){
            if(isLeapYear(year))
                return 29;
            else
                return 28;
        }
        return 30;
    }
    int solve(string& date){
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        
        int ans = 0;
        for(int i=1900;i<year;i++){
            if(isLeapYear(i))
                ans += 366;
            else
                ans += 365;
        }
        for(int i=1;i<month;i++){
            ans += daysInMonths(i,year);
        }
        ans += day;
        
        return ans;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(solve(date1) - solve(date2));
    }
};