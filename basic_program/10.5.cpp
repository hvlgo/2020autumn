#include<fstream>
#include<stdint.h>
using namespace std;
#pragma pack(1)
struct BitMapFileHeader {
    uint16_t bfType;      // 2字节，文件类型（magic number），一般为0x4D42；
    uint32_t bfSize;      // 4字节，BMP文件的大小（单位为字节）；
    uint16_t bfReserved1; // 2字节，保留，一般设置为0；
    uint16_t bfReserved2; // 2字节，保留，一般设置为0；
    uint32_t bfOffBits;   // 4字节，位图数据（像素数组）的地址偏移，也就是起始地址。
};
 
struct BitMapInfoHeader {
    uint32_t biSize;          // 4字节，信息头的大小，即40；
    int32_t biWidth;          // 4字节，（有符号整数）以像素为单位说明图像的宽度；
    int32_t biHeight;         // 4字节，（有符号整数）以像素为单位说明图像的高度;
    uint16_t biPlanes;        // 2字节，为目标设备说明颜色平面数，总被设置为1；
    uint16_t biBitCount;      // 2字节，说明比特数/像素数，值有1、2、4、8、16、24、32；
    uint32_t biCompression;   // 4字节，说明图像的压缩类型，最常用的就是0（BI_RGB），表示不压缩；
    uint32_t biSizeImages;    // 4字节，说明位图数据的大小，当用BI_RGB格式时，可以设置为0；
    int32_t biXPelsPerMeter;  // 4字节，（有符号整数）表示水平分辨率，单位是像素/米；
    int32_t biYPelsPerMeter;  // 4字节，（有符号整数）表示垂直分辨率，单位是像素/米；
    uint32_t biClrUsed;       // 4字节，说明位图使用的调色板中的颜色索引数，为0说明使用所有；
    uint32_t biClrImportant;  // 4字节，说明对图像显示有重要影响的颜色索引数，为0说明都重要；
};
 
struct Pixel {
    uint8_t blue;
    uint8_t red;
    uint8_t green;
};
#pragma pack()
int main()
{
    BitMapFileHeader file;
    file.bfType = 0x4D42;
    file.bfSize = 480054;
    file.bfReserved1 = 0;
    file.bfReserved2 = 0;
    file.bfOffBits = 54;
    BitMapInfoHeader info;
    info.biSize = 40;
    info.biWidth = 400;
    info.biHeight = 400;
    info.biPlanes = 1;
    info.biBitCount = 24;
    info.biCompression = 0;
    info.biSizeImages = 480000;
    info.biXPelsPerMeter = 1000;
    info.biYPelsPerMeter = 1000;
    info.biClrUsed = 0;
    info.biClrImportant = 0;
    ifstream fin("input.txt");
    int x,y,r;
    fin >> x >> y >> r;
    fin.close();
    ofstream fout("output.bmp",ios::binary);
    fout.write((char*)(&file),sizeof(file));
    fout.write((char*)(&info),sizeof(info));
    for(int y_ = 0;y_ < 400;y_++)
        for(int x_ = 0;x_ < 400;x_++)
            {
                if((x-x_)*(x-x_) + (y-y_)*(y-y_) < r*r)
                    {
                        Pixel xiangsu;
                        xiangsu.blue = 255;
                        xiangsu.green = 255;
                        xiangsu.red = 255;
                        fout.write((char*)(&xiangsu),sizeof(xiangsu));
                    }
                else
                {
                    Pixel xiangsu;
                        xiangsu.blue = 0;
                        xiangsu.green = 0;
                        xiangsu.red = 0;
                        fout.write((char*)(&xiangsu),sizeof(xiangsu));
                }
                
            }
    fout.close();
    return 0;
}