// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include "book.h"


#include "simpleLinkedListTemplate.h"
#include "StackAndQueue.h"
#include "Graph.h"

using namespace std;

///////////////////////////////////////////////////////////////////
// Submission Zone: You should submit your code after this line
///////////////////////////////////////////////////////////////////


template <class T>
bool List<T>::exist(T n) {
    // You may leave this function (List<T>::exist(T n)) as it is, it's up to you
    // You *need to submit* this function, but your program should work without modifying it
    // I just put it here just in case that if anyone needs to implement/modify this
    // Meaning, you should be able to get full marks without implementing this function
    return false;
}

template <class T>
void List<T>::removeTail() {
    // You may leave this function (List<T>::removeTail()) as it is, it's up to you
    // You *need to submit* this function, but your program should work without modifying it
    // I just put it here just in case that if anyone needs to implement/modify this
    // Meaning, you should be able to get full marks without implementing this function
 }

// You should modify the following and submit

template <class T>
void List<T>::insertTail(T n)
{
    // Task 1
    insertHead(n); // <<<< which is wrong, erase this and code your own insertTail
    return;
};

template <class T>
void Stack<T>::push(T item) {
    // Task 2
    return;
}

template <class T>
T Stack<T>::pop() {
    // Task 2
    return 0;
}

template <class T>
void Queue<T>::enqueue(T item) {
    // Task 3
    return;
}
template <class T>
T Queue<T>::dequeue() {
    // Task 3
    return 0;
}

int qBalancedBrackets(string exp) {

    // Task 4
    // this part of code is just to show you how to use "string" in C++ as char[];
    // Please delete or comment this for your submission
    /*
    for (unsigned int i = 0; i < expression.length(); i++)
        cout << expression[i];
    cout << endl;
    */

    return 0;
};


void Graph::DFS(int s, List<int>& output, bool resetVisited)
{
    if (resetVisited) {
        _resetVisited();
    }
    output.insertTail(s); //output item
    _setVisited(s); //mark item as visited

    _al[s].start();
    for (int n = 0; n < _al[s].size(); n++) { //for number of items in linked list
        if (!_isVisited(_al[s].current())) { //if head item of s linked list is not visited
            DFS(_al[s].current(), output, false); //dfs down current node
        }
        _al[s].next();  
    }

};

void Graph::BFS(int s, List<int>& output, bool resetVisited)
{
    if (resetVisited) {
        _resetVisited();
    }
    Queue<int> q;  // Assuming Queue::enqueue and Queue::dequeue are implemented correctly
    q.enqueue(s);
    _setVisited(s);

    while (!q.isEmpty()) {
        int v = q.dequeue();
        output.insertTail(v);

        for (_al[v].start(); !_al[v].end(); _al[v].next()) {
            int neighbour = _al[v].current();
            if (!_isVisited(neighbour)) {
                _setVisited(neighbour);
                q.enqueue(neighbour);
            }
        }
    }
};

int Graph::nComponents() {
    int count = 0;
    _resetVisited();
    for (int i = 0; i < _nv; ++i) {
        if (!_isVisited(i)) {  // If node i is not visited, it is a new component
            List<int> component;  // Temp list to use for BFS/DFS
            DFS(i, component, false);  // or BFS(i, component, false);
            count++;
        }
    }
    return count;
};
///////////////////////////////////////////////////////////////////
// Submission Zone Ended: You should submit your code above this line
///////////////////////////////////////////////////////////////////



void insertTailTest();
void stackTest();
void queueTest();
void bookStackTest();
void bookQueueTest();
int BFSTest(string,bool printGraph=true);
int DFSTest(string, bool printGraph = true);
int nComponentTest(string filename, bool printGraph = true);
void balancedBracketsTest(string exp);


int main()
{
    // All test cases
    //Task 1
    insertTailTest();

    // Task 2
    //stackTest();
    //bookStackTest();
    // For the book test, you need to uncomment the function with body below

    // Task 3
    //queueTest();
    //bookQueueTest();
    
    // Task 4
    //balancedBracketsTest("((a+b)+{e-(a-b)})");
    //balancedBracketsTest("(((a+b)+{e-(a-b)})");
    //balancedBracketsTest("(){}(){}(()){{}}");
    //balancedBracketsTest(")(");

    cout << endl;

    // Task 5
    //DFSTest("graphTraveralexample1.txt");
    //DFSTest("graphTraveralexample2.txt");
    //DFSTest("graphTraveralexample3.txt");


    // Task 6
    //BFSTest("graphTraveralexample1.txt");
    //BFSTest("graphTraveralexample2.txt");
    //BFSTest("graphTraveralexample3.txt");


    // Task 7
    //nComponentTest("cexample1.txt");
    //nComponentTest("cexample2.txt");
    //nComponentTest("cexample3.txt");

    return 0;
}

void insertTailTest() {
    cout << "Insert Tail Test:" << endl;
    List<int> li;
    for (int i = 1; i < 5; i++)
    {
        li.insertHead(i);
        li.insertTail(i);
    }
    cout << "List after inserting head and tails" << endl;
    cout << "Your list:" << endl;
    li.print();
    cout << "List after more deletion and insertion" << endl;
    for (int i = 0; i < 8; i++)
    {
        li.removeHead();
    }
    for (int i = 100; i < 104; i++)
    {
        li.insertHead(i);
        li.insertTail(i);
    }
    li.removeHead();
    cout << "Your list:" << endl;
    li.print();
    cout << endl;
}


