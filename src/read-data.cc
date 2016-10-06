#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

struct IP
{
	unsigned char data[8];
}ip;
std::vector<IP> ip_data;

struct BM
{
	int data[256*8+1];
	BM()
	{
		for(int i=0;i<256*8;i++)
			data[i] = 0;
	}
}bitmap_row;
std::vector<BM> bitmap;

vector<int> final_bitmap[256*8+1];

//typedef std::vector<col_map> Col_map;

int main()
//void ReadData(string data_path)
{
	string str;
	char *ch,*token;
	int cnt=0;
	//ifstream file(data_path);
	ifstream file("ipdata.txt");

	while(getline(file,str))
    {
		ch =new char[str.length()+1];
		strcpy(ch,str.c_str());

		token = strtok(ch,",");  

		while(token!=NULL)
		{
			if(cnt<=7&&atoi(token)<256)
			{
				ip.data[cnt] = atoi(token);
				cnt++;
			}
			token=strtok(NULL,",");
		}
		ip_data.push_back(ip);
		cnt = 0;
    }

	unsigned int i,j,k;
	for(i=0;i<ip_data.size();i++)
	{
		for(j=0;j<8;j++)
		{
			bitmap_row.data[j*256+int(ip_data[i].data[j])-1] = 1;
		}
		bitmap.push_back(bitmap_row);
		for(k=0;k<256*8;k++)
			bitmap_row.data[k] = 0;
	}

	//transform
	for(i=0;i<256*8;i++)
	{
		for(j=0;j<ip_data.size();j++)
			final_bitmap[i].push_back(bitmap[j].data[i]);
	}

	file.close();
}
