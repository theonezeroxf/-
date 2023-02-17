#ifndef DATAREAD_H
#define DATAREAD_H
#include<QVector>
#include<QString>
#include<QPlainTextEdit>
#include <QTcpSocket>
#include<QPushButton>
#include<QHostAddress>
#include<QLocalServer>
#include<QIODevice>
#include<QDebug>
#include<QByteArray>
typedef struct NODE{
    QString name;
    int tem;
    int voice;
    int light;
}Node;

typedef struct node{
    char id[30];
    int day;
    double tem;		//温度
    int syin;	//湿度
    int light;		//光照
}Node_net;



typedef struct package{	//发我时封装成这样
    char cmd;		//代表'c'代表查7天新数据，‘C’代表15天新数据（n7与n15都赋值）	‘i’代表插入一次数据（一天）
    char name[30];  //查询时使用，查询者姓名
    int day_start;	//0代表最新7天，其他代表从day_start开始的n7和n15;
    Node_net n7[7];	//‘7’时传7天数据
    int n7_len;	//n7中实际有效数据（有7条填7条，没7条填实际条数）
    Node_net n15[15];	//  ‘15’时传15天数据
    int n15_len;	//同n7_len
    Node_net data;	//插入时使用
}Package;


class DataRead
{
public:
    DataRead();
    static void getData_std();
    static void inputData();
    static bool inputData_net(QString name);

};
extern Node ns[7];
extern Node ms[15];
extern QVector<Node> v;
extern QVector<Node> v2;
extern int start_day;

extern double average;

extern double mediu_shu;

extern int from_net;

#endif // DATAREAD_H
