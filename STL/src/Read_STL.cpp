#include<iostream>
#include<fstream>
#include<sstream>
#include"../Headers/read_STL.h"
#include<string>
using namespace std;

Read :: Read(){}

Read :: ~Read(){}

void Read :: Read_from_STL_File()
{
    ifstream in;
    in.open("D:\\Dinesh\\STL5\\STL_Files\\flowerpot.stl");

    ofstream out;
    out.open("D:\\Dinesh\\STL5\\TextFiles\\Sample.txt");
    string s,s1, s2, s3;
    double n1,n2,n3,iCnt;
    string Firstline;
    
    while(in.eof() == 0)
    {
      getline(in,s);
      if(s.find("vertex") != std::string::npos)
      {
            std::istringstream iss(s);
            std::string token;
            double x, y, z;
            iss>>token>>x>>y>>z;
        
        out<<x<<" "<<y<<" "<<z<<endl;
        iCnt++;
        
        if(iCnt == 3)
        {
            iCnt = 0;
            out<<Firstline<<endl;
        }
      }
    }
    in.close();
    cout<<endl;
    
   
}