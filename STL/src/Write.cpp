#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"../Headers/write.h"
#include<cmath>
using namespace std;

Write :: Write(){}

Write :: ~Write(){};

void Write :: Write_in_Files()
{
    ifstream in;
    in.open("D:\\Dinesh\\STL\\STL_Files\\flowerpot.stl");

    ofstream out1;
    out1.open("D:\\Dinesh\\STL\\TextFiles\\BoundingBox.txt");
    string s;
    double x,y,z,iCnt,distance;
    
    getline(in,s);
    double Xmax = 0.0, Ymax = 0.0, Zmax = 0.0, Xmin = 0.0, Ymin = 0.0, Zmin = 0.0;
    double Xcen = 0.0, Ycen = 0.0, Zcen = 0.0;
    double Xdistance = 0.0, Ydistance = 0.0, Zdistance = 0.0, maincount = 0.0;

    while(in.eof() == 0)
    {
      getline(in,s);
    //s.erase(0,s.find_first_not_of(" \t"))
    //s.compare()
      if(s.find("vertex") != std::string::npos)
      {
            std::istringstream iss(s);
            std::string token;
            double x, y, z;
            iss>>token>>x>>y>>z;
    
        if(maincount == 0)
        {
            Xmax = Xmin =x;
            Ymax = Ymin = y;
            Zmax = Zmin = z;
            maincount = 1;
        }

        if(x > Xmax)
        {
            Xmax = x;
        }

        if(x < Xmin)
        {
            Xmin = x;
        }

        if(y > Ymax)
        {
            Ymax = y;
        }

        if(y < Ymin)
        {
            Ymin = y;
        }

        if(z > Zmax)
        {
            Zmax = z;
        }

        if(z < Zmin)
        {
            Zmin= z;
        }
    
      }
    }
    in.close();

    out1<<Xmin<<" "<<Ymin<<" "<<Zmin<<endl;
        out1<<Xmax<<" "<<Ymin<<" "<<Zmin<<endl;
        out1<<Xmax<<" "<<Ymax<<" "<<Zmin<<endl;
        out1<<Xmin<<" "<<Ymax<<" "<<Zmin<<endl;
        out1<<Xmin<<" "<<Ymin<<" "<<Zmin<<endl;
        out1<<Xmin<<" "<<Ymin<<" "<<Zmax<<endl;
        out1<<Xmax<<" "<<Ymin<<" "<<Zmax<<endl;
        out1<<Xmax<<" "<<Ymin<<" "<<Zmin<<endl;
        out1<<Xmax<<" "<<Ymax<<" "<<Zmin<<endl;
        out1<<Xmax<<" "<<Ymax<<" "<<Zmax<<endl;
        out1<<Xmax<<" "<<Ymin<<" "<<Zmax<<endl;
        out1<<Xmax<<" "<<Ymax<<" "<<Zmax<<endl;
        out1<<Xmin<<" "<<Ymax<<" "<<Zmax<<endl;
        out1<<Xmin<<" "<<Ymin<<" "<<Zmax<<endl;
        out1<<Xmin<<" "<<Ymax<<" "<<Zmax<<endl;
        out1<<Xmin<<" "<<Ymax<<" "<<Zmin<<endl;

    Xcen = ((4*Xmin) + (4*Xmax))/8;
    Ycen = ((4*Ymin) + (4*Ymax))/8;
    Zcen = ((4*Zmin) + (4*Zmax))/8;

    out1<<Xcen<<" "<<Ycen<<" "<<Zcen<<endl;

    in.close();

    ofstream out2;
    out2.open("D:\\Dinesh\\STL\\TextFiles\\disect1.txt");

    ofstream out3;
    out3.open("D:\\Dinesh\\STL\\TextFiles\\disect2.txt");
    
    in.open("D:\\Dinesh\\STL\\STL_Files\\flowerpot.stl");
    iCnt = 0;
    while(in.eof() == 0)
    {
      getline(in,s);
      if(s.find("vertex") != std::string::npos)
      {
            std::istringstream iss(s);
            std::string token;
            double x, y, z;
            iss>>token>>x>>y>>z;
        

        if(x >= Xcen)
        {
            out2<<Xcen-35<<" "<<y<<" "<<z<<endl;
            out3<<x+35<<" "<<y<<" "<<z<<endl;
        }
        else
        {
            out2<<x-35<<" "<<y<<" "<<z<<endl;
            out3<<Xcen+35<<" "<<y<<" "<<z<<endl;
        }   
      }
    }
    in.close();
    out1.close();
    out2.close();
    out3.close();
}
