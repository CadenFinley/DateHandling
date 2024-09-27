//
//  date.h
//  DateOverWriteOperands
//
//  Created by Caden Finley on 9/21/23.
//
#include <sstream>
#include <iostream>
using namespace std;
struct Date{
    int year;
    int month;
    int day;
    const int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int nextDay(){
        if(day>=daysInMonth[month]){
            if(!(month == 2 && isLeapYear(year))){
                day = 1;
                month ++;
            }
            else{
                if(!(day>=daysInMonth[month]+1)){
                    day++;
                }
                else{
                    day = 1;
                    month ++;
                }
            }
            if(month > 12){
                day = 1;
                month = 1;
                year ++;
            }
        }
        else{
            day++;
        }
        return day;
    }
    bool isLeapYear(int yearTest) {
        return (yearTest % 4 == 0 && yearTest % 100 != 0) || (yearTest % 400 == 0);
    }
};
istream& operator>>(istream& in, Date &d){
    string input;
    in >> input;
    char spacer;
    istringstream dateStream(input);
    dateStream >> d.month >> spacer >> d.day >> spacer >> d.year;
    return in;
}
ostream& operator<<(ostream& out, Date d){
    out << d.month << "/" << d.day << "/" << d.year;
    return out;
}
Date operator+(Date a, int x){
    Date result;
    result.day= a.day;
    result.month= a.month;
    result.year= a.year;
    while (x > 0) {
        int daysInCurrentMonth = result.daysInMonth[result.month];
        if (result.month == 2 && result.isLeapYear(result.year)){
            daysInCurrentMonth++;
        }
        if (x <= daysInCurrentMonth - result.day){
            result.day += x;
            break;
        }
        else {
            x -= (daysInCurrentMonth - result.day + 1);
            result.day = 1;
            if (result.month == 12) {
                result.month = 1;
                result.year++;
            }
            else {
                result.month++;
            }
        }
    }
    return result;
}
bool operator<(Date a, Date b){
    bool result;
    if(a.year < b.year){
        result =  true;
    }
    else if (a.year > b.year){
        result = false;
    }
    else{
        if(a.month < b.month){
            result = true;
        }
        else if(a.month > b.month){
            result = false;
        }
        else{
            if(a.day < b.day){
                result = true;
            }
            else{
                result = false;
            }
        }
    }
    return result;
}
bool operator>(Date a, Date b){
    bool result;
    if(a.year > b.year){
        result =  true;
    }
    else if (a.year < b.year){
        result = false;
    }
    else{
        if(a.month > b.month){
            result = true;
        }
        else if(a.month < b.month){
            result = false;
        }
        else{
            if(a.day > b.day){
                result = true;
            }
            else{
                result = false;
            }
        }
    }
    return result;
}
bool operator==(Date a, Date b){
    if(a.year == b.year){
        if(a.month == b.month){
            if(a.day == b.day){
                return true;
            }
        }
    }
    return false;
}

