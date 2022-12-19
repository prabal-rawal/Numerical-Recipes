#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <fstream>   
using namespace std;

#define SIZE 10  // Macros
using namespace std;
class methods
{
public:
    float a[10][10], l[10][10], u[10][10];  // 2D Array
    float x[SIZE], ratio;
    int n = 0, i = 0, j = 0;
    int matrix[10][10];

    void GaussElimination(float a[SIZE][SIZE], float x[SIZE], float ratio)
    {
        int i, j, k, n;
        cout << setprecision(3) << fixed;

        /* Inputs */
        /* 1. Reading number of unknowns */
        cout << "Enter number of unknowns: ";
        cin >> n;

        /* 2. Reading Augmented Matrix */
        cout << "Enter Coefficients of Augmented Matrix: " << endl;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n + 1; j++)
            {
                cout << "a[" << i << "]" << j << "]= ";
                cin >> a[i][j];
            }
        }
        /* Applying Gauss Elimination */
        
        for (i = 1; i <= n - 1; i++)
        {
            if (a[i][i] == 0.0)
            {
                cout << "Mathematical Error!";
                exit(0);
            }
            for (j = i + 1; j <= n; j++)
            {
                ratio = a[j][i] / a[i][i];

                for (k = 1; k <= n + 1; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
        
        /* Obtaining Solution by Back Substitution Method */
        x[n] = a[n][n + 1] / a[n][n];

        for (i = n - 1; i >= 1; i--)
        {
            x[i] = a[i][n + 1];
            for (j = i + 1; j <= n; j++)
            {
                x[i] = x[i] - a[i][j] * x[j];
            }
            x[i] = x[i] / a[i][i];
        }
        cout << endl
             << "Solution: " << endl;
        for (i = 1; i <= n; i++)
        {
            cout << "x[" << i << "] = " << x[i] << endl;
        }
    }

    inline int determinant(int matrix[10][10], int n)
    {
        int det = 0;
        int submatrix[10][10];
        if (n == 2)
            return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
        else
        {
            for (int x = 0; x < n; x++)
            {
                int subi = 0;
                for (int i = 1; i < n; i++)
                {
                    int subj = 0;
                    for (int j = 0; j < n; j++)
                    {
                        if (j == x)
                            continue;
                        submatrix[subi][subj] = matrix[i][j];
                        subj++;
                    }
                    subi++;
                }
                det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
            }
        }
        return det;
    }
    void show_data2()
    {
        cout << "The entered matrix is:" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << "Determinant of the matrix is " << determinant(matrix, n);
    }
    friend void design();
};

// SINGLE INHERITANCE
 class methods1: public methods{

    public:void LUdecomposition(float a[10][10], float l[10][10], float u[10][10], int n)
    {
        int i = 0, j = 0, k = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (j < i)
                    l[j][i] = 0;
                else
                {
                    l[j][i] = a[j][i];
                    for (k = 0; k < i; k++)
                    {
                        l[j][i] = l[j][i] - l[j][k] * u[k][i];
                    }
                }
            }
            for (j = 0; j < n; j++)
            {
                if (j < i)
                    u[i][j] = 0;
                else if (j == i)
                    u[i][j] = 1;
                else
                {
                    u[i][j] = a[i][j] / l[i][i];
                    for (k = 0; k < i; k++)
                    {
                        u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
                    }
                }
            }
        }
    }
    void show_data(float l[10][10], float u[10][10], int n)
    {
        cout << "L Decomposition is as follows..." << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << l[i][j] << " ";
            }
            cout << endl;
        }
        cout << "U Decomposition is as follows..." << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << u[i][j] << " ";
            }
            cout << endl;
        }
    }

 };
void design()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\tLOADING ";
    char x = 219;
    for (int i = 0; i < 35; i++)
    {
        cout << x;
        if (i < 10)
            Sleep(300); // this makes program pause for few seconds
        if (i >= 10 && i < 20)
            Sleep(150);
        if (i >= 10)
            Sleep(25);
    }
    system("cls"); // this makes screen clear
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\tHi ! WELCOME TO NUMERICAL RECIPIES IN C++";
}

class Complex
{
private:
    int a, b;

public:
    Complex()       // Default Constructor
    {
        a = 0;
        b = 0;
    }
    void getData()
    {
        cout << "Enter Real Part: ";
        cin >> a;
        cout << "Enter Imaginary Part: ";
        cin >> b;
    }
    void showData()
    {
        cout << a << "+i(" << b << ")" << endl;
    }

