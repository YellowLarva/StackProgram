#include <iostream>
using namespace std;

class Node{

    private:
        int data;
        Node* next;

        Node(){ data = 0; next = NULL; }
        Node(int data, Node* ptr){
           this->data = data;
           this->next = ptr;
        }
        Node(int data){
            this->data = data;
        }
       
    friend class Stack;
        
};


class Stack {

    Node* head;
    int n;
    int size;
 
public:
 
    Stack() { n = 0; size = 0; }
    ~Stack(){  while ( !isEmpty() ){ pop(); } delete head; };

    void push(int x);
    int pop();
    int Top_fun();
    bool isEmpty();
    void Enter_size();
    int Know_size();
    void clear();
    void display();

};

 
void Stack::push(int x)
{
    if ( n == size  ){
        cout << "Stack is full" << endl;
    }
    else {

        Node* temp = new Node();      
        temp->data = x;
        temp->next = head;
        head = temp;
        n++;
    }
}
 
void Stack::Enter_size()
{
    cout << "\nEnter the size of the array: ";
    int num;
    cin  >> num;
    size = num;
}

 
int Stack::pop()
{
    int x = 0;
    if ( isEmpty()) 
    return -1;
    else{
        Node* temp = head;
        x = temp->data;
        head = head->next;
        delete temp;
        n--;
    }

    return x;
}

 
int Stack::Top_fun()
{
    int x = 0;
    if ( isEmpty() )
    return -1;
    else{
        Node* temp = head;
        x = temp->data;
    } 
    return x;
}

 
bool Stack::isEmpty()
{
    return n == 0 ;
}
 
 
int Stack::Know_size()
{
    return n;
}

 
void Stack::clear()
{
    n = 0 ;
    while ( !isEmpty() )
    {
        pop();
    }
    delete head;
    
}

void Stack::display(){

    
    Node* temp2;
    int count = 0;
    cout << "List is : ";
    while ( !isEmpty())
    {
        Node* temp = new Node();
        if ( count == 0 ){
            temp2 = temp;
            count = 1;
        }
        temp->data = pop();
        cout << temp->data << " ";
        temp->next = temp2;
        temp2 = temp;
    }

    cout << "\n\n";

    while ( n < size)
    {
        int x = temp2->data;
        push(x);
        temp2 = temp2->next;
    }

}

int main()
{
    Stack s;
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
        cout     << "Enter 6 : clear Stack \n";
        cout     << "Enter 7 : Display \n";
        
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
                    cout << "Push element again (y/n) : ";
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
            case 7: { 
                s.display();
            }  break;
            default: cout << "\nWrong Input Entered \n";  break;
        }

        cout << "\nGo to the Main menu (y/n) : ";
        cin  >> ch;
    }while ( ch == 'Y' || ch == 'y');
    cout << "\nProgram ended \n\n\n";
    exit(0); 
    return 0;
}