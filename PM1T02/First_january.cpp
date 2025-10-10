#include <iostream>


using namespace std;

int main(){
    int k, num;
    string start;
    num = 0;
    
    cout << "Please enter what day of the week January 1st is: ";
    cin >> start;
    cout << "Enter the day for which you want to find out the day of the week:";
    cin >> k;
    string days[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

    if (k > 365 || k < 1) {
        cout << "The entered data is incorrect, please enter it again:";
        cin >> k;

    }

    for (int i = 0; i < 7; i++) {
        if (start == days[i]) {
            num = i;
        }
    }
    k = k % 365;
    k = k % 7 + num;
    cout << days[k];

    return 0;
}