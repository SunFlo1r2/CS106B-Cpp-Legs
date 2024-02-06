/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include "console.h"
#include <iostream>
#include <cmath>
#include "SimpleTest.h"
#include "perfect.h"
using namespace std;

/* The divisorSum function takes one argument `n` and calculates the
 * sum of proper divisors of `n` excluding itself. To find divisors
 * a loop iterates over all numbers from 1 to n-1, testing for a
 * zero remainder from the division using the modulus operator %
 *
 * Note: the C++ long type is a variant of int that allows for a
 * larger range of values. For all intents and purposes, you can
 * treat it like you would an int.
 */
long divisorSum(long n) {
    long total = 0;
    for (long divisor = 1; divisor < n; divisor++) {
        if (n % divisor == 0) {
            total += divisor;
        }
    }
    return total;
}

/* The isPerfect function takes one argument `n` and returns a boolean
 * (true/false) value indicating whether or not `n` is perfect.
 * A perfect number is a non-zero positive number whose sum
 * of its proper divisors is equal to itself.
 */
bool isPerfect(long n) {
    return (n != 0) && (n == divisorSum(n));
}

/* The findPerfects function takes one argument `stop` and performs
 * an exhaustive search for perfect numbers over the range 1 to `stop`.
 * Each perfect number found is printed to the console.
 */
void findPerfects(long stop) {
    for (long num = 1; num < stop; num++) {
        if (isPerfect(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush; // progress bar
    }
    cout << endl << "Done searching up to " << stop << endl;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
long smarterSum(long n) {
    /* TODO: Fill in this function. */
    long total=0;
    for(long divisor=1;divisor<sqrt(n)+1;divisor++){
        if (n%divisor==0){
            total+=divisor;
        }
    }
    return total;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
bool isPerfectSmarter(long n) {
    /* TODO: Fill in this function. */
    if(smarterSum(n)==n&&n!=0)
    {
        return true;
    }
    return false;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
void findPerfectsSmarter(long stop)
{
     /* TODO: Fill in this function. */
    for(long num=1;num<stop;num++)
     {
         if(isPerfect(num)==true)
        {
            cout<<"Find perfect numbers:"<<num<<endl;
        }
         if (num % 10000 == 0) cout << "." << flush; // progress bar
    }
    cout << endl << "Done searching up to " << stop << endl;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
bool isPrime(long n){
    long total=0;
    for(int i=1;i<n;i++){
        if(n%i==0)
        {
            total++;
        }
    }
    if(total==1){
        return true;
    }
    else{
        return false;
    }
}


long findNthPerfectEuclid(long n) {
    // Initialize k outside the loop
    while (true) {
        long m = -1 + pow(2, n);
        if (isPrime(m)) {
            return (pow(2, n - 1) * (pow(2, n) - 1));
        } else {
            n++;
            continue;
        }
    }
}

/* * * * * * Test Cases * * * * * */

// TODO: add your STUDENT_TEST test cases here!
STUDENT_TEST("confirm Negative numbers are not perfect"){
    EXPECT(isPerfect(-6));
    EXPECT(isPerfect(-28));
}


STUDENT_TEST("confirm function smarterSum is as well as divisorSum"){
    EXPECT_EQUAL(smarterSum(25),divisorSum(25));
    EXPECT_EQUAL(smarterSum(37),divisorSum(37));
    EXPECT_EQUAL(smarterSum(49),divisorSum(49));
}

STUDENT_TEST("confirm function findNthPerfectEuclid is all right"){
    EXPECT(isPerfect(findNthPerfectEuclid(1)));
    EXPECT(isPerfect(findNthPerfectEuclid(2)));
    EXPECT(isPerfect(findNthPerfectEuclid(3)));
    EXPECT(isPerfect(findNthPerfectEuclid(4)));
    EXPECT(isPerfect(findNthPerfectEuclid(5)));
}

/*
 * Here is sample test demonstrating how to use a loop to set the input sizes
 * for a sequence of time trials.
 */
//STUDENT_TEST("Multiple time trials of findPerfects on increasing input sizes") {
//    int smallest = 1000, largest = 8000;
//    for (int size = smallest; size <= largest; size *= 2) {
//        TIME_OPERATION(size, findPerfects(size));
//    }
//}


/* Please not add/modify/remove the PROVIDED_TEST entries below.
 * Place your student tests cases above the provided tests.
 */

PROVIDED_TEST("Confirm divisorSum of small inputs") {
    EXPECT_EQUAL(divisorSum(1), 0);
    EXPECT_EQUAL(divisorSum(6), 6);
    EXPECT_EQUAL(divisorSum(12), 16);
}

PROVIDED_TEST("Confirm 6 and 28 are perfect") {
    EXPECT(isPerfect(6));
    EXPECT(isPerfect(28));
}

PROVIDED_TEST("Confirm 12 and 98765 are not perfect") {
    EXPECT(!isPerfect(12));
    EXPECT(!isPerfect(98765));
}

PROVIDED_TEST("Test oddballs: 0 and 1 are not perfect") {
    EXPECT(!isPerfect(0));
    EXPECT(!isPerfect(1));
}

PROVIDED_TEST("Confirm 33550336 is perfect") {
    EXPECT(isPerfect(33550336));
}

PROVIDED_TEST("Time trial of findPerfects on input size 1000") {
    TIME_OPERATION(1000, findPerfects(1000));
}
