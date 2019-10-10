#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    std::ifstream  data("file.csv");

    std::string line;
    int x=0;	
    while(std::getline(data,line))
    {
        std::stringstream  lineStream(line);
        std::string        cell;
        while(std::getline(lineStream,cell,','))
        {
           if(cell.compare("ARP"))
	{
	   x++;
	}
        }
    }

	cout<<x;
 }
