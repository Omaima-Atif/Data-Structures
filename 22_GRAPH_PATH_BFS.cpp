#include <iostream>
#include <cstdlib>
using namespace std;

struct Edge;

struct Vertex{
    char vertexname;
    Vertex *nextVertex;
    Edge *edgestart;
    bool visited;
};

struct Edge{
    Vertex *tovertex;
    Edge *nextedge;
    
};

Vertex *vertexstart=NULL;

void insertvertex(char vertexname ){
    
    //------------------IF VERTEX ALREADY EXISTS---------------------------
    if(vertexstart!=NULL){
        Vertex *temp=vertexstart;
        while(temp!=NULL){
            if(temp->vertexname==vertexname){
                cout<<"Vertex already exist"<<endl;
                return;
            }
            temp=temp->nextVertex;
        }
    }
    
    //-----------------CREATING VERTEX-------------------------
    Vertex *newvertex=(Vertex*)malloc(sizeof(Vertex));
    newvertex->vertexname=vertexname;
    newvertex->nextVertex=NULL;
    newvertex->edgestart=NULL;
    
    //------------------IF NO VERTEX ADDEd--------------------
    if(vertexstart==NULL){
        vertexstart=newvertex;
        return;
    }
    
    //----------------ENDING VERTEX AT THE END OF VERTEX LIST-------------------
    else{
        Vertex *temp=vertexstart;
        while(temp->nextVertex!=NULL){
            temp=temp->nextVertex;
          
        }
        temp->nextVertex=newvertex;
        return;
        
    }
}
void insertEdge(char vertex, char edge) {
    // Check if no vertices added
    if (vertexstart == NULL) {
        cout << "NO VERTICES ADDED" << endl;
        return;
    }

    // Find the vertex to add the edge to
    Vertex *findvertex = vertexstart;
    while (findvertex != NULL) {
        if (findvertex->vertexname == vertex) {
            cout << "VERTEX FOUND AND EDGE ADDED" << endl;

            // Find the vertex where the edge points to
            Vertex *toVertex = vertexstart;
            while (toVertex != NULL) {
                if (toVertex->vertexname == edge) {
                    
                    // Create a new edge
                    Edge *newEdge = new Edge;
                    newEdge->nextedge = NULL;
                    newEdge->tovertex = toVertex; // Assign the correct vertex the edge points to

                    // If no edges exist, make this the first edge
                    if (findvertex->edgestart == NULL) {
                        findvertex->edgestart = newEdge;
                    } else {
                        
                        // Find the last edge and append the new edge
                        Edge *temp = findvertex->edgestart;
                        while (temp->nextedge != NULL) {
                            temp = temp->nextedge;
                        }
                        temp->nextedge = newEdge;
                    }

                    return;
                }
                toVertex = toVertex->nextVertex;
            }

            // If the edge's destination vertex is not found
            cout << "Destination vertex not found" << endl;
            return;
        }
        findvertex = findvertex->nextVertex;
    }

    cout << "Vertex not found" << endl;
}

void printVertices() {
    cout << "Vertices:" << endl;
    Vertex* current = vertexstart;
    while (current != nullptr) {
        cout << current->vertexname << " ";
        current = current->nextVertex;
    }
    cout << endl;
}

void printEdges() {
    cout << "Edges:" << endl;
    Vertex* current = vertexstart;
    while (current != nullptr) {
        cout << "Edges from vertex " << current->vertexname << ": ";
        Edge* edge = current->edgestart;
        while (edge != nullptr) {
            cout << "(" << current->vertexname << " -> " << edge->tovertex->vertexname << ") ";
            edge = edge->nextedge;
        }
        cout << endl;
        current = current->nextVertex;
    }
}

//------------------------------BREADTH FIRST SEARCH--------------------

struct Stack{
    Vertex *vertex;
    Stack *next;
};
Stack *top=NULL;

void push(Vertex *vertex){
    Stack *temp = new Stack;
    temp->vertex = vertex;
    temp->next = top;
    top = temp;
}

void pop(){
    if(top == NULL){
        return;
    }
    Stack *temp = top;
    top = top->next;
    delete temp;
}

