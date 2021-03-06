/*
  needs point class ***************

  will use two points and create a linesegment which can return a lot of info




  */

#ifndef _LINESEG_H
#define _LINESEG_H

#define PI 3.141592654

#include <iostream>
#include <string> //for string
#include <sstream> //output stringstream
#include <cmath> //for math functions
#include <iomanip>
#include "point.h"
using namespace std;

class LineSeg
{
public:
  //Class constructors
  LineSeg();  //Default constructor
  LineSeg(Point first, Point second); //Will set the two points as they are given

  //Method Functions
  double slope(); //return the slope
  Point yint();   //Returns the theoretical y-int as a point
  Point midpoint(); //returns the midpoint of the line
  double dist();  //returns the distance of the segment
  Point xint();   //returns the x intercept
  double argument();
  double xdist();
  double ydist();
  string yform();
  string pointslope();

  string tostring();

  //Public members
  Point fpoint; //first point
  Point spoint; //second point
  Point temp; //made to use the other point functions on it
};

  LineSeg::LineSeg(Point first, Point second)
  {
    fpoint = first;
    spoint = second;
  }

  double LineSeg::slope()
  {
    double s = (spoint.gety()-fpoint.gety()) / (spoint.getx()-fpoint.getx()); //gets the line segment
    int bleh = int(s * 100);
    s = bleh / 100;
    return s;
  }
  double LineSeg::dist()
  {
    return (sqrt((xdist() * xdist())+(ydist() * ydist())));  //Pythag

  }
  Point LineSeg::yint()
  {
    Point out(0, 0);
    double b = fpoint.gety() - (slope() * fpoint.getx()); //y = mx + b to b = y - mx
    out.sety(b);  //set out point as y intercept
    return out;
  }
  Point LineSeg::xint() //y = mx+b -> 0 = mx+b
  {
    Point out(0, 0);  //temp point and is returned
    out = yint();
    double b = out.gety();  //makes b
    double xint = (0 - b) / slope();  //reverse standard function
    out.setx(xint);
    out.sety(0);
    return out; //return xint
  }
  Point LineSeg::midpoint()
  {
    double midx = (slope()/2) * fpoint.getx();
    double midy = (slope()/2) * fpoint.gety();
    Point mid(midx, midy);
    return mid;
  }
  double LineSeg::argument()
  {


    return ((atan((ydist() / xdist())) * 180)/PI);

  }
  double LineSeg::xdist()
  {
    return spoint.getx() - fpoint.getx();
  }
  double LineSeg::ydist()
  {
    return spoint.gety() - fpoint.gety();
  }
  string  LineSeg::yform()
  {
    ostringstream ss;
    string str;
    temp = yint();
    ss << "Y = " << slope() << "x + " << temp.gety();

    str = ss.str();
    return str;
  }
  string LineSeg::pointslope()
  {
    ostringstream ss;
    string str;
    ss << "(Y - Y1) = " << slope() << "(X - X1)";

    str = ss.str();
    return str;
  }


  string LineSeg::tostring()
  {
    ostringstream ss;
    string str;

    ss << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
    ss << "Points are " << fpoint.tostring() << " and " << spoint.tostring() << endl;
    ss << "Line slope is " << slope() << endl;
    ss << "Line distance is " << dist() << endl;
    temp = yint();
    ss << "Y-intercept is " << temp.tostring() << endl;
    temp = xint();
    ss << "X-intercept is " << temp.tostring() << endl;
    temp = midpoint();
    ss << "Midpoint is " << temp.tostring() << endl;
    ss << "The Argument is " << argument() << " degrees" << endl;
    ss << "\nY-intercept form is " << yform() << endl;
    ss << "The point-slope form is " << pointslope() << endl;
    str = ss.str();

    return str;
  }
#endif