void stackTest()
{

    Stack<int> si;


    cout << "Stack Test:" << endl;

    for (int i = 0; i < 10; i++)
        si.push(i);
    for (int i = 0; i < 3; i++)
        si.pop();
    for (int i = 90; i < 100; i++)
        si.push(i);
    cout << "Your output" << endl;
    si.print();
    cout << endl;
}

void queueTest() {

    Queue<int> qi;
    cout << "Queue Test:" << endl;
    for (int i = 0; i < 10; i++)
        qi.enqueue(i);
    for (int i = 0; i < 3; i++)
        qi.dequeue();
    for (int i = 90; i < 100; i++)
        qi.enqueue(i);
    cout << "Your output" << endl;
    qi.print();
    cout << endl;

}

/*
void bookStackTest()
{

    Stack<Book> sb;


    cout << "Book Stack Test:" << endl;

    for (int i = 0; i < 5; i++)
    {
        string series("Hairy Border ");
        Book b(series + to_string(i+1),100+i);
        sb.push(b);
    }
    
    for (int i = 0; i < 3; i++)
        sb.pop();
    for (int i = 0; i < 2; i++)
    {
        string series("Bravo Super Hero Comics ");
        Book b(series + to_string(i+1),23+i);
        sb.push(b);
    }

    sb.print(true);
}

void bookQueueTest()
{

    Queue<Book> qb;


    cout << "Book Queue Test:" << endl;

    for (int i = 0; i < 5; i++)
    {
        string series("Hairy Border ");
        Book b(series + to_string(i+1),100+i);
        qb.enqueue(b);
    }
    
    for (int i = 0; i < 3; i++)
        qb.dequeue();
    for (int i = 0; i < 2; i++)
    {
        string series("Bravo Super Hero Comics ");
        Book b(series + to_string(i+1),23+i);
        qb.enqueue(b);
    }

    qb.print(true);
}
*/

void balancedBracketsTest(string exp)
{
    cout << "The expression \"" << exp << "\" is " << (qBalancedBrackets(exp) ? "balanced" : "not balanced" )<< endl;
}

int DFSTest(string filename, bool printGraph) {
    cout << "DFS Test with file: " << filename << endl;
    ifstream myfile(filename);
    int v; // number of vertices
    int e; // number of edges
    int q; // number of queries
    
    if (myfile.fail()){
        cout << "File not found" << endl;
        return -1;
    }
    
    myfile >> v;
    myfile >> e;
    myfile >> q;
    

    Graph G(v); // create a graph with nv nodes
    int s, d;

    // read in all the edges and add into the graph
    for (int i = 0; i < e; i++)
    {
        myfile >> s;
        myfile >> d;
        G.addEdge(s, d);
        G.addEdge(d, s);
    }
    
    if (printGraph)
        G.printGraph(); 

    for (int i = 0; i < q; i++)
    {
        myfile >> s;
        cout << "Starting from Node " << s << ":" << endl;
        List<int> li;
        G.DFS(s, li);
        li.print();

    }
    myfile.close();
    cout << endl;
    return 0;
}

int BFSTest(string filename, bool printGraph) {
    cout << "BFS Test with file: " << filename << endl;
    ifstream myfile(filename);
    int v; // number of vertices
    int e; // number of edges
    int q; // number of queries

    if (myfile.fail()) {
        cout << "File not found" << endl;
        return -1;
    }

    myfile >> v;
    myfile >> e;
    myfile >> q;


    Graph G(v); // create a graph with nv nodes
    int s, d;

    // read in all the edges and add into the graph
    for (int i = 0; i < e; i++)
    {
        myfile >> s;
        myfile >> d;
        G.addEdge(s, d);
        G.addEdge(d, s);
    }

    if (printGraph)
        G.printGraph();


    for (int i = 0; i < q; i++)
    {
        
        myfile >> s;
        cout << "Starting from Node " << s << ":" << endl;
        List<int> li;
        G.BFS(s, li);
        li.print();
    }
    myfile.close();
    cout << endl;
    return 0;
}

int nComponentTest(string filename,bool printGraph) {
    cout << "Number of Component Test with file: " << filename << endl;
    ifstream myfile(filename);
    int v; // number of vertices
    int e; // number of edges
    int q; // number of queries

    if (myfile.fail()) {
        cout << "File not found" << endl;
        return -1;
    }



    myfile >> v;
    myfile >> e;
    myfile >> q;


    Graph G(v); // create a graph with nv nodes
    int s, d;

    // read in all the edges and add into the graph
    for (int i = 0; i < e; i++)
    {
        myfile >> s;
        myfile >> d;
        G.addEdge(s, d);
        G.addEdge(d, s);
    }

    if (printGraph)
        G.printGraph();


    cout << "No. of components = " << G.nComponents() << endl;

    myfile.close();
    cout << endl;
    return 0;
}
