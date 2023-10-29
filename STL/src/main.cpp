#include"../Headers/write.h"
#include"../Headers/read_STL.h"

int main()
{
    Read robj;
    robj.Read_from_STL_File();

    Write wobj;
    wobj.Write_in_Files();
    
    return 0;
}