#include <bits/stdc++.h> 

class Stack {

    queue<int> q1, q2;

    int size;

 

   public:

    Stack() {

        size = 0;

    }

 

    /*----------------- Public Functions of Stack -----------------*/

 

    int getSize() {

 

        return size;

    }

 

    bool isEmpty() {

 

       if(size == 0)

       {

           return true;

       }

       else

       {

           return false;

       }

    }

 

    void push(int element) {

 

        // Step 1 : Push Element into q2

        q2.push(element);

 

        // Step 2 : Push all the elements of q1 into q2

        while(!q1.empty())

        {

            int val = q1.front();

            q1.pop();

            q2.push(val);

        }

 

        // Step 3 : Swap q1 and q2

        swap(q1, q2);

 

        // Step 4 : Update the value of size

        size++;

    }

 

    int pop() {

        

        // Simply Pop from q1

        if(!q1.empty())

        {

            int val = q1.front();

            q1.pop();

 

            // Update the value of size

            size--;

            return val;

        }

        else{

            return -1;

        }

        

    }

 

    int top() {

 

        // Return front of q1

        if(!q1.empty())

        {

            return q1.front();

        }

        else

        {

          return -1;
        }
    }
};
