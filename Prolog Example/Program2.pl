%Parker Spaan
%3/24/2023
%Prolog Program2. 
/*This code will simply create all of the predicates that the the Assignment2 requests */


/*This finds the start of a factorial. Sending in the value and reponding with what the 
number is for that factorial */

factorial(0,1).             /*Base case. If the first num is 0 return a 1 */
factorial(Val,R) :-
    Val > 0,                /*once the value is no longer larger than 0 return everything */
    Last is Val - 1,        /* decrimenting the value. */
    factorial(Last, RLast), /* passing the last value in and getting a new returned*/
    R is Val * RLast.       /*Multiply the current value times the past as its popped off. */
    
isFactorial(X, Fact) :-
    between(1,Fact,X),  /* if the X is between the Fact value and 1 */
    factorial(X, R),    /* findings the facrotial of the number is a factorial*/
    Fact =:= R;         /* Returns X if its equal to the R value, otherwise its false */
    false.              /* otherwise it is a false value */


/*This predicate will take in a list of numbers and atoms. With another list containing
these values. It will then return a list stating how many of each are in second list. */

howMany(_, [], 0).             /* base case. If there is no list or value of number return 0 */
howMany(Val, [H|T], Z):-         /* Pass in our list, break it, with our value */
    Val = H,                     /* if the value is the same as first value*/
    howMany(Val, T, P),          /* send the rest of the list back in to find the rest*/
    Z is P + 1 ;                    
    howMany(Val, T, Z).          /* otherwise just send the value back in. */

numInList([],_,[]).            /* Base case */
numInList([H|T], L, [S|F]):- /* takes the two lists and gets the third list ready to fill*/
     howMany(H, L, S),         /* sends the start of orginal list, list being checked, and the 
                               head the first value of the new empty list. to find how many*/
     numInList(T, L, F).     /* Sends the rest of the list back through */


/*Below will take in a list and split it equally between two. This will split it evenly. IF
it is an odd number then the second list will have one more value than the first. */
div([],_,_).
div(List, Lst1, Lst2) :-
    length(List, N),          /* setting n to be the length of the list */
    Half is N // 2,           /* Half is the value of N divided by 2 */
    length(Lst1, Half),       /* making Lst1 the length of the halfway */
    append(Lst1, Lst2, List). /* With Lst1 being the length of half it will then append values
                                from lst1 until full. Then lst2 will get the rest*/

/*This will calculate the Collatz function. Taking in a value and finding what its value was
This was completed in the test.  If the value is even it will utilize one function, where if 
its odd it will utilize the other.*/

collatz(1, [1]).      /*Base case */
collatz(N, [N|T]) :-  /*Taking in our number, getting the values ready to be placed into the list */
    N > 1,            /*as long as the value is above 1 */    
   (N mod 2 =:= 0 -> Ans is N // 2 ; Ans is 3*N + 1), /*If the value is even, do the first equation
                      otherwise do the second. */
    collatz(Ans, T).  /*Take the answer found and put it into the list */

nCollatz(Num, X) :-    /*Getting initial value and the value that is to be retuend */
    collatz(Num, Ans), /*sending the value to the collatz function to figure out*/
    length(Ans, X).    /* finding hte length of the list returned and will return this*/