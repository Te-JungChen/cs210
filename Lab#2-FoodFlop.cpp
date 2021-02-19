
#include <iostream>
#include <stack>
#include<cstdlib>
#include <fstream>
using namespace std;

template <class T>
class Stack
{
private:
   T *stackArray;
   int stackSize;
   int top;

public:
   //Constructor
   Stack(int);
   
   // Copy constructor
   Stack(const Stack&);
   
   // Destructor
   ~Stack();
   
   // Stack operations
   void push(T);
   void pop(T &);
   bool isFull();
   bool isEmpty();
};
   
//***************************************************
//  Constructor                                     *
//***************************************************

template <class T>
Stack<T>::Stack(int size)
{
   stackArray = new T[size];
   stackSize = size;
   top = -1;
}

//***************************************************
//  Copy constructor                                *
//***************************************************

template <class T>
Stack<T>::Stack(const Stack &obj)
{
   // Create the stack array.
   if (obj.stackSize > 0)
      stackArray = new T[obj.stackSize];
   else
      stackArray = nullptr;
      
   // Copy the stackSize attribute.
   stackSize = obj.stackSize;
   
   // Copy the stack contents.
   for (int count = 0; count < stackSize; count++)
      stackArray[count] = obj.stackArray[count];
      
   // Set the top of the stack.
   top = obj.top;
}

//***************************************************
//  Destructor                                      *
//***************************************************

template <class T>
Stack<T>::~Stack()
{
   if (stackSize > 0)
      delete [] stackArray;
}

//*************************************************************
// Member function push pushes the argument onto              *
// the stack.                                                 *
//*************************************************************

template <class T>
void Stack<T>::push(T item)
{
   if (isFull())
   {
      cout << "The stack is full.\n";
   }
   else
   {
      top++;
      stackArray[top] = item;
   }
}
 
//*************************************************************
// Member function pop pops the value at the top              *
// of the stack off, and copies it into the variable          *
// passed as an argument.                                     *
//*************************************************************

template <class T>
void Stack<T>::pop(T &item)
{
   if (!isEmpty())
   {
      item = stackArray[top];
      top--;
   }
}

//*************************************************************
// Member function isFull returns true if the stack           *
// is full, or false otherwise.                               *
//*************************************************************

template <class T>
bool Stack<T>::isFull()
{
   bool status;
   
   if (top == stackSize - 1)
      status = true;
   else
      status = false;
   
   return status;
}

//*************************************************************
// Member function isEmpty returns true if the stack          *
// is empty, or false otherwise.                              *
//*************************************************************

template <class T>
bool Stack<T>::isEmpty()
{
   bool status;
   
   if (top == -1)
      status = true;
   else
      status = false;
   
   return status;
}


int main()

{

    string str, ch;

    ifstream inputFile("test_stack.txt");

    if(inputFile.fail())
    {
        cout << "error opening" << endl;
    }
    else
    {
        while(inputFile >> str)
        {
            
            //to extract the remain newline charactor
            string pd;
            getline(inputFile, pd);
            
            int size = stoi(str);
            Stack<char> stackarr(size);
            for(int i = 0; i < size; i++ )
            {
                
                string pd;
                getline(inputFile, pd);
                if( pd[0] == '1')
                {
                    stackarr.push(pd[2]);
                }
                else if( pd[0] == '2')
                {
                    char s;
                    stackarr.pop(s);
                    if(pd[2] != s)
                    {
                        stackarr.push(s);
                    }
                }
                if(i == size - 1)
                {
                    if(stackarr.isEmpty())
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
    }
    inputFile.close();
        return 0;
}
