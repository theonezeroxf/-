#ifndef __WeSock__20220920__ZengCB_ChenK_Xf__
#define __WeSock__20220920__ZengCB_ChenK_Xf__

#include<string.h>
#include<stdio.h>

#define Badd 0x32         //标志位：插入行请求
#define Bplzall 0x33         //标志位：查询请求 
#define Bplzname 0x34        //标志位：由姓名查找
#define Bplzday 0x35        //标志位：由日期查找   
#define selfSQL 0x40        //标志位：客户端自己输入SQL语句，其存入Name中

typedef struct WePro{
    unsigned char cmd;
    char Name[100];
    int Day;
    int Slptime;
    int Wen;
    int Shen;
    int Guang;
}*wepro;

//#define Berr 0x35         //标志位：违规通知
//#define Bclos 0x36        //标志位：断开连接*/

static char Seccse[15]="Send secceed!";         //发送完毕通知

static char serverip[16]="172.168.0.122";
static char port[6]="10920";
/*
inttostr : 将一个数转换为字符串并存入p中
    @i:需要转换的数字
    @p:储存数字的指针
*/
void inttostr(const int i,char *p);

/*
strtoint : 将3位数字字符串转换为整型数字
    @p:储存数字的首地址
    返回追：转换后的数字
            若返回-1，表示字符串错误
*/
int strtoint(char *p);

/*
Package:对协议包进行封装
    @cmd:标志位（已宏定义）
    @Name用户名字
    @day:储存第几天的指针
    @slptime:储存睡眠时间的指针
    @wen；储存温度的指针
    @shen:储存声音的指针
    @guang:储存光照的指针
*/
//struct WePro Package(const unsigned char Cmd,char *name,int day,int slptime,int wen,int shen,int guang);

/*
Parse：对协议包进行解析
    @pro:数据包，需强制转换回struct WePro格式数组
    @name:用户名字
    @day:储存第几天的指针
    @slptime:储存睡眠时间的指针
    @wen；储存温度的指针
    @shen:储存声音的指针
    @guang:储存光照的指针
*/
unsigned char Parse(char *pro,char *name,int *day,int *slptime,int *wen,int *shen,int *guang);
#endif













/*
    通信协议规则:
        unsigned char ch[256];
            包头：ch[0]
                统一使用0x30   Bhead
            标志位:ch[1]
                包括：
                    插入数据库请求 0x32 Badd
                    查询数据库请求 0x33 Bplz
                    发送完毕通知   0x34 Bsec
                    违规通知       0x35 Berr
                    断开连接请求   0x36 Bclos
            协议包长度：ch[2]~ch[4]
                占3个字节，由函数inttostr得到
                解包时使用函数strtoint得到长度
                    （包头）1+（标志位）1+（包长度）3+（表名长度）3+（查询内容长度）3+（包尾）1=12
                    再加上数据位长度
            （数据部分：）
                表名长度：ch[5]~ch[7]
                    在请求插入、查询数据库时，需要将表名（dest）传入
                    则表名长度为strlen(dest),dest的'\0'不会写入数据包
                表名：ch[7]~ch[d]
                    表名dest
                查询内容长度：ch[d+1]~ch[d+3]
                    在请求查询数据库时，需要将查询内容传入
                查询内容：ch[d+4]~ch[strlen(ch)-1]
                    如 "NAME XIEFENG",则查找谢峰的一切数据并传回
                    或者"NAME XIEFENG,DAY 2"，则传回谢峰第二天的数据
                    或者”NAME XIEFENG,SLEEPTIME > 4",则传回谢峰睡觉超过4小时的日子里的数据
                    注：单词、符号、数据之间用空格间隔，逗号两端无需空格
                    字符串中'\0'不存入
            包尾: ch[strlen(ch)]
                统一使用0x31 Blast
            结束符: '\0'

#define Bhead 0x30        //包头
#define Blast 0x31        //包尾*/
