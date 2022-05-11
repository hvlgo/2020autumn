#include <fstream>
using namespace std;
 
#pragma pack(1)
struct BitMapFileHeader {
    uint16_t bfType;      // 2字节，文件类型（magic number），一般为0x4D42；
    uint32_t bfSize;      // 4字节，文件大小；
    uint16_t bfReserved1; // 2字节，保留，一般设置为0；
    uint16_t bfReserved2; // 2字节，保留，一般设置为0；
    uint32_t bfOffBits;   // 4字节，从头到位图数据的偏移；
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
#pragma pack()
int main()
{
    BitMapFileHeader header;
    BitMapInfoHeader info;
    ifstream fin ("input.bmp",ios::binary);
    fin.read((char *)(&header), sizeof(header));
    fin.read((char *)(&info), sizeof(info));
    fin.close();
    ofstream fout("output.txt");
    fout << "bfType=" << header.bfType << endl
        << "bfSize=" << header.bfSize << endl
        << "bfReserved1=" << header.bfReserved1 << endl
        << "bfReserved2=" << header.bfReserved2 << endl
        << "bfOffBits=" << header.bfOffBits << endl
        << "biSize=" << info.biSize << endl
        << "biWidth=" << info.biWidth << endl
        << "biHeight=" << info.biHeight << endl
        << "biPlanes=" << info.biPlanes << endl
        << "biBitCount=" << info.biBitCount << endl
        << "biCompression=" << info.biCompression << endl
        << "biSizeImages=" << info.biSizeImages << endl
        << "biXPelsPerMeter=" << info.biXPelsPerMeter << endl
        << "biYPelsPerMeter=" << info.biYPelsPerMeter << endl
        << "biClrUsed=" << info.biClrUsed << endl
        << "biClrImportant=" << info.biClrImportant << endl;
        fout.close();
    return 0;
}