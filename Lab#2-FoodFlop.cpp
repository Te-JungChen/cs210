
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<stack>

using namespace std;

int main()
{
    string str;
    ifstream f("test_stack.txt");
    if (f.fail())
    {
        cout << "Invalid file. " << endl;
        exit(-1);
    }
    while (f >> str)
    {
        //extract the remain space
        string pd;
        getline(f, pd);

        //change the number of the seequence from string to integer
        int size = stoi(str);

        //create the stack with the size
        stack<char> iStack;

        for (int i = 0; i < size; i++)
        {
            getline(f, pd);
            //pickup - labeled with a 1, push into stack 
            if (pd[0] == '1')
            {
                iStack.push(pd[2]);

            }
            // only pop off when the item is on top of the stack equals to the item that need to dropoff
            else if (pd[0] == '2')
            {
                if (iStack.top() == pd[2])
                {
                    iStack.pop();
                }


            }
            //if the series  is valid the stack should be empty when the for loop end
            if (i == size - 1)
            {
                if (iStack.empty())
                {
                    cout << "valid" << endl;
                }
                else
                {
                    cout << "not valid" << endl;
                }
            }
        }
    }
    f.close();


    return 0;
}
