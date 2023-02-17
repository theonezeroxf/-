#include "dataread.h"
#include "WeSock_h.h"
QVector<Node> v;
QVector<Node> v2;
Node ns[7];
Node ms[15];
double average;
double mediu_shu;
int from_net;
int start_day;
DataRead::DataRead()
{

}
void DataRead::getData_std(){
    for(int i=0;i<7;i++){
        Node n;
        n.name="name";
        n.light=60;
        n.tem=20;
        n.voice=30;
        ns[i]=n;
    }
    for(int i=0;i<15;i++){
        Node n;
        n.name="test";
        n.light=60;
        n.tem=20;
        n.voice=30;
        ms[i]=n;
    }


}
bool DataRead::inputData_net(QString name){
    QTcpSocket *cfd=new QTcpSocket();

    Package p1,p2;
    p1.cmd='c';
    p1.day_start=start_day;
    QByteArray byteArr=name.toLatin1();

    strcpy(p1.name,byteArr.data());
    cfd->connectToHost(QHostAddress("192.168.43.115"),10086);

    //cfd->write((char*)&n);
    //cfd->write((char*)(&p1),sizeof(p1));
    cfd->write((char*)(&p1),sizeof(p1));

    //cfd->write((char*)n);
    cfd->waitForBytesWritten();
    cfd->waitForReadyRead();
    cfd->read((char*)(&p2),sizeof(p2));

    v.resize(7);
    v2.resize(15);
    for(int i=0;i<7;i++){
        v[i].tem=p2.n7[i].tem;
        v[i].voice=p2.n7[i].syin;
        v[i].light=p2.n7[i].light;

    }
    for(int i=0;i<15;i++){
        v2[i].tem=p2.n7[i].tem;
        v2[i].voice=p2.n7[i].syin;
        v2[i].light=p2.n7[i].light;
    }

    cfd->close();
    qDebug()<<p2.n7[0].id<<p2.n7[0].tem<<endl;




}
void DataRead::inputData(){
    for(int i=0;i<7;i++){
        Node n;
        n.name="name";
        n.light=60+i;
        n.voice=30+i;
        n.tem=20+i;
        v.push_back(n);
    }
    for(int i=0;i<15;i++){
        Node n;
        n.name="test";
        n.light=60+i;
        n.voice=30+i;
        n.tem=20+i;
        v2.push_back(n);
    }
}
