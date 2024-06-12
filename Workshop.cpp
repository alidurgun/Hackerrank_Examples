#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Workshop
{
    int startTime;
    int duration;
    int endTime;

    bool operator<(Workshop& w)
    {
        return this->endTime < w.endTime;
    }
};

struct Available_Workshops
{
    int size;
    Workshop* arrWorkshop;
    Available_Workshops(int size, Workshop* arrWorkshop)
    {
        this->size = size;
        this->arrWorkshop = arrWorkshop;
    }
    ~Available_Workshops() {
        delete[] arrWorkshop;
    }
};

bool isSuitableWorkshop(Workshop* lastWorkshop, Workshop currentWorkshop)
{
    return ((currentWorkshop.startTime >= lastWorkshop->endTime));
}

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Workshop *workshops = new Workshop[n];
    for (int i = 0; i < n; i++)
    {
        workshops[i].startTime = start_time[i];
        workshops[i].duration = duration[i];
        workshops[i].endTime = start_time[i] + duration[i];
    }
    return new Available_Workshops(n,workshops);
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    std::sort(ptr->arrWorkshop,ptr->arrWorkshop + ptr->size);
    Workshop* lastWorkshop = &ptr->arrWorkshop[0];
    int attendedWorkshops = 1;
    for (int i = 1; i < ptr->size; i++)
    {
        if (isSuitableWorkshop(lastWorkshop,ptr->arrWorkshop[i]))
        {
            attendedWorkshops++;
            lastWorkshop = &ptr->arrWorkshop[i];
        }
    }
    return attendedWorkshops;
}
