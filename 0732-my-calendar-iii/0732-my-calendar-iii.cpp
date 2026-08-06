
class MyCalendarThree {
public:
    map<int, int> events; // ordered map stores the elements in ascending order
                          // of their keys
    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        events[startTime] += 1;
        events[endTime] -= 1;
        int k = 0;
        int currBookings = 0;
        for (auto& it : events) {
            currBookings += it.second;
            k = max(k, currBookings);
        }
        return k;
    }
};