void DFS(char startvertex, char endvertex) {
    // Check if no vertices exist in the graph
    if (vertexstart == NULL) {
        cout << "NO VERTICES ADDED" << endl;
        return;
    }

    // Find the starting vertex
    Vertex* start = vertexstart;
    while (start != NULL) {
        if (start->vertexname == startvertex) {
            break;
        }
        start = start->nextVertex;
    }

    // If the starting vertex is not found, exit
    if (start == NULL) {
        cout << "STARTING VERTEX NOT FOUND" << endl;
        return;
    }

    // Initialize stack and push the starting vertex
    push(start);

    // Perform DFS traversal
    while (top != NULL) {
        // Pop a vertex from the stack
        Vertex *current = top->vertex;
        pop();

        // If the current vertex has not been visited
        if (current->visited != true) {
            // Mark the current vertex as visited and print its name
            current->visited = true;
            cout << current->vertexname << " ";

            // If the destination vertex is found, print it and return
            if (current->vertexname == endvertex) {
                cout << endvertex << " ";
                break;
            }

            // Explore all adjacent vertices
            Edge *edge = current->edgestart;
            while (edge != NULL) {
                if (edge->tovertex->visited != true) {
                    push(edge->tovertex);
                }
                edge = edge->nextedge;
            }
        }
    }

    // Reset visited flags for future traversals
    Vertex* reset = vertexstart;
    while (reset != NULL) {
        reset->visited = false;
        reset = reset->nextVertex;
    }
}

int main() {
    int graphtype;
    char vertex;
    char edgeto;
    char edgefrom;
    char startvertex;
    char endvertex;
    cout << "ENTER 1 for DIRECTED GRAPH AND @ FOR UNDIRECTED GRAPH" << endl;
    cin >> graphtype;

    switch(graphtype) {
        case 1: {
            int score = -1;
            while(score != 0) {
                cout << "Enter 1 to insert a vertex, 2 to insert an edge, 3 to print vertices and edges,and 4 to DFS or 0 to exit" << endl;
                cin >> score;
                switch(score) {
                    case 1:
                        cout << "ENTER VERTEX CHARACTER TO BE INSERTED: ";
                        cin >> vertex;
                        insertvertex(vertex);
                        break;
                    case 2:
                         cout << "ADD VERTEX TO ADD EDGE TO: ";
                        cin >> edgeto;
                        cout << "ADD VERTEX TO ADD EDGE FROM: ";
                        cin >> edgefrom;
                        insertEdge(edgeto, edgefrom);
                        break;
                    case 3:
                        cout << "Printing vertices:" << endl;
                        printVertices();
                        cout << endl;

                        cout << "Printing edges:" << endl;
                        printEdges();
                        cout << endl;
                        break;
                    case 4:
                        cout<<"ENTER VERTEX TO START FROM TO DFS"<<endl;
                        cin>>startvertex;
                        cout<<"ENTER DESTINATION"<<endl;
                        cin>>endvertex;
                        DFS(startvertex,endvertex);
                        break;
                }
            }
            break;
        }
        case 0: {
            int score = -1;
            while(score != 0) {
                cout << "Enter 1 to insert a vertex, 2 to insert an edge, 3 to print vertices and edges, 4 to DEPTH FIRST SEARCH or 0 to exit" << endl;
                cin >> score;
                switch(score) {
                    case 1:
                        cout << "ENTER VERTEX CHARACTER TO BE INSERTED: ";
                        cin >> vertex;
                        insertvertex(vertex);
                        break;
                    case 2:
                        cout << "ADD VERTEX TO ADD EDGE TO: ";
                        cin >> edgeto;
                        cout << "ADD VERTEX TO ADD EDGE FROM: ";
                        cin >> edgefrom;
                        insertEdge(edgeto, edgefrom);
                        insertEdge(edgefrom, edgeto);
                        break;
                    case 3:
                        cout << "Printing vertices:" << endl;
                        printVertices();
                        cout << endl;

                        cout << "Printing edges:" << endl;
                        printEdges();
                        cout << endl;
                        break;
                    case 4:
                        cout<<"ENTER VERTEX TO START FROM TO DFS"<<endl;
                        cin>>startvertex;
                        cout<<"ENTER DESTINATION"<<endl;
                        cin>>endvertex;
                        DFS(startvertex,endvertex);
                        break;
                }
            }
            break;
        }
        default:
            cout << "Invalid graph type" << endl;
            break;
    }

    return 0;
}