    // Operator Overloading
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        return temp;
    }
    Complex operator-(Complex c)
    {
        Complex temp;
        temp.a = a - c.a;
        temp.b = b - c.b;
        return temp;
    }
    Complex operator*(Complex c)
    { // (a+ib)(c+id)=(ac-bd)+i(ad+bc)
        Complex temp;
        temp.a = a * c.a - b * c.b;
        temp.b = a * c.b + b * c.a;
        return temp;
    }
    Complex operator/(Complex c)
    {
        Complex temp;
        temp.a = (a * c.a + b * c.b) / (c.a * c.a + c.b * c.b);
        temp.b = (-a * c.b + b * c.a) / (c.a * c.a + c.b * c.b);
        return temp;
    }

    // Equation of Circle
    //  friend void equationOfCircle(Complex c)
};

// void Complex::equationOfCircle(Complex c){
//     float radius = sqrt(c.a * c.a + c.b * c.b);
//     cout << "z=" << radius << endl;
// }

   


class root
{
    private:
        double x,a,b,tol;
    public:
    double f(double x)
    {
         return x * x * x - 2 * x - 5;
        
    }
    root(double x0,double x1,double x2){
        a=x0;
        b=x1;
        tol=x2;
    }
    root(double s , double r){
        x=s;
        tol=r;

    }
    // void getData(){
    //     cout << "Enter a: "; cin>>a;
    //     cout<< "Enter b: "; cin>>b;
    //     cout << "Enter tol: "; cin>>tol;
    // }
    double bisection(double a, double b, double tol)
    {
        double c;
        int i = 0;
        while (abs(b - a) > tol)
        {
            c = (a + b) / 2;
            if (f(a) * f(c) < 0)
                b = c;
            else
                a = c;
            i++;
        }
        cout << "Bisection method: " << i << " iterations" << endl;
        return c;
    }
    double secant(double a, double b, double tol)
    {
        double c;
        int i = 0;
        while (abs(b - a) > tol)
        {
            c = b - f(b) * (b - a) / (f(b) - f(a));
            a = b;
            b = c;
            i++;
        }
        cout << "Secant method: " << i << " iterations" << endl;
        return c;
    }
      double newton(double x, double tol)
    {
        double c;
        int i = 0;
        while (abs(f(x)) > tol)
        {
            c = x - f(x) / (3 * x * x - 2);
            x = c;
            i++;
        }
        cout << "Newton Rapson method: " << i << " iterations" << endl;
        return c;
    }
};
  
class Interpolation
{
private:
    float x[100], y[100], xp, yp = 0, p;
    int i, j, n;

public:
    void getData()
    {
        cout << "Enter number of data points: ";
        cin >> n;
        cout << "Enter data: " << endl;
        for (i = 1; i <= n; i++)
        {
            cout << "x[" << i << "] = ";
            cin >> x[i];
            cout << "y[" << i << "] = ";
            cin >> y[i];
        }
        cout << "Enter interpolation point: ";
        cin >> xp;
    }
    void lagrangeInterpolation()
    {
        for (i = 1; i <= n; i++)
        {
            p = 1;
            for (j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    p = p * (xp - x[j]) / (x[i] - x[j]);
                }
            }
            yp = yp + p * y[i];
        }
    }
    void showData()
    {
        cout << "Interpolated value at " << xp << " is " << yp << endl;
    }
};

