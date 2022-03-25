#include <iostream>

#include <fstream>

#include <string>

 

using namespace std;

 



struct Student

{

  string first, last;

  int grade;

};

istream& operator>>(istream& in, Student &S);

ostream& operator<<(ostream& out, Student S);

void sort(Student *A, int N);

void swap(Student &studentA, Student &studentB);

 


bool before(Student a, Student b);

 

int main()

{
// #ifndef ONLINE_JUDGE
//         freopen("results.txt","w",stdout);
//     #endif


  string fname;

  cout << "Enter file name: ";

  cin >> fname;

  ifstream fin(fname.c_str());

 



  int n;

  string junk;

  fin >> n >> junk;

  Student *S = new Student[n];

  for(int i = 0; i < n && fin >> S[i]; ++i);

 


  sort(S,n);

  for(int i = 0; i <n ; ++i)

    cout << S[i] << endl;

 

  return 0;

}

 


istream& operator>>(istream& in, Student &S)

{

  return in >> S.first >> S.last >> S.grade;

}

 

ostream& operator<<(ostream& out, Student S)

{

  return out << S.first << ' ' << S.last << ' ' << S.grade;

}

 

bool before(Student a, Student b)

{

        if(a.grade==b.grade)

               if (a.last<b.last)

                       return true;

               else

                       return false;

        else

               if (a.grade<b.grade)

                       return false;

               else

                       return true;

}

 

void sort(Student *A, int N)

{

  for(int length = N; length > 1; length--)

  {


    int imax = 0, i;

    for(i = 1; i < length; i++)

      if (before(A[imax],A[i]))

        imax = i;

    swap(A[imax],A[length-1]);

  }

}

 

 

void swap(Student &studentA, Student &studentB)

{

  Student temp = studentA;

  studentA = studentB;

  studentB = temp;

 

}