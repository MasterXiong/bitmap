#include<bitmap.h>
#include<fstream>
#include<string>
using namespace std;

//int main()
void ReadData(string data_path)
{
	string str;
	char *ch,*token;
	int cnt=0;
	ifstream file(data_path);             //open data file
	//ifstream file("ipdata.txt");

	while(getline(file,str))
  {
		ch =new char[str.length()+1];       //change string into char
		strcpy(ch,str.c_str());

		token = strtok(ch,",");  

		while(token!=NULL)                  //get ip data in 8 blocks
		{
			if(cnt<=7&&atoi(token)<256)
			{
				ip.data[cnt] = atoi(token);
				cnt++;
			}
			token=strtok(NULL,",");
		}
		ip_data.push_back(ip);              //add new ip to ip_data vector
		cnt = 0;
  }

	unsigned int i,j;
	for(i=0;i<ip_data.size();i++)         //make bitmap according to ip_data 
	{
		for(j=0;j<8;j++)
		{
			bitmap_row.data[j*256+int(ip_data[i].data[j])-1] = 1;
		}
		bitmap.push_back(bitmap_row);
	}
	file.close();
}
