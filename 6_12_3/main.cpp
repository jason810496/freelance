#include "Queue.cpp"
#include <iostream>
using namespace std;


int main () {
    Queue Q , Q2 ,Q3;
    // test exception 
    // Q.peek();

    // enqueue 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) {
        Q.enqueue(i);
        cout << "enqueue " << i << endl;
    }

    Q3 = Q;

    Queue Q4(Q3);


    // dequeue 2x elements
    for (int i = 0; i < 2; i++) {
        int y = Q.peek();
        Q.dequeue();
        cout << "peek " << y << endl;
    }


    // enqueue 6, 7, 8, 9, 10
    for (int i = 6; i <= 50; i++) {
        Q.enqueue(i);
        cout << "enqueue " << i << endl;
    }

    Q2 = Q;


    // dequeue all elements
    while (!Q.isEmpty()) {
        int y = Q.peek();
        Q.dequeue();
        cout << "front" << y << endl;
    }
    cout << endl;


    cout<<"Q2:\n";
    while (!Q2.isEmpty()) {
        int y = Q2.peek();
        Q2.dequeue();
        cout << "top " << y << endl;
    }
    cout << endl;

    cout<<"Q3:\n";
    while (!Q3.isEmpty()) {
        int y = Q3.peek();
        Q3.dequeue();
        cout << "top " << y << endl;
    }
    cout << endl;

    cout<<"Q4:\n";
    while (!Q4.isEmpty()) {
        int y = Q4.peek();
        Q4.dequeue();
        cout << "top " << y << endl;
    }
    cout << endl;

    cout<<" check exception \n";
    // test exception 
    Q.peek();
    Q.dequeue();
    Q.dequeue();
    


    return 0;
}