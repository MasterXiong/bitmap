#include <iostream>
#include <vector>

typedef std::vector<bool> BitMap;
typedef std::vector<int> WAH;

class Bitmap {
 public:
  
  // ReadData: import the path of ipdata.txt, update ip_data and bitmap
  void ReadData (string data_path); 

  // CompressWAH: compress bitmap to bitmapWAH
  void CompressWAH ();

  // DecompressWAH: input the index of eight ip data, update search_result
  void DecompressWAH (int search_index[]);

  // QueryResponse: operate on search_result and provide the output
  void QueryResponse ();
 
 private:
  struct IP
  {
	unsigned char data[8];
  }ip;
  struct BM
  {
	int data[256*8];
	BM()
	{
		for(int i=0;i<256*8;i++)
			data[i] = 0;
	}
  }bitmap_row;
  std::vector<IP> ip_data;      // each element of ip_data saves one row of ipdata info
  std::vector<BM> bitmap;      // each element of bitmap is one column of the overall bitmaps
  std::vector<int> final_bimap[256*8];
  WAH bitmapWAH[256*8];      // each element of bitmapWAH is transfered from the corresponding element in bitmap in the form of WAH
  BitMap search_result[8];
}
