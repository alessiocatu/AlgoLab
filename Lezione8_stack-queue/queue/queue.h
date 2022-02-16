typedef struct queue *Queue;

// Put element on rear
void enqueue( Queue, int );

// Remove and return element from front
int dequeue( Queue );

// Return front element
int frontValue( Queue );

// Check if queue is empty
int is_empty_queue( Queue );

// Print queue content
void print_queue( Queue );
