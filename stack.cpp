#include <iostream>

using namespace std;


template <class T>
class Stack {

    T* arr;
    int size;
    int top;
 
public:
 
    Stack() { top = -1; arr=NULL; }
    ~Stack(){ delete[] arr; }

    void push(T x);
    int pop();
    int Top_fun();
    bool isEmpty();
    void Enter_size();
    int Know_size();
    void clear();
    void Display();

};

template <class T> 
void Stack<T>::push(T x)
{
    if ( top == (size - 1) ){
        cout << "Stack is full" << endl;
    }
    else {
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }
}

 
template <class T> 
void Stack<T>::Enter_size()
{
    cout << "\nEnter the size of the array: ";
    int num;
    cin  >> num;
    size = num;
    arr = new T [size];
}

template <class T> 
int Stack<T>::pop()
{
    int x = 0;
    if (top < 0) 
    return -1;
    else
    x = arr[top--];

    return x;

}

template <class T> 
int Stack<T>::Top_fun()
{
    int x = 0;
    if ( isEmpty() )
    return -1;
    else 
    x = arr[top];
    
    return x;
}

template <class T> 
bool Stack<T>::isEmpty()
{
    return (top < 0);
}
 
template <class T> 
int Stack<T>::Know_size()
{
    return (top + 1);
}

template <class T> 
void Stack<T>::clear()
{
    top = -1 ;
}

template <class T>
void Stack<T>::Display()
{
    
}

// Driver program to test above functions
int main()
{
    Stack<int>s;
    s.Enter_size();

    char ch;

    do{

        int choice;                 
        cout << "\n\n\t";
        for ( int i = 0 ; i < 25 ; i++){  
            cout << "- ";
        }
        cout     << "\n\t\t\t\tMenu " << endl;      
        cout << "\t";
        for ( int i = 0 ; i < 25 ; i++){   
            cout << "- ";
        }
        cout     << "\nEnter 1 : Push \n"; 
        cout     << "Enter 2 : Pop \n";
        cout     << "Enter 3 : top element\n";
        cout     << "Enter 4 : Empty \n";
        cout     << "Enter 5 : Size of stack \n";
        cout     << "Enter 6 : clear Array \n";
        
        cout << "\nEnter your Choice:  " ;
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1: {
                char again;
                do{
                    int num;
                    cin >> num;
                    s.push(num); 
                    cout << "Want to push element again (y/n) : ";
                    cin >> again;
                    cout << endl;
                } while ( again == 'Y' || again =='y');
                       
            }  break;

            case 2: {
                    char again;
                    do{  
                        int num = s.pop();            
                        if ( num == -1 ){
                            cout << "Stack UnderFlow\n";
                        }

                        if ( num != -1 ){
                            cout << num << " Pooped From the Stack\n";
                        }

                        cout << "Want to Pop element again (y/n) : ";
                        cin >> again;
                    } while ( again == 'Y' || again =='y');
            }  break;

            case 3: { 
                    if ( s.Top_fun() == -1 ){
                        cout << "Stack is Empty\n";
                    }
                    if ( s.Top_fun() != -1 ){
                        cout << "Top value is : " << s.Top_fun() << "\n";
                    }      
            }  break;

            case 4: { 
                    if ( s.isEmpty() ){
                        cout << "Stack is Empty\n";
                    }
                    if ( !s.isEmpty() ){
                        cout << "Stack is not Empty\n";
                    }
            }  break;
            case 5: { 
                cout << s.Know_size() << " is the size of the stack \n" ;
            }  break;
            case 6: { s.clear();
                cout << "Stack Cleared\n\n";
            }  break;
            default: cout << "\nWrong Input Entered \n";  break;
        }

        cout << "\nDo you want to go to the Main menu (y/n) : ";
        cin  >> ch;
    }while ( ch == 'Y' || ch == 'y');
    cout << "\nProgram ended \n\n\n";
    exit(0); 
    return 0;
}