int main()
{
    int choice;
    system("color 0b");
      design();

    do
    {
        cout << "\n\n\n\t\t\t\t\t\t+-/+-/+-/+-/+-/+-/+-/+-/+-/+-/+-/+-/";
        cout << "\n\t\t\t\t\t\t\tWhat would you like to perform?" << endl;
        cout << "\t\t\t\t\t\t\t1.LU Decomposition" << endl;
        cout << "\t\t\t\t\t\t\t2.Gauss Elimination" << endl;
        cout << "\t\t\t\t\t\t\t3.Compute Determinant" << endl;
        cout << "\t\t\t\t\t\t\t4.Complex Arithmetic" << endl;
        cout << "\t\t\t\t\t\t\t5.Interpolation" << endl; 
        cout << "\t\t\t\t\t\t\t6.Iteration Methods" <<endl;
        cout << "\t\t\t\t\t\t\t7.Exit" << endl;
        cout << "\t\t\t\t\t\t+-/+-/+-/+-/+-/+-/+-/+-/+-/+-/+-/+-/" << endl;
        cout << " --->>> Enter your choice here:-";
        cin >> choice;
        if (choice == 1)
        {
            float a[10][10], l[10][10], u[10][10];
            int n = 0, i = 0, j = 0;
            methods1 c;
            cout << "Enter size of square matrix : " << endl;
            cin >> n;

            cout << "Enter matrix values: " << endl;
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    cin >> a[i][j];

            c.LUdecomposition(a, l, u, n);
            c.show_data(l, u, n);
            int val;
            cout<<"\n** Press 0 to continue\t"<<"Press -1 to exit** "<<endl;
            cout<<"\n--->>> Enter your choice here:-";
            cin>>val;
            if (val==0)
            {
                main();
            }
            if(val==-1){
                exit(0);
            }
            


        }
        if (choice == 2)
        {
            float a[SIZE][SIZE], x[SIZE], ratio;
            int i, j, k, n;
            methods g;
            g.GaussElimination(a, x, ratio);
             int val;
            cout<<"\n** Press 0 to continue\t"<<"Press -1 to exit ** "<<endl;
            cout<<"\n--->>> Enter your choice here:-";
            cin>>val;
            if (val==0)
            {
                main();
            }
            if(val==-1){
                exit(0);
            }
        }
        if (choice == 3)
        {
            int n, i, j;
            int matrix[10][10];
            methods d;
            cout << "\nEnter the size of the matrix:";

            cin >> n;
            cout << "\nEnter the elements of the matrix:";

            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    cin >> matrix[i][j];
            cout << "The entered matrix is:" << endl;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                    cout << matrix[i][j] << " ";
                cout << endl;
            }
            cout << " Determinant of the matrix is:- " << d.determinant(matrix, n) << endl;
        
             int val;
            cout<<"\n** Press 0 to continue\t"<<"Press -1 to exit ** "<<endl;
            cout<<"\n--->>> Enter your choice here:-";
            cin>>val;
            if (val==0)
            {
                main();
            }
            if(val==-1){
                exit(0);
            }
        }
        if (choice == 4)
        {
            Complex c1, c2, c3;
            c1.getData();
            c2.getData();
            cout << "What would you like to perform?" << endl;
            cout << "1.Addition | 2.Subtraction | 3.Multiplication | 4.Division" << endl;
            int operatorNo;
            cin >> operatorNo;
            switch (operatorNo)
            {
            case 1:
                c3 = c1 + c2;
                break;
            case 2:
                c3 = c1 - c2;
                break;
            case 3:
                c3 = c1 * c2;
                break;
            case 4:
                c3 = c1 / c2;
                break;
            }
            c3.showData();
             int val;
            cout<<"* Press 0 to continue\t"<<"Press -1 to exit * "<<endl;
            cout<<"--->>> Enter your choice here:-";
            cin>>val;
            if (val==0)
            {
                main();
            }
            if(val==-1){
                exit(0);
            }
        }
        if (choice == 5)
        {
            Interpolation data;
            data.getData();
            data.lagrangeInterpolation();
            data.showData();
             int val;
            cout<<"* Press 0 to continue\t"<<"Press -1 to exit * "<<endl;
            cout<<"--->>> Enter your choice here:-";
            cin>>val;
            if (val==0)
            {
                main();
            }
            if(val==-1){
                exit(0);
            }
        }
        // if(choice == 6){
        //     Complex c1;
        //     c1.getData();
        //     c1.equationOfCircle(c1);
        // }
        if(choice == 6){
            double x0,x1,x2,x3,x4;
              int option;
            cout << "Enter Method Choice: 1.Bisection Method | 2.Secant Method | 3. Newton Method" << endl;
            cin >> option;
           
            
            root r(x0,x1,x2);
            root s(x3 ,x4);
            // r.getData(); 
          
           
            switch(option){
                case 1: {  cout<<"enter the values x0,x1,x2"<<endl;
                           cin>>x0>>x1>>x2;
                           r.bisection(x0,x1,x2);
                break;}
                case 2:{
                          cout<<"enter the values x0,x1,x2"<<endl;
                           cin>>x0>>x1>>x2;
                            r.secant(x0,x1,x2);
                break ;}
                case 3:{
                     cout<<"enter the values x3,x4"<<endl;
                           cin>>x3>>x4;
                          s.newton(x3,x4);

                }
                default: cout<<"Enter Valid Option" <<endl;
            }
                 int val;
            cout<<"\n*** Press 0 to continue\t"<<"Press -1 to exit *** "<<endl;
            cout<<"--->>> Enter your choice here:-";
            cin>>val;
            if (val==0)
            {
                main();
            }
            if(val==-1){
                exit(0);
            }


            
        }
    } while (choice >= 1 && choice < 8);
    return 0;
}