#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    if (s.find("AM") != std::string::npos)
    {
        s = s.substr(0, s.length() - 2);
    }
    else {
        s = s.substr(0, s.length() - 2);
        string hour = s.substr(0, 2);
        stringstream ss;
        ss << hour;
        int hourTime;
        ss >> hourTime;
        hourTime = hourTime + 12;
        hour = std::to_string(hourTime);
        s.replace(0, 2, hour);
    }
    return s;
}

int main()
{

    string s = "07:05:45PM";

    string result = timeConversion(s);

    cout << result << "\n";

    return 0;
}
