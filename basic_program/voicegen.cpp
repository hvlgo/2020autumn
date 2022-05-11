#include <cstring>  // strlen
#include <fstream>  // ifstream, ofstream
#include <iostream> // cin, cout
using namespace std;

struct WavHead
{
    char riff_id[4];           //! 标识串"RIFF"
    long size0;                //波形块的大小
    char wave_fmt[8];          //! 标识串"WAVEfmt "
    long size1;                //格式块的大小
    short fmttag;              //波形编码格式
    short channel;             //音频数据的声道数
    long sampl;                //音频采样率
    long bytepersecblockalign; //每秒音频需要记录的字节数
    short blockalign;          //存储一个采样需要的字节数
    short bitpersamples;       //每个采样的二进制位数
    char data[4];              //! 标识串"data"
    long datasize;             //数据块大小
};

short* load_wav(char *File,WavHead* head) //文件传参的数据类型？
{
	ifstream in;
	in.open(File,ios::binary);
	in.read(reinterpret_cast<char*>(head),sizeof(WavHead));  //sizeof(head)?
	
	int len = head -> datasize / sizeof(short);
	short *pdata = new short[len];
	
	for(int i=0;i<len;i++)
		in.read(reinterpret_cast<char*>(&pdata[i]),sizeof(short));	
	in.close();
	
	return pdata;
} 

void load_labels(char *File, int *start, int *len)		//数组在传参时一般都是传指针?
{
	ifstream fin;
	fin.open(File);		
	for (int i = 0; i < 10; i++)
	{
		int x;
		fin >> x >> start[i] >> len[i];			
	}
	fin.close();
}

int main(int argc, char *argv[])
{
    WavHead head;
    short *pdata = load_wav("template.wav", &head);

    int start_sample[10], len_samples[10];
    load_labels("template_label_sample_point.txt", start_sample, len_samples);

	int nums[100] = {0};
	int n; cin >> n;
	for(int i=1;i<=n;i++)
		cin >> nums[i];

	long datasize_ = 0;
	for(int i = 1;i <= n;i++)
	{
		datasize_ += len_samples[nums[i]]*sizeof(short);
	}
	head.datasize = datasize_;
	ofstream fout("res.wav",ios::binary);
	
	fout.write(reinterpret_cast<char*>(&head),sizeof(head));
	for(int i=1;i<=n;i++)
	{
		//cout << start_sample[nums[i]] << ' ' << len_samples[nums[i]] << endl;
		fout.write(reinterpret_cast<char*>(&pdata[start_sample[nums[i]]]),sizeof(short)*len_samples[nums[i]]);	
		//cout << i << endl;
	}

    //! 用【语音拼接法】合成指定数字串的语音文件 -->

    // <1> 写入WAV文件的头结构：先计算语音数据长度，准备好WAV文件的头结构

    // <2> 依次写入数字串中各位数字对应的语音数据

    fout.close();

    delete[] pdata;

    return 0;
}