%module area
%{
extern double pi;
extern double area_of_circle(int r);
extern int area_of_square(int n);
%}
/* If we don't want to access pi variable from the perl, then comment
the below line.
*/
extern double pi;
extern int area_of_square(int n);
extern double area_of_circle(int r);
