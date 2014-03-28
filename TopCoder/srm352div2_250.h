#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <ctype.h>
#include <math.h>

using namespace std;

class AttendanceShort
{
public:
    vector <string> shortList(vector <string> names, vector <string> attendance)
    {
    	vector<string> absenteeList;
    	vector<string>::iterator it1, it2;

        for (it1 = names.begin(), it2 = attendance.begin(); it1 != names.end(); it1++, it2++)
        {
        	string studentName = *it1;
        	string studentAttendance = *it2;
        	int totalWorkingDays = studentAttendance.size();
        	int totalPresence = 0;
        	for(int j =0; j < studentAttendance.size(); j++)
        	{
        		if(studentAttendance[j] == 'P')
        			totalPresence = totalPresence + 1;
        		if(studentAttendance[j] == 'M')
        			totalWorkingDays = totalWorkingDays - 1;
        	}
        	int percentage = (totalPresence*100)/totalWorkingDays;
        	if(percentage < 75)
        		absenteeList.push_back(studentName);
        }
        return absenteeList;
    }
};
