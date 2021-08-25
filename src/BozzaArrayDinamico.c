


typedef struct _node{
    Node *next;
    int aborted;
    int finished;
    int lengthpath;
    /*many more*/
}Node;


typedef struct _superarray{
    Node *first;
    int status;
    int sourceX, sourceY, destX, destY;
}SuperArray;

SuperArray *creator(){

    SuperArray *x=(SuperArray *)malloc(sizeof(SuperArray));;
    x->first= NULL;
    x->aborted=0;
    x->finished=0;
    x->lengthpath=0;
    return x;
}

Node *addRide(SuperArray queue, /**/){
    Node *x=(SuperArray *)malloc(sizeof(SuperArray));
    x->next=queue->first;
    queue->first=x;

    return x;
}

void setAborted(SuperArray queue){
    queue->aborted++;
    return;
}

void setFinished(SuperArray queue){
    queue->finished++;
    return;
}

void setLengthPath(SuperArray queue, int km){
    queue->lengthpath=queue->lengthpath+km;
    return;
}



int getAborted(SuperArray queue){
    return queue->aborted;
    
}

int getFinished(SuperArray queue){
    return queue->finished++;
}

int getLengthPath(SuperArray queue){
    return queue->lengthpath=queue;
}