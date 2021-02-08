#include <iostream>

// after first commit
using namespace std;
void hailstone(int n, int limit, int &i)
{
    if (n == 1)
    {
        
        cout << i << "\t \t \t \t" << n << endl;
    }
    else if(i == limit)
    {
        
        cout << i << "\t \t \t \t" << n << endl;
        cout << "Sequence was aborted early." << endl;
    }
    else
    {
        
        if (n % 2 == 0)
        {
            cout << i << "\t \t \t \t" << n << endl;
            i++;
            hailstone(n / 2, limit, i);
            
        }
        else
        {
            cout << i << "\t \t \t \t" << n << endl;
            i++;
            hailstone(3 * n + 1, limit, i);
            
        }
            
    }
    
}

int main()
{
    int i = 1;
    int limit;
    int num;
    cout <<"Number: ";
    cin >> num;
    if(num <= 0)
    {
        cout << "Invalid number, please try again." << endl;
        cout << "Number: ";
        cin >> num;
    }
    cout << "Limit of terms: ";
    cin >> limit;
    if (limit <= 0)
    {
        cout << "Invalid number, please try again." << endl;
        cout << "Limit of terms: ";
        cin >> limit;
    }
    cout <<"Term Number     Value" << endl;
    hailstone(num, limit, i);
    
    return 0;
